/** 
 * @file
  * @brief Write summary output to an index file, as is done by utility
 * grb2index.
 *
 * @author Ed Hartnett @date 10/12/22
 */
#include "grib2_int.h"
#include <stdarg.h>

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/** Length of the two header lines at the top of the index file. */
#define G2C_INDEX_HEADER_LEN 81

/**
 * Create an index file from a GRIB2 file.
 *
 * @param g2cid File it for an open GRIB2 file, as returned by
 * g2c_open().
 * @param index_file The name that will be given to the index file. An
 * existing file will be overwritten.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 10/12/22
 */
int
g2c_write_index(int g2cid, char *index_file)
{
    
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
g2c_read_index(char *data_file, char *index_file, int mode, int *g2cid)
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
	    printf("reclen %d msg %d local %d gds %d pds %d drs %d bms %d data %d "
	         "msglen %ld version %d discipline %d fieldnum %d",
	         reclen, msg, local, gds, pds, drs, bms, data, msglen,
	         version, discipline, fieldnum);

            /* Read ingest the metadata for sections 3, 4, and 5 from
             * the index record. */
	    {
                int sec_len;
                char sec_num;
                int s;
                G2C_MESSAGE_INFO_T *msgp;
		int ret;

                /* Allocate storage for message. */
                if ((ret = add_msg(&g2c_file[*g2cid], rec, msg, msglen, 0, &msgp)))
                    return ret;
		msgp->discipline = discipline;
                msgp->bytes_to_local = local;
                msgp->bytes_to_bms = bms;
                msgp->bytes_to_data = data;
                                
                /* Read section 1. */
                LOG((3, "howdy2"));
		if ((ret = g2c_read_section1_metadata(f, 0, msgp)))
		    return ret;
		if ((ret = g2c_log_section1(msgp)))
		    return ret;
                LOG((3, "howdy3"));

                LOG((4, "reading section info at file position %ld", ftell(f)));

                /* Add a new section to our list of sections. */
                for (s = 3; s < 6; s++)
                {
                    size_t bytes_to_sec = gds;
                    int sec_id = 0;
                    LOG((3, "howdy4 s %d sec_num %d", s, sec_num));

                    /* Read the section length and number from the index record. */
                    LOG((3, "howdy4 s %d sec_num %d", s, sec_num));
                    READ_BE_INT4(f, sec_len);
                    READ_BE_INT1(f, sec_num);
                    LOG((3, "howdy5"));

                    /* Select the value from the index record which is
                     * the number of bytes to section s. */
                    LOG((3, "howdy5 sec_num %d", sec_num));
                    if (sec_num == 4)
                        bytes_to_sec = pds;
                    else if (sec_num == 5)
                        bytes_to_sec = drs;
                    LOG((3, "howdy6"));

                    /* Check some stuff. */
                    if (sec_num != s)
                        return G2C_EBADSECTION;
                    if (sec_num == 4)
                        if (fieldnum < 0) /* to silence warning */
                            return G2C_EBADSECTION;

                    /* Read the section info from the index file,
                     * using the same functions that read it from the
                     * GRIB2 data file. */
                    if ((ret = add_section(f, msgp, sec_id++, sec_len, bytes_to_sec, sec_num)))
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
