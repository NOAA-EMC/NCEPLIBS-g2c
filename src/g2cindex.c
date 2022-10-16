/** 
 * @file
  * @brief Write summary output to an index file, as is done by utility
 * grb2index.
 *
 * @author Ed Hartnett @date 10/12/22
 */
#include "grib2_int.h"
#include <stdarg.h>

/* /\** Global file information. *\/ */
/* extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1]; */

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
 * Read an index file.
 *
 * @param index_file The name that will be given to the index file. An
 * existing file will be overwritten.
 * @param g2cid Pointer that gets the g2cid for this file. Ignored if
 * NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 10/12/22
 */
int
g2c_read_index(char *index_file, int *g2cid)
{
    int my_g2cid = 0;
    FILE *f;
    size_t bytes_read;
    
    /* Check inputs. */
    if (!index_file)
	return G2C_EINVAL;
    
    LOG((1, "g2c_read_index index_file %s", index_file));

    /* Open the index file. */
    if (!(f = fopen(index_file, "r")))
	return G2C_EFILE;

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
	LOG((2, "line %s", line));	
	LOG((2, "skip %d total_len %d num_rec %d basename %s", skip, total_len, num_rec, basename));

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
		 "msglen %ld version %d discipline %d fieldnum %d\n",
		 reclen, msg, local, gds, pds, drs, bms, data, msglen,
		 version, discipline, fieldnum);

	    /* Read section 1. */
	    {
		G2C_MESSAGE_INFO_T *msgp;
		int ret;

		if (!(msgp = malloc(sizeof(G2C_MESSAGE_INFO_T))))
		    return G2C_ENOMEM;
		msgp->discipline = discipline;
		msgp->bytes_to_msg = msg;
		if ((ret = g2c_read_section1_metadata(f, 0, msgp)))
		    return ret;
		if ((ret = g2c_log_section1(msgp)))
		    return ret;
		free(msgp);
	    }

	    /* Move the file position to the start of the next index record. */
	    file_pos += reclen;
	}
    }

    /* Read the lines of data. */

    /* Close the index file. */
    fclose(f);

    /* Return file ID to caller. */
    if (g2cid)
	*g2cid = my_g2cid;

    return G2C_NOERROR;
}