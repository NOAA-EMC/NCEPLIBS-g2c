/** 
 * @file
 * @brief File functions for the g2c library.
 * @author Ed Hartnett @date Aug 16, 2022
 */

#include "grib2_int.h"

/** Global file information. */
G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

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
    int done = 0;
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

    for (num_blocks = 0; !eof && !done; num_blocks++)
    {	
	/* Read some bytes. If we don't get the number expected, either a
	 * read error occured, or we reached the end of file. */
	if ((ftell_pos = ftell(g2c_file[g2cid].f)) == -1)
	    return G2C_EFILE;
	LOG((4, "before read ftell() is %ld (0x%x) reading %ld bytes", ftell_pos,
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
		    {
			ret = G2C_EMSG;
			done++;
			break;
		    }
		}

		/* Find the end of a GRIB message. And then we're done. */
		if (msg_found && buf[i] == '7' && i < bytes_read - G2C_MAGIC_HEADER_LEN
		    && buf[i + 1] == '7' && buf[i + 2] == '7' && buf[i + 3] == '7')
		{
		    msg_found--;
		    *bytes_in_msg = ftell_pos + i - *bytes_to_msg + 4;
		    LOG((3, "bytes_in_msg %ld", *bytes_in_msg));
		    ret = G2C_NOERROR;
		    done++;
		    break;
		}
	    }
	}

	/* Back up 8 bytes in case the "GRIB" magic header occurred
	 * within the last 8 bytes of the previous read. */
	if (!done)
	    if (fseek(g2c_file[g2cid].f, (off_t)(ftell(g2c_file[g2cid].f) - G2C_MAGIC_HEADER_LEN),
		      SEEK_SET))
		return G2C_ERROR;
    }

    /* Free storage. */
    free(buf);
    
    return ret;
}

/** Search a file for the next GRIB1 or GRIB2 message, and read it,
 * allocating space in memory to hold the message.
 *
 * A grib message is identified by its indicator section,
 * i.e. an 8-byte sequence with 'GRIB' in bytes 1-4 and a '1' or '2'
 * in byte 8. If found, the length of the message is decoded from
 * bytes 5-7. The search is done over a given section of the file. The
 * search is terminated if an EOF or I/O error is encountered.
 *
 * @param g2cid ID of the opened grib file, returned by g2c_open().
 * @param skip_bytes The number of bytes to skip before search.
 * @param max_bytes The maximum number of bytes to search. Must be at
 * least 16.
 * @param bytes_to_msg A pointer that gets the number of bytes to skip
 * before message.
 * @param bytes_in_msg A pointer that gets the number of bytes in
 * message (or 0 if no message found)
 * @param cbuf A pointer that gets allocation of memory, into which the
 * message is copied. This memory must be freed by the caller.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EBADID g2cid not found.
 * - ::G2C_EFILE File error.
 * - ::G2C_EINVAL Invalid input.
 * - ::G2C_ENOMEM Out of memory.
 * - ::G2C_ENOMSG No GRIB message found.
 *
 * @author Ed Hartnett @date 2022-08-20
 */
int
g2c_get_msg(int g2cid, size_t skip_bytes, size_t max_bytes, size_t *bytes_to_msg,
	    size_t *bytes_in_msg, unsigned char **cbuf)
{
    size_t bytes_read;
    int ret = G2C_NOERROR;

    /* Check inputs. */
    if (!bytes_to_msg || !bytes_in_msg || !cbuf || max_bytes < G2C_MIN_MAX_BYTES)
	return G2C_EINVAL;

    LOG((2, "g2c_get_msg g2cid %d skip_bytes %ld max_bytes %ld", g2cid, skip_bytes,
	 max_bytes));
    
    /* Find the open file struct. */
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    /* Find the start and length of the GRIB message. */
    /* if ((ret = g2c_find_msg2(g2cid, skip_bytes, max_bytes, bytes_to_msg, */
    /* 			     bytes_in_msg))) */
    /* 	return ret; */
    {
	g2int bytes_to_msg_g, bytes_in_msg_g;
	seekgb(g2c_file[g2cid].f, (g2int)skip_bytes, (g2int)max_bytes, &bytes_to_msg_g,
		   &bytes_in_msg_g);
	*bytes_to_msg = bytes_to_msg_g;
	*bytes_in_msg = bytes_in_msg_g;
    }
    LOG((3, "*bytes_to_msg %ld *bytes_in_msg %ld", *bytes_to_msg, *bytes_in_msg));

    /* If no message was found, return an error. */
    if (*bytes_in_msg == 0)
	return G2C_ENOMSG;

    /* Allocate storage for the GRIB message. */
    if (!(*cbuf = malloc(*bytes_in_msg)))
	return G2C_ENOMEM;

    /* Position file at start of GRIB message. */
    if (fseek(g2c_file[g2cid].f, (off_t)*bytes_to_msg, SEEK_SET))
    {
#ifdef LOGGING
	int my_errno = errno;
	LOG((0, "fseek error %s", strerror(my_errno)));
#endif
	return G2C_ERROR;
    }

    /* Read the message from the file into the buffer. */
    if ((bytes_read = fread(*cbuf, 1, *bytes_in_msg, g2c_file[g2cid].f)) != *bytes_in_msg)
	return G2C_EFILE;

#ifdef LOGGING
    {
	int i;
	for (i = 0; i < 10; i++)
	    LOG((4, "cbuf[%d] = %2x", i, (*cbuf)[i]));
    }
#endif

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

/* Read metadata from a GRIB2 file being opened with g2c_open().
 *
 * @param g2cid The indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EBADID g2cid not found.
 * - ::G2C_EFILE File error.
 * - ::G2C_EINVAL Invalid input.
 * - ::G2C_ENOMEM Out of memory.
 * - ::G2C_ENOMSG No GRIB message found.
 *
 * @author Ed Hartnett @date Aug 22, 2022
 */
/* static int */
/* read_metadata(int g2cid) */
/* { */
/*     size_t msg_num; */
/*     size_t file_pos = 0; */
/*     int ret = G2C_NOERROR; */

/*     /\* Find the open file struct. *\/ */
/*     if (g2c_file[g2cid].g2cid != g2cid) */
/* 	return G2C_EBADID; */

/*     LOG((2, "read_metadata g2cid %d", g2cid)); */

/*     /\* Read each message in the file. *\/ */
/*     for (msg_num = 0; !ret; msg_num++) */
/*     { */
/* 	size_t bytes_to_msg, bytes_in_msg; */
/* 	unsigned char *cbuf = NULL; */

/* 	/\* Read the message, allocating memory. *\/ */
/* 	ret = g2c_get_msg(g2cid, file_pos, READ_BUF_SIZE, &bytes_to_msg, &bytes_in_msg, &cbuf); */
/* 	LOG((3, "msg_num %d bytes_to_msg %ld bytes_in_msg %ld", msg_num, bytes_to_msg, */
/* 	     bytes_in_msg)); */

/* 	/\* Learn about this message. *\/ */
/* 	if (!ret) */
/* 	{ */
/* 	    g2int listsec0[3], listsec1[13], numfields, numlocal; */
/* 	    /\* g2int *igds, *igdstmpl, mapgridlen, *ideflist, idefnum; *\/ */
/* 	    /\* g2int iofst = 128; *\/ */
/* 	    int i; */
	    
/* 	    /\* Set some message info. *\/ */
/* 	    g2c_file[g2cid].num_messages++; */
/* 	    g2c_file[g2cid].msg[msg_num].message_number = msg_num; */

/* 	    if ((ret = g2_info(cbuf, listsec0, listsec1, &numfields, &numlocal))) */
/* 		return G2C_EMSG; */
/* 	    for (i = 0; i < G2C_SECTION0_LEN; i++) */
/* 		g2c_file[g2cid].msg[msg_num].section0[i] = listsec0[i];		 */
/* 	    for (i = 0; i < G2C_SECTION1_LEN; i++) */
/* 		g2c_file[g2cid].msg[msg_num].section1[i] = listsec1[i]; */
/* 	    g2c_file[g2cid].msg[msg_num].num_fields = numfields; */
/* 	    g2c_file[g2cid].msg[msg_num].num_local = numlocal; */

/* 	    /\* Unpack section 3. *\/ */
/* 	    /\* if ((ret = (int)g2_unpack3(cbuf, &iofst, &igds, &igdstmpl, &mapgridlen, &ideflist, &idefnum))) *\/ */
/* 	    /\* 	return ret; *\/ */
/* 	} */

/* 	/\* Free memory. *\/ */
/* 	if (cbuf) */
/* 	    free(cbuf); */

/* 	/\* Move to next message. *\/ */
/* 	file_pos += bytes_in_msg; */
/*     }     */

/*     /\* If we run out of messages, that's success. *\/ */
/*     if (ret == G2C_ENOMSG) */
/* 	ret = G2C_NOERROR; */

/* #ifdef LOGGING */
/*     /\* Print the file contents for library debugging. *\/ */
/*     g2c_log_file(g2cid); */
/* #endif */

/*     return ret; */
/* } */

/** Read metadata from a GRIB2 file being opened with g2c_open().
 *
 * @param g2cid The indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EBADID g2cid not found.
 * - ::G2C_EFILE File error.
 * - ::G2C_EINVAL Invalid input.
 * - ::G2C_ENOMEM Out of memory.
 * - ::G2C_ENOMSG No GRIB message found.
 *
 * @author Ed Hartnett @date Aug 22, 2022
 */
static int
read_metadata2(int g2cid)
{
    size_t msg_num;
    size_t file_pos = 0;
    size_t bytes_to_msg, bytes_in_msg;
    int ret = G2C_NOERROR;

    /* Find the open file struct. */
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    LOG((2, "read_metadata g2cid %d", g2cid));

    /* Read each message in the file. When there are 0 bytes_in_msg, we are done. */
    for (msg_num = 0; !ret && bytes_in_msg; msg_num++)
    {

        /* Find the message. */
        if ((ret = g2c_seekmsg(g2cid, file_pos, &bytes_to_msg, &bytes_in_msg)))
            return ret;
	LOG((3, "msg_num %d bytes_to_msg %ld bytes_in_msg %ld", msg_num, bytes_to_msg,
	     bytes_in_msg));
        file_pos += bytes_in_msg;
    }    

    /* If we run out of messages, that's success. */
    if (ret == G2C_ENOMSG)
	ret = G2C_NOERROR;

#ifdef LOGGING
    /* Print the file contents for library debugging. */
    g2c_log_file(g2cid);
#endif

    return ret;
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

    /* Copy the path. */
    strncpy(g2c_file[my_g2cid].path, path, G2C_MAX_NAME);

    /* Remember the id. */
    g2c_file[my_g2cid].g2cid = my_g2cid;
    
    /* Pass id back to user. */
    *g2cid = my_g2cid;
    
    /* Read the metadata. */
    if ((ret = read_metadata2(my_g2cid)))
	return ret;

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

/** Free resources holding the file metadata.
 *
 * @param g2cid Indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EBADID - Bad file ID.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
static int
free_metadata(int g2cid)
{
    int m;
    
    /* Check input. */
    if (g2cid > G2C_MAX_FILES)
	return G2C_EBADID;
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    /* Free memory allocated for each message in the file. */
    for (m = 0; m < g2c_file[g2cid].num_messages; m++)
    {
        G2C_MESSAGE_INFO_T *msg = &g2c_file[g2cid].msg[m];
        free(msg->section_number);
        free(msg->section_offset);
    }
    
    return G2C_NOERROR;
}

/** Close a GRIB2 file, freeing resources.
 *
 * @param g2cid Indentifier for the file.
 *
 * @return
 * - ::G2C_NOERROR - No error.
 * - ::G2C_EBADID - Bad file ID.
 *
 * @author Ed Hartnett @date Aug 16, 2022
 */
int
g2c_close(int g2cid)
{
    int ret;
    
    /* Check input. */
    if (g2cid > G2C_MAX_FILES)
	return G2C_EBADID;
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    LOG((1, "g2c_close %d", g2cid));

    /* Free resources. */
    if ((ret = free_metadata(g2cid)))
        return ret;
    
    /* Close the file. */
    if (fclose(g2c_file[g2cid].f))
        return G2C_EFILE;

    /* Reset the file data. */
    g2c_file[g2cid].path[0] = 0;
    g2c_file[g2cid].g2cid = 0;
    g2c_file[g2cid].num_messages = 0;
    g2c_file[g2cid].f = NULL;

    return G2C_NOERROR;
}


