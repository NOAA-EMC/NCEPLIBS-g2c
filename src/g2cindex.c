/**
 * @file
 * @brief Write summary output to an index file, as is done by utility
 * grb2index.
 *
 * @author Ed Hartnett @date 10/12/22
 */
#include "grib2_int.h"
#include <time.h>
#include <stdarg.h>

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/** Length of the two header lines at the top of the index file. */
#define G2C_INDEX_HEADER_LEN 81

/** Length of the basename in header record 2. */
#define G2C_INDEX_BASENAME_LEN 40

/** Length of bitmap section included in the index record. */
#define G2C_INDEX_BITMAP_BYTES 6

/** Length of beginning of index record. */
#define G2C_INDEX_FIXED_LEN 44

/** Use externally-defined mutex for thread-safety. */
EXTERN_MUTEX(m);

/**
 * Read or write the start of an index record.
 *
 * @param f FILE * to open index file.
 * @param rw_flag True if function should write, false if it should read.
 * @param reclen Pointer to reclen.
 * @param msg Pointer to msg.
 * @param local Pointer to local.
 * @param gds Pointer to gds.
 * @param pds Pointer to pds.
 * @param drs Pointer to drs.
 * @param bms Pointer to bms.
 * @param data Pointer to data.
 * @param msglen Pointer to msglen.
 * @param version Pointer to version.
 * @param discipline Pointer to discipline.
 * @param fieldnum Pointer to fieldnum, 0- based. (It is 1-based in
 * the index file.)
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EINVAL Invalid input.
 * - ::G2C_EFILE File I/O error.
 *
 * @author Ed Hartnett 10/26/22
 */
int
g2c_start_index_record(FILE *f, int rw_flag, int *reclen, int *msg, int *local, int *gds,
                       int *pds, int *drs, int *bms, int *data, size_t *msglen,
                       unsigned char *version, unsigned char *discipline, short *fieldnum)
{
    int int_be;
    short short_be;
    size_t size_t_be;
    short fieldnum1; /* This is for the 1-based fieldnum in the index file. */

    /* All pointers must be provided. */
    if (!f || !reclen || !msg || !local || !gds || !pds || !drs || !bms || !data
        || !msglen || !version || !discipline || !fieldnum)
        return G2C_EINVAL;

    /* When writing, set the fieldnum1 to be a 1-based index, just
     * like in Fortran. */
    if (rw_flag)
        fieldnum1 = *fieldnum + 1;

    /* Read or write the values at the beginning of each index
     * record. */
    FILE_BE_INT4P(f, rw_flag, reclen);
    FILE_BE_INT4P(f, rw_flag, msg);
    FILE_BE_INT4P(f, rw_flag, local);
    FILE_BE_INT4P(f, rw_flag, gds);
    FILE_BE_INT4P(f, rw_flag, pds);
    FILE_BE_INT4P(f, rw_flag, drs);
    FILE_BE_INT4P(f, rw_flag, bms);
    FILE_BE_INT4P(f, rw_flag, data);
    FILE_BE_INT8P(f, rw_flag, msglen);
    FILE_BE_INT1P(f, rw_flag, version);
    FILE_BE_INT1P(f, rw_flag, discipline);
    FILE_BE_INT2P(f, rw_flag, &fieldnum1);

    /* When reading, translate the 1-based fieldnum1 into the 0-based
     * fieldnum that C programmers will expect and love. */
    if (!rw_flag)
        *fieldnum = fieldnum1 - 1;

    return G2C_NOERROR;
}

/**
 * Given a pointer to a message, and a field number, return pointers
 * to all relevent section structs for that product.
 *
 * Each product is defined in a section 4, and has an associated
 * section 3, 5, 6, and 7.
 *
 * @param msg Pointer to a G2C_MESSAGE_INFO_T with information about
 * the message.
 * @param fieldnum The field number (first field in message is 0).
 * @param sec3 Pointer that gets a pointer to the G2C_SECTION_INFO_T
 * struct for the section 3 associated with this product.
 * @param sec4 Pointer that gets a pointer to the G2C_SECTION_INFO_T
 * struct for the section 4 associated with this product.
 * @param sec5 Pointer that gets a pointer to the G2C_SECTION_INFO_T
 * struct for the section 5 associated with this product.
 * @param sec6 Pointer that gets a pointer to the G2C_SECTION_INFO_T
 * struct for the section 6 associated with this product. NULL is
 * returned if there is no section 6.
 * @param sec7 Pointer that gets a pointer to the G2C_SECTION_INFO_T
 * struct for the section 7 associated with this product.
 *
 * @note This is an internal function and should not be called by users.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EINVAL Invalid input.
 * - ::G2C_ENOSECTION Section not found.
 *
 * @author Ed Hartnett @date 10/27/22
 */
int
g2c_get_prod_sections(G2C_MESSAGE_INFO_T *msg, int fieldnum, G2C_SECTION_INFO_T **sec3,
                      G2C_SECTION_INFO_T **sec4, G2C_SECTION_INFO_T **sec5,
                      G2C_SECTION_INFO_T **sec6, G2C_SECTION_INFO_T **sec7)
{
    G2C_SECTION_INFO_T *s3, *s4, *s5, *s6, *s7;

    /* Check inputs. */
    if (!msg || fieldnum < 0)
        return G2C_EINVAL;
    if (!sec3 || !sec4)
        return G2C_EINVAL;
    if (!sec5)
        return G2C_EINVAL;
    if (!sec6)
        return G2C_EINVAL;
    if (!sec7)
        return G2C_EINVAL;

    /* Find the product with matching fieldnum. */
    for (s4 = msg->sec; s4; s4 = s4->next)
    {
        G2C_SECTION4_INFO_T *s4info = s4->sec_info;
        if (s4->sec_num != 4)
            continue;
        if (s4info->field_num == fieldnum)
            break;
    }
    if (!s4)
        return G2C_ENOSECTION;

    /* Find the section 3, grid definition section, which is
     * associated with this product. */
    for (s3 = s4->prev; s3; s3 = s3->prev)
        if (s3->sec_num == 3)
            break;
    if (!s3)
        return G2C_ENOSECTION;

    /* Find the section 5, data representation section, which
     * is associated with this product. */
    for (s5 = s4->next; s5; s5 = s5->next)
        if (s5->sec_num == 5)
            break;
    if (!s5)
        return G2C_ENOSECTION;

    /* Find the section 6, the bit map section. There may not be
     * one. */
    for (s6 = s5->next; s6; s6 = s6->next)
    {
        if (s6->sec_num == 6)
            break;

        /* If we hit section 7, there's no bitmap. */
        if (s6->sec_num == 7)
        {
            s6 = NULL;
            break;
        }
    }

    /* Find the section 7, data section, which is associated with this
     * product. */
    for (s7 = s5->next; s7; s7 = s7->next)
        if (s7->sec_num == 7)
            break;
    if (!s7)
        return G2C_ENOSECTION;

    /* Return results to caller. */
    *sec3 = s3;
    *sec4 = s4;
    *sec5 = s5;
    *sec6 = s6;
    *sec7 = s7;

    return G2C_NOERROR;
}

/**
 * Create an index file from a GRIB2 file, just like those created by
 * the grb2index utility.
 *
 * The index file starts with two header records:
 * 1. 81-byte header with 'gb2ix1' in columns 42-47.
 * 2. 81-byte header with number of bytes to skip before index records,
 * total length in bytes of the index records, number of index records,
 * and grib file basename written in format ('ix1form:',3i10,2x,a40).
 *
 * Each following index record corresponds to a grib message
 * and has the internal format:
 * - byte 001 - 004 length of index record
 * - byte 005 - 008 bytes to skip in data file before grib message
 * - byte 009 - 012 bytes to skip in message before lus (local use) (0, if none).
 * - byte 013 - 016 bytes to skip in message before gds
 * - byte 017 - 020 bytes to skip in message before pds
 * - byte 021 - 024 bytes to skip in message before drs
 * - byte 025 - 028 bytes to skip in message before bms
 * - byte 029 - 032 bytes to skip in message before data section
 * - byte 033 - 040 bytes total in the message
 * - byte 041 - 041 grib version number (currently 2)
 * - byte 042 - 042 message discipline
 * - byte 043 - 044 field number within grib2 message (1-based)
 * - byte 045 -  ii identification section (ids)
 * - byte ii+1-  jj grid definition section (gds)
 * - byte jj+1-  kk product definition section (pds)
 * - byte kk+1-  ll the data representation section (drs)
 * - byte ll+1-ll+6 first 6 bytes of the bit map section (bms)
 *
 * @param g2cid File it for an open GRIB2 file, as returned by
 * g2c_open().
 * @param mode Mode flags. Set ::G2C_NOCLOBBER to avoid overwriting
 * and existing file.
 * @param index_file The name that will be given to the index file. An
 * existing file will be overwritten.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 10/12/22
 */
int
g2c_write_index(int g2cid, int mode, const char *index_file)
{
    FILE *f;
    char h1[G2C_INDEX_HEADER_LEN * 2 + 1]; /* need extra space to silence GNU warnings */
    char h2[G2C_INDEX_HEADER_LEN + 10];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    size_t items_written;
    char my_path[G2C_INDEX_BASENAME_LEN + 1];
    G2C_MESSAGE_INFO_T *msg;
    int total_index_size = 0; /* Does not include size of header records. */
    int reclen;
    int ret = G2C_NOERROR;

    /* Is this an open GRIB2 file? */
    if (g2cid < 0 || g2cid > G2C_MAX_FILES)
        return G2C_EBADID;
    if (!index_file)
        return G2C_EINVAL;

    LOG((1, "g2c_write_index g2cid %d mode %d index_file %s", g2cid, mode,
         index_file));

    /* If NOCLOBBER, check if file exists. */
    if (mode & G2C_NOCLOBBER)
    {
        FILE *f;
        if ((f = fopen(index_file, "r")))
        {
            fclose(f);
            return G2C_EFILE;
        }
    }

    /* Create the index file. */
    if (!(f = fopen(index_file, "wb+")))
        return G2C_EFILE;

    /* If using threading, lock the mutex. */
    MUTEX_LOCK(m);

    if (g2c_file[g2cid].g2cid != g2cid)
        ret = G2C_EBADID;

    if (!ret)
    {
        /* Create header 1. */
        sprintf(h1, "!GFHDR!  1   1   162 %4.4u-%2.2u-%2.2u %2.2u:%2.2u:%2.2u GB2IX1        hfe08           grb2index\n",
                (tm.tm_year + 1900), (tm.tm_mon + 1), tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

        /* Write header 1. */
        if ((items_written = fwrite(h1, G2C_INDEX_HEADER_LEN, 1, f)) != 1)
            ret = G2C_EFILE;
    }

    /* Find the total length of the index we are generating. */
    if (!ret)
    {
        for (msg = g2c_file[g2cid].msg; msg; msg = msg->next)
        {
            short fieldnum;
            
            /* Find information for each field in the message. */
            for (fieldnum = 0; fieldnum < msg->num_fields; fieldnum++)
            {
                G2C_SECTION_INFO_T *sec3, *sec4, *sec5, *sec6, *sec7;
                
                if ((ret = g2c_get_prod_sections(msg, fieldnum, &sec3, &sec4, &sec5, &sec6, &sec7)))
                    break;
                
                /* What will be the length of this index record? */
                reclen = G2C_INDEX_FIXED_LEN + msg->sec1_len + sec3->sec_len + sec4->sec_len +
                    sec5->sec_len + G2C_INDEX_BITMAP_BYTES;
                total_index_size += reclen;
                LOG((4, "fieldnum %d reclen %d total_index_size %d", fieldnum, reclen, total_index_size));
            } /* next product */

            /* If there was a problem, give up. */
            if (!ret)
                break;
        } /* next message */
    }

    /* Create header 2. */
    if (!ret)
    {
        strncpy(my_path, g2c_file[g2cid].path, G2C_INDEX_BASENAME_LEN);
        sprintf(h2, "IX1FORM:       162    %6d    %6ld  %s    \n", total_index_size,
                g2c_file[g2cid].num_messages, my_path);
        LOG((5, "header 2: %s", h2));
        
        /* Write header 2. */
        if ((items_written = fwrite(h2, G2C_INDEX_HEADER_LEN, 1, f)) != 1)
            ret = G2C_EFILE;
    }

    /* Write a record of index file for each message in the file. */
    if (!ret)
    {
        for (msg = g2c_file[g2cid].msg; msg; msg = msg->next)
        {
            short fieldnum;

            /* Find information for each field in the message. */
            for (fieldnum = 0; fieldnum < msg->num_fields; fieldnum++)
            {
                G2C_SECTION_INFO_T *sec3, *sec4, *sec5, *sec6, *sec7;
                int bytes_to_msg = (int)msg->bytes_to_msg;
                int bs3, bs4, bs5, bs6, bs7; /* bytes to each section, as ints. */
                int sec_num;
                int int_be;
                int ret;

                if ((ret = g2c_get_prod_sections(msg, fieldnum, &sec3, &sec4, &sec5, &sec6, &sec7)))
                    return ret;
                bs3 = (int)sec3->bytes_to_sec;
                bs4 = (int)sec4->bytes_to_sec;
                bs5 = (int)sec5->bytes_to_sec;
                bs6 = (int)sec6->bytes_to_sec;
                bs7 = (int)sec7->bytes_to_sec;

                /* What will be the length of this index record? */
                reclen = G2C_INDEX_FIXED_LEN + msg->sec1_len + sec3->sec_len + sec4->sec_len +
                    sec5->sec_len + G2C_INDEX_BITMAP_BYTES;
                LOG((4, "fieldnum %d reclen %d", fieldnum, reclen));

                /* Write the beginning of the index record. */
                if ((ret = g2c_start_index_record(f, G2C_FILE_WRITE, &reclen, &bytes_to_msg, &msg->bytes_to_local,
                                                  &bs3, &bs4, &bs5, &bs6, &bs7, &msg->bytes_in_msg, &msg->master_version,
                                                  &msg->discipline, &fieldnum)))
                    return ret;

                /* Write the section 1, identification section. */
                if ((ret = g2c_rw_section1_metadata(f, G2C_FILE_WRITE, msg)))
                    return ret;

                /* Write the section 3, grid definition section. */
                sec_num = 3;
                FILE_BE_INT4P(f, G2C_FILE_WRITE, &sec3->sec_len);
                FILE_BE_INT1P(f, G2C_FILE_WRITE, &sec_num);
                if ((ret = g2c_rw_section3_metadata(f, G2C_FILE_WRITE, sec3)))
                    return ret;

                /* Write the section 4, product definition section. */
                sec_num = 4;
                FILE_BE_INT4P(f, G2C_FILE_WRITE, &sec4->sec_len);
                FILE_BE_INT1P(f, G2C_FILE_WRITE, &sec_num);
                if ((ret = g2c_rw_section4_metadata(f, G2C_FILE_WRITE, sec4)))
                    return ret;

                /* Write the section 5, data representation section. */
                sec_num = 5;
                FILE_BE_INT4P(f, G2C_FILE_WRITE, &sec5->sec_len);
                FILE_BE_INT1P(f, G2C_FILE_WRITE, &sec_num);
                if ((ret = g2c_rw_section5_metadata(f, G2C_FILE_WRITE, sec5)))
                    return ret;

                /* Write the first 6 bytes of the bitmap section, if there
                 * is one. */
                if (sec6)
                {
                    unsigned char sample[G2C_INDEX_BITMAP_BYTES];
                    int b;

                    /* Read the first 6 bytes of the bitmap section. */
                    if (fseek(msg->file->f, msg->bytes_to_msg + sec6->bytes_to_sec, SEEK_SET))
                        return G2C_EFILE;
                    if ((fread(sample, ONE_BYTE, G2C_INDEX_BITMAP_BYTES, msg->file->f)) != G2C_INDEX_BITMAP_BYTES)
                        return G2C_EFILE;

                    /* Now write these bytes to the end of the index record. */
                    for (b = 0; b < G2C_INDEX_BITMAP_BYTES; b++)
                        FILE_BE_INT1P(f, G2C_FILE_WRITE, &sample[b]);
                }
            } /* next product */
        } /* next message */
    }

    /* If using threading, unlock the mutex. */
    MUTEX_UNLOCK(m);

    /* Close the index file. */
    if (fclose(f))
        return G2C_EFILE;

    return ret;
}

/**
 * Open a GRIB2 file with the help of an index file.
 *
 * The index file, generated by the grb2index utility, of the
 * g2c_write_index() function, contains the byte offsets for the
 * sections of each message in the GRIB2 file. When a GRIB2 file is
 * opened with an index file, the library does not have to scan the
 * file to locate all metadata.
 *
 * @param data_file The name of the data file to which the index applies.
 * @param index_file The name that will be given to the index file. An
 * existing file will be overwritten.
 * @param mode Open mode flags.
 * @param g2cid Pointer that gets the g2cid for this file. Ignored if
 * NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 10/12/22
 */
int
g2c_read_index(const char *data_file, const char *index_file, int mode,
               int *g2cid)
{
    FILE *f;
    size_t bytes_read;
    int ret;

    /* Check inputs. */
    if (!index_file || !data_file || !g2cid)
        return G2C_EINVAL;
    if (strlen(data_file) > G2C_MAX_NAME)
        return G2C_ENAMETOOLONG;

    LOG((1, "g2c_read_index index_file %s", index_file));

    /* Open the index file. */
    if (!(f = fopen(index_file, "rb")))
        return G2C_EFILE;

    /* If using threading, lock the mutex. */
    MUTEX_LOCK(m);

    /* Remember file metadata. */
    if ((ret = g2c_add_file(data_file, mode, g2cid)))
        return ret;

    /* Read the header. */
    {
        char line[G2C_INDEX_HEADER_LEN + 1];
        char str1[8], date_str[11], time_str[9];
        int i, j, k;
        int skip, total_len, num_rec;
        char basename[41];
        size_t file_pos = G2C_INDEX_HEADER_LEN * 2;
        int rec;

        /* Read the first line of header. */
        if ((bytes_read = fread(line, 1, 81, f)) != 81)
            return G2C_EFILE;
        line[G2C_INDEX_HEADER_LEN] = 0;
        sscanf(line, "%s %d %d %d %s %s GB2IX1", str1, &i, &j, &k, date_str, time_str);
        LOG((2, "str1 %s i %d j %d k %d date_str %s time_str %s", str1, i, j, k, date_str,
             time_str));

        /* Read the second line of header. */
        if ((bytes_read = fread(line, 1, 81, f)) != 81)
            return G2C_EFILE;
        line[G2C_INDEX_HEADER_LEN] = 0;
        sscanf(line, "IX1FORM: %d %d %d %s", &skip, &total_len, &num_rec, basename);
        LOG((2, "skip %d total_len %d num_rec %d basename %s", skip, total_len, num_rec, basename));

        /* Read each index record. */
        for (rec = 0; rec < num_rec; rec++)
        {
            int int_be;
            int reclen, msg, local, gds, pds, drs, bms, data;
            size_t msglen;
            unsigned char version, discipline;
            short fieldnum;
            int ret;

            /* Move to beginning of index record. */
            if (fseek(f, file_pos, SEEK_SET))
                return G2C_EFILE;

            /* Read the index record. */
            LOG((4, "reading index record at file position %ld", ftell(f)));
            if ((ret = g2c_start_index_record(f, G2C_FILE_READ, &reclen, &msg, &local, &gds, &pds,
                                              &drs, &bms, &data, &msglen, &version, &discipline, &fieldnum)))
                return ret;

            LOG((3, "reclen %d msg %d local %d gds %d pds %d drs %d bms %d data %d "
                 "msglen %ld version %d discipline %d fieldnum %d",
                 reclen, msg, local, gds, pds, drs, bms, data, msglen,
                 version, discipline, fieldnum));
            /* printf("reclen %d msg %d local %d gds %d pds %d drs %d bms %d data %d " */
            /*      "msglen %ld version %d discipline %d fieldnum %d", */
            /*      reclen, msg, local, gds, pds, drs, bms, data, msglen, */
            /*      version, discipline, fieldnum); */

            /* Read ingest the metadata for sections 3, 4, and 5 from
             * the index record. */
            {
                int sec_len;
                char sec_num;
                int s;
                G2C_MESSAGE_INFO_T *msgp;
                int sec_id = 0;
                int ret;

                /* Allocate storage for message. */
                if ((ret = add_msg(&g2c_file[*g2cid], rec, msg, msglen, 0, &msgp)))
                    return ret;
                msgp->discipline = discipline;
                msgp->bytes_to_local = local;
                msgp->bytes_to_bms = bms;
                msgp->bytes_to_data = data;
                msgp->master_version = version;

                /* Read section 1. */
                if ((ret = g2c_rw_section1_metadata(f, G2C_FILE_READ, msgp)))
                    return ret;
                if ((ret = g2c_log_section1(msgp)))
                    return ret;

                LOG((4, "reading section info at file position %ld", ftell(f)));

                /* Add a new section to our list of sections. */
                for (s = 3; s < 8; s++)
                {
                    size_t bytes_to_sec = gds; /* Correct value for section 3. */

                    /* For sections 3, 4, 5, read the section length
                     * and number from the index record. */
                    if (s < 6)
                    {
                        FILE_BE_INT4P(f, G2C_FILE_READ, &sec_len);
                        FILE_BE_INT1P(f, G2C_FILE_READ, &sec_num);
                    }
                    else
                    {
                        /* For section 7, the length of the section is
                         * not in the index file, but is needed for
                         * data read operations. So we will use the
                         * open data file and get the length of this
                         * section. */
                        if (fseek(g2c_file[*g2cid].f, msgp->bytes_to_msg + data, SEEK_SET))
                            return G2C_EFILE;
                        FILE_BE_INT4P(g2c_file[*g2cid].f, G2C_FILE_READ, &sec_len);
                        FILE_BE_INT1P(g2c_file[*g2cid].f, G2C_FILE_READ, &sec_num);
                        LOG((4, "read section 7 info from data file. sec_len %d sec_num %d",
                             sec_len, sec_num));
                    }

                    /* Select the value from the index record which is
                     * the number of bytes to section s. */
                    if (s == 4)
                        bytes_to_sec = pds;
                    else if (s == 5)
                        bytes_to_sec = drs;
                    else if (s == 6)
                        bytes_to_sec = bms;
                    else if (s == 7)
                        bytes_to_sec = data;

                    /* Check some stuff. */
                    if (s < 6 && sec_num != s)
                        return G2C_EBADSECTION;
                    if (sec_num == 4)
                        if (fieldnum < 0) /* to silence warning */
                            return G2C_EBADSECTION;

                    /* Read the section info from the index file,
                     * using the same functions that read it from the
                     * GRIB2 data file. */
                    if ((ret = add_section(f, msgp, sec_id++, sec_len, bytes_to_sec, s)))
                        return ret;
                }
            }

            /* Move the file position to the start of the next index record. */
            file_pos += reclen;
        }
    }

    /* If using threading, unlock the mutex. */
    MUTEX_UNLOCK(m);

    /* Close the index file. */
    fclose(f);

    return G2C_NOERROR;
}
