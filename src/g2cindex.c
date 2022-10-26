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
 * - byte 043 - 044 field number within grib2 message
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
    
    /* Is this an open GRIB2 file? */
    if (g2cid < 0 || g2cid > G2C_MAX_FILES || g2c_file[g2cid].g2cid != g2cid)
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

    /* Create header 1. */
    sprintf(h1, "!GFHDR!  1   1   162 %4.4u-%2.2u-%2.2u %2.2u:%2.2u:%2.2u GB2IX1        hfe08           grb2index",
            (tm.tm_year + 1900), (tm.tm_mon + 1), tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    /* Write header 1. */
    if ((items_written = fwrite(h1, G2C_INDEX_HEADER_LEN, 1, f)) != 1)
        return G2C_EFILE;

    /* Create header 2. Awkwardly it wants to know the total length of
     * all index records, and we don't know that yet. */
    strncpy(my_path, g2c_file[g2cid].path, G2C_INDEX_BASENAME_LEN);
    sprintf(h2, "IX1FORM:       162    %6d    %6ld  %s    ", 0,
            g2c_file[g2cid].num_messages, my_path);

    /* Write header 2. */
    if ((items_written = fwrite(h2, G2C_INDEX_HEADER_LEN, 1, f)) != 1)
        return G2C_EFILE;

    /* Close the index file. */
    if (fclose(f))
        return G2C_EFILE;

    return G2C_NOERROR;
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
	    short short_be;
	    size_t size_t_be;
	    int reclen, msg, local, gds, pds, drs, bms, data;
	    size_t msglen;
	    unsigned char version, discipline;
	    short fieldnum;

	    /* Move to beginning of index record. */
	    if (fseek(f, file_pos, SEEK_SET))
		return G2C_EFILE;

	    /* Read the index record. */
            LOG((4, "reading index record at file position %ld", ftell(f)));
	    READ_BE_INT4(f, reclen);
	    READ_BE_INT4(f, msg);
	    READ_BE_INT4(f, local);
	    READ_BE_INT4(f, gds);
	    READ_BE_INT4(f, pds);
	    READ_BE_INT4(f, drs);
	    READ_BE_INT4(f, bms);
	    READ_BE_INT4(f, data);
	    READ_BE_INT8(f, msglen);
	    READ_BE_INT1(f, version);
	    READ_BE_INT1(f, discipline);
	    READ_BE_INT2(f, fieldnum);

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
                                
                /* Read section 1. */
		if ((ret = g2c_read_section1_metadata(f, 0, msgp)))
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
                        READ_BE_INT4(f, sec_len);
                        READ_BE_INT1(f, sec_num);
                    }
                    else
                    {
                        /* For section 7, the length of the section is
                         * not in the index file, but is needed for
                         * data read operations. So we will open the
                         * data file and get the length of this
                         * section. */
                        if (fseek(g2c_file[*g2cid].f, msgp->bytes_to_msg + data, SEEK_SET))
                            return G2C_EFILE;
                        READ_BE_INT4(g2c_file[*g2cid].f, sec_len);
                        READ_BE_INT1(g2c_file[*g2cid].f, sec_num);
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

    /* Close the index file. */
    fclose(f);

    return G2C_NOERROR;
}
