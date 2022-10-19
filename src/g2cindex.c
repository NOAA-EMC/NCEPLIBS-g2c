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
 * Read Section 1.
 *
 * @param f Pointer to open file.
 * @param skip Skip this many bytes to get to section 0.
 * @param msg Pointer to G2C_MESSAGE_INFO_T which will be populated
 * with the values of section 0.
 *
 * @return
 * -G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 10/16/22
 */
int
g2c_read_section1_metadata_2(FILE *f, size_t skip, G2C_MESSAGE_INFO_T *msg)
{
    int int_be;
    short short_be;
    char sec_num;

    /* Skip to section 1. */
    if (fseek(f, skip, SEEK_CUR))
        return G2C_EFILE;

    /* Read the section. */
    READ_BE_INT4(f, msg->sec1_len);
    READ_BE_INT1(f, sec_num);
    /* if (sec_num != 1) */
    /*     return G2C_ENOSECTION; */
    READ_BE_INT2(f, msg->center);
    /* READ_BE_INT2(f, msg->subcenter); */
    /* READ_BE_INT1(f, msg->master_version); */
    /* READ_BE_INT1(f, msg->local_version); */
    /* READ_BE_INT1(f, msg->sig_ref_time); */
    /* READ_BE_INT2(f, msg->year); */
    /* READ_BE_INT1(f, msg->month); */
    /* READ_BE_INT1(f, msg->day); */
    /* READ_BE_INT1(f, msg->hour); */
    /* READ_BE_INT1(f, msg->minute); */
    /* READ_BE_INT1(f, msg->second); */
    /* READ_BE_INT1(f, msg->status); */
    /* READ_BE_INT1(f, msg->type); */

    /* /\* Section 1 may contain optional numbers at the end of the */
    /*  * section. The sec1_len tells us if there are extra values. If */
    /*  * so, skip them. *\/ */
    /* if (msg->sec1_len > G2C_SECTION1_BYTES) */
    /*     fseek(f, msg->sec1_len - G2C_SECTION1_BYTES, SEEK_CUR); */

    return G2C_NOERROR;
}

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

	    {
		G2C_MESSAGE_INFO_T *msgp;
		int ret;

		if (!(msgp = malloc(sizeof(G2C_MESSAGE_INFO_T))))
		    return G2C_ENOMEM;
		msgp->discipline = discipline;
		msgp->bytes_to_msg = msg;
                
                /* Read section 1. */
		if ((ret = g2c_read_section1_metadata_2(f, 0, msgp)))
		    return ret;
		/* if ((ret = g2c_log_section1(msgp))) */
		/*     return ret; */

                /* Read section 3 */
		/* if ((ret = g2c_read_section3_metadata(f, 0, msgp))) */
		/*     return ret; */
		/* if ((ret = g2c_log_section1(msgp))) */
		/*     return ret; */

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
