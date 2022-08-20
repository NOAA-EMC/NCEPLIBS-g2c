/** 
 * @file
 * @brief File functions for the g2c library.
 * @author Ed Hartnett @date Aug 16, 2022
 */

#include "grib2_int.h"

/** This is the information about each open file. */
typedef struct g2c_file_info_t
{
    int g2cid;
    char path[G2C_MAX_NAME + 1];
    FILE *f;
} G2C_FILE_INFO;

/** Global file information. */
G2C_FILE_INFO g2c_file[G2C_MAX_FILES + 1];

/** Next g2cid file ID - used when opening or creating a file. */
int g2c_next_g2cid = 1;

/** Find a minimum. */
#define MIN(a,b) ((a) < (b) ? (a) : (b))

/** Default size of read-buffer. */
#define READ_BUF_SIZE 4092

/** Search a file for the next GRIB1 or GRIB2 message.
 *
 * A grib message is identified by its indicator section,
 * i.e. an 8-byte sequence with 'GRIB' in bytes 1-4 and a '1' or '2'
 * in byte 8. If found, the length of the message is decoded from
 * bytes 5-7. The search is done over a given section of the file. The
 * search is terminated if an eof or i/o error is encountered.
 *
 * @param g2cid ID of the opened grib file, returned by g2c_open().
 * @param skip_bytes Number of bytes to skip before search.
 * @param max_bytes Maximum number of bytes to search.
 * @param bytes_to_msg Pointer that gets the number of bytes to skip
 * before message.
 * @param bytes_in_msg Pointer that gets the number of bytes in
 * message (or 0 if no message found)
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EBADID g2cid not found.
 * - ::G2C_EFILE File error.
 * - ::G2C_EINVAL Invalid input.
 *
 * @author Ed Hartnett @date 2022-08-19
 */
int
g2c_find_msg2(int g2cid, size_t skip_bytes, size_t max_bytes, size_t *bytes_to_msg,
	      size_t *bytes_in_msg)
{
    size_t bytes_to_read = MIN(READ_BUF_SIZE, max_bytes);
    size_t bytes_read;
    unsigned char *buf;
    int grib_version;
    int eof = 0;
    int msg_found = 0;
    size_t num_blocks;
    size_t ftell_pos;
    int i;
    int ret = G2C_NOERROR;

    /* Check inputs. */
    if (!bytes_to_msg || !bytes_in_msg)
	return G2C_EINVAL;
    
    /* Find the open file struct. */
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;
    
    /* Skip some bytes if desired. */
    if (fseek(g2c_file[g2cid].f, (off_t)skip_bytes, SEEK_SET))
	return G2C_ERROR;

    /* Allocate storage to read into. */
    if (!(buf = calloc(bytes_to_read, sizeof(char))))
	return G2C_ENOMEM;

    for (num_blocks = 0; !eof; num_blocks++)
    {	
	/* Read some bytes. If we don't get the number expected, either a
	 * read error occured, or we reached the end of file. */
	if ((ftell_pos = ftell(g2c_file[g2cid].f)) == -1)
	    return G2C_EFILE;
	LOG((3, "before read ftell() is %ld (0x%x) reading %ld bytes", ftell_pos,
	     ftell_pos, bytes_to_read));
	if ((bytes_read = fread(buf, 1, bytes_to_read, g2c_file[g2cid].f)) != bytes_to_read)
	{
	    if (ferror(g2c_file[g2cid].f))
		ret = G2C_EFILE;
	    eof++;
	}

	/* Scan for 'GRIB2' in the bytes we have read. */
	if (!ret)
	{
	    for (i = 0; i < bytes_read; i++)
	    {
#ifdef LOGGING
		/* if (i < 10) LOG((3, "buf[%ld] = %2.2x", i, buf[i])); */
#endif
		/* Find the beginning of a GRIB message. */
		if (buf[i] == 'G' && i < bytes_read - G2C_MAGIC_HEADER_LEN
		    && buf[i + 1] == 'R' && buf[i + 2] == 'I' && buf[i + 3] == 'B')
		{
		    msg_found++;
		    *bytes_to_msg = ftell_pos + i;
		    grib_version = buf[i + 7];
		    LOG((3, "bytes_to_msg %ld grib_version %d", *bytes_to_msg, grib_version));
		    if (grib_version != 1 && grib_version != 2)
			return G2C_EMSG;
		}

		/* Find the end of a GRIB message. And then we're done. */
		if (msg_found && buf[i] == '7' && i < bytes_read - G2C_MAGIC_HEADER_LEN
		    && buf[i + 1] == '7' && buf[i + 2] == '7' && buf[i + 3] == '7')
		{
		    msg_found--;
		    *bytes_in_msg = ftell_pos + i - *bytes_to_msg + 4;
		    LOG((3, "bytes_in_msg %ld", *bytes_in_msg));
		    return G2C_NOERROR;
		}
	    }
	}

	/* Back up 8 bytes in case the "GRIB" magic header occurred
	 * within the last 8 bytes of the previous read. */
	if (fseek(g2c_file[g2cid].f, (off_t)(ftell(g2c_file[g2cid].f) - G2C_MAGIC_HEADER_LEN),
		  SEEK_SET))
	    return G2C_ERROR;
    } /* end while not EOF */

    /* Free storage. */
    free(buf);
    
    return ret;
}

/** Search a file for the next GRIB1 or GRIB2 message.
 *
 * A grib message is identified by its indicator section,
 * i.e. an 8-byte sequence with 'GRIB' in bytes 1-4 and a '1' or '2'
 * in byte 8. If found, the length of the message is decoded from
 * bytes 5-7. The search is done over a given section of the file. The
 * search is terminated if an eof or i/o error is encountered.
 *
 * @param g2cid ID of the opened grib file, returned by g2c_open().
 * @param skip_bytes Number of bytes to skip before search.
 * @param max_bytes Maximum number of bytes to search.
 * @param bytes_to_msg Pointer that gets the number of bytes to skip
 * before message.
 * @param bytes_in_msg Pointer that gets the number of bytes in
 * message (or 0 if no message found)
 * @param cbuf Pointer that gets allocation of memory, into which the
 * message is copied. This memory must be freed by the caller.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EBADID g2cid not found.
 * - ::G2C_EFILE File error.
 * - ::G2C_EINVAL Invalid input.
 * - ::G2C_ENOMEM Out of memory.
 *
 * @author Ed Hartnett @date 2022-08-20
 */
int
g2c_get_msg(int g2cid, size_t skip_bytes, size_t max_bytes, size_t *bytes_to_msg,
	    size_t *bytes_in_msg, unsigned char **cbuf)
{
    g2int bytes_to_msg_g, bytes_in_msg_g;
    size_t bytes_read;
    int ret = G2C_NOERROR;

    /* Check inputs. */
    if (!bytes_to_msg || !bytes_in_msg)
	return G2C_EINVAL;
    
    /* Find the open file struct. */
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    /* Find the start and length of the GRIB message. */
    seekgb(g2c_file[g2cid].f, (g2int)skip_bytes, (g2int)max_bytes, &bytes_to_msg_g,
	   &bytes_in_msg_g);
    *bytes_to_msg = bytes_to_msg_g;
    *bytes_in_msg = bytes_in_msg_g;

    /* Allocate storage for the GRIB message. */
    if (!(*cbuf = malloc(bytes_in_msg_g)))
	return G2C_ENOMEM;

    /* Read the message from the file into the buffer. */
    if ((bytes_read = fread(*cbuf, 1, bytes_in_msg_g, g2c_file[g2cid].f)) != bytes_in_msg_g)
	return G2C_EFILE;
    
    return ret;
}

/** Find a g2cid to use for a newly opened or created file.
 *
 * @param g2cid Pointer that gets the next available g2cid.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EINVAL - Invalid input.
 * - ::G2C_ETOOMANYFILES - Trying to open too many files at the same time.
 * '
 * @author Ed Hartnett 8/18/22
 */
static int
find_available_g2cid(int *g2cid)
{
    int i;
    
    /* Check input. */
    if (!g2cid)
	return G2C_EINVAL;

    /* Find a new g2cid. */
    for (i = 0; i < G2C_MAX_FILES + 1; i++)
    {
	int id = (i + g2c_next_g2cid) % (G2C_MAX_FILES + 1);

	/* Skip id 0. */
	if (!id)
	    continue;
	
	/* Is this ID available? If so, we're done. */
	if (!g2c_file[id].g2cid)
	{
	    *g2cid = id;
	    g2c_next_g2cid = id + 1;
	    return G2C_NOERROR;
	}
    }

    /* If we couldn't find one, they are all open. */
    return G2C_ETOOMANYFILES;
}

/** Open an existing GRIB2 file.
 *
 * @param path Path of the file.
 * @param mode Open mode flags.
 * @param g2cid Pointer that gets an indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EINVAL - Invalid input.
 * - ::G2C_ETOOMANYFILES - Trying to open too many files at the same time.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_open(const char *path, int mode, int *g2cid)
{
    int my_g2cid;
    int ret;

    /* Check inputs. */
    if (strlen(path) > G2C_MAX_NAME)
	return G2C_ENAMETOOLONG;
    if (!g2cid)
	return G2C_EINVAL;

    LOG((1, "g2c_open path %s mode %d", path, mode));

    /* Find a file ID. */
    if ((ret = find_available_g2cid(&my_g2cid)))
	return ret;

    /* Open the file. */
    if (!(g2c_file[my_g2cid].f = fopen(path, (mode & G2C_WRITE ? "rb+" : "rb"))))
	return G2C_EFILE;

    /* Read the metadata. */

    /* Copy the path. */
    strncpy(g2c_file[my_g2cid].path, path, G2C_MAX_NAME);

    /* Remember the id. */
    g2c_file[my_g2cid].g2cid = my_g2cid;
    
    /* Pass id back to user. */
    *g2cid = my_g2cid;
    
    return G2C_NOERROR;
}

/** Create a new GRIB2 file.
 *
 * @param path Path of the file.
 * @param cmode Open mode flags.
 * @param g2cid Pointer that gets an indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EFILE - File exsists and NOCLOBBER, or error opening file.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_create(const char *path, int cmode, int *g2cid)
{
    int my_g2cid;
    int ret;
    
    /* Check inputs. */
    if (strlen(path) > G2C_MAX_NAME)
	return G2C_ENAMETOOLONG;
    if (!g2cid)
	return G2C_EINVAL;

    LOG((1, "g2c_create path %s cmode %d", path, cmode));

    /* If NOCLOBBER, check if file exists. */
    if (cmode & G2C_NOCLOBBER)
    {
	FILE *f;
	if ((f = fopen(path, "r")))
	{
	    fclose(f);
	    return G2C_EFILE;
	}
    }

    /* Find a file ID. */
    if ((ret = find_available_g2cid(&my_g2cid)))
	return ret;

    /* Create the file. */
    if (!(g2c_file[my_g2cid].f = fopen(path, "w+")))
	return G2C_EFILE;

    /* Read the metadata. */

    /* Copy the path. */
    strncpy(g2c_file[my_g2cid].path, path, G2C_MAX_NAME);

    /* Remember the id. */
    g2c_file[my_g2cid].g2cid = my_g2cid;

    /* Pass id back to user. */
    *g2cid = my_g2cid;
    
    return G2C_NOERROR;
}

/** Close a GRIB2 file, freeing resources.
 *
 * @param g2cid Indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_close(int g2cid)
{
    /* Check input. */
    if (g2cid > G2C_MAX_FILES)
	return G2C_EBADID;
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    LOG((1, "g2c_close %d", g2cid));

    /* Close the file. */
    fclose(g2c_file[g2cid].f);

    /* Reset the file data. */
    g2c_file[g2cid].path[0] = 0;
    g2c_file[g2cid].g2cid = 0;
    g2c_file[g2cid].f = NULL;
    
    return G2C_NOERROR;
}


