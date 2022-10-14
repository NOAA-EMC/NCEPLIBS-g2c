/** @file
 * @brief Search a file for the next GRIB message.
 * @author Stephen Gilbert @date 2002-10-28
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2002-10-28 | GILBERT | Modified from Iredell's skgb subroutine
 * 2009-01-16 | VUONG | Changed  lskip to 4 instead of sizof(g2int)
 * 2022-09-11 | Hartnett | Added g2c_seekgb() function.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"
/* #if defined(APPLE) */
/*   #include <machine/endian.h> */
/* #else */
/*   #include <endian.h> */
/* #endif */

#define G2C_SEEKMSG_BUFSIZE 4092 /**< Size of buffer used in g2c_seekmsg(). */

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/**
 * Search a file for the next GRIB2 Message. 
 *
 * The search is terminated when a GRIB2 message is found, or the end
 * of the file is reached.
 *
 * @param g2cid ID of an open GRIB2 file, returned from
 * g2c_open()/g2c_create().
 * @param skip The number of bytes in the file to skip before
 * starting the search.
 * @param offset Pointer that gets the number of bytes to skip from
 * the beggining of the file to where the GRIB message starts. Ignored
 * if NULL.
 * @param msglen Pointer that gets the number of bytes in message (set
 * to 0, if no message found). Ignored if NULL.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EBADID Bad g2cid.
 * - ::G2C_ENOMEM Out of memory.
 *
 * @author Ed Hartnett @date 2022-09-11
 */
int
g2c_seekmsg(int g2cid, size_t skip, size_t *offset, size_t *msglen)
{
    size_t k4;
    int k, lim;
    int end;
    unsigned char *cbuf;
    size_t bytes_read = G2C_SEEKMSG_BUFSIZE;
    size_t my_msglen = 0, my_offset = 0, ipos;

    /* Find the open file struct. */
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;
    
    LOG((3, "g2c_seekgb skip %ld", skip));

    /* Get memory to read in some of the file. */
    if (!(cbuf = malloc(G2C_SEEKMSG_BUFSIZE)))
        return G2C_ENOMEM;

    ipos = skip;

    /* Loop until grib message is found. */
    while (my_msglen == 0 && bytes_read == G2C_SEEKMSG_BUFSIZE)
    {
        /* Read partial section. */
        if (fseek(g2c_file[g2cid].f, ipos, SEEK_SET))
        {
            free(cbuf);
            return G2C_EFILE;
        }
        bytes_read = fread(cbuf, sizeof(unsigned char), G2C_SEEKMSG_BUFSIZE, g2c_file[g2cid].f);
        lim = bytes_read - 8;

        /* Look for 'GRIB...2' in partial section. */
        for (k = 0; k < lim; k++)
        {
            if (!strncmp((char *)&cbuf[k], G2C_MAGIC_HEADER, strlen(G2C_MAGIC_HEADER)) && cbuf[k + 7] == 2)
            {
                /* Find the length of the message. This is stored as
                 * an 8-byte big-endian integer starting at positon
                 * 8 in cbuf. */
                my_msglen = bswap64(*(size_t *)&cbuf[k + 8]);
                
		LOG((4, "my_msglen %ld", my_msglen));

                /* Read the last 4 bytes of the message. */
                if (fseek(g2c_file[g2cid].f, ipos + k + my_msglen - 4, SEEK_SET))
                {
                    free(cbuf);
                    return G2C_EFILE;
                }
                    
                if ((k4 = fread(&end, 4, 1, g2c_file[g2cid].f)) != 1)
                {
                    free(cbuf);
                    return G2C_EFILE;
                }
                    
                /* Look for '7777' at end of grib message. */
                if (k4 == 1 && end == 926365495)
                {
                    /* GRIB message found. */
                    my_offset = ipos + k;
		    LOG((4, "found end of message my_offset %ld", my_offset));
                    break;
                }
            }
        }
        ipos = ipos + lim;
    }

    /* Free resources. */
    free(cbuf);

    /* Return information to the caller. */
    if (offset)
        *offset = my_offset;
    if (msglen)
        *msglen = my_msglen;

    return G2C_NOERROR;
}

/**
 * Search a file for the next GRIB Message. 
 *
 * The search is done starting at byte offset iseek of the file
 * referenced by lugb for mseek bytes at a time. If found, the
 * starting position and length of the message are returned in lskip
 * and lgrib, respectively. The search is terminated when an EOF or
 * I/O error is encountered.
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2002-10-28 | GILBERT | Modified from Iredell's skgb subroutine
 * 2009-01-16 | VUONG | Changed  lskip to 4 instead of sizof(g2int)
 *
 * @param lugb FILE pointer for the file to search. File must be
 * opened before this routine is called.
 * @param iseek The number of bytes in the file to skip before search.
 * @param mseek The maximum number of bytes to search at a time (must
 * be at least 16, but larger numbers like 4092 will result in better
 * perfomance).
 * @param lskip Pointer that gets the number of bytes to skip from the
 * beggining of the file to where the GRIB message starts.
 * @param lgrib Pointer that gets the number of bytes in message (set
 * to 0, if no message found).
 *
 * @author Stephen Gilbert @date 2002-10-28
 */
void
seekgb(FILE *lugb, g2int iseek, g2int mseek, g2int *lskip, g2int *lgrib)
{
    g2int k, k4, ipos, nread, lim, start, vers, lengrib;
    int end;
    unsigned char *cbuf;


    LOG((3, "seekgb iseek %ld mseek %ld", iseek, mseek));
    
    *lgrib = 0;
    cbuf = (unsigned char *)malloc(mseek);
    nread = mseek;
    ipos = iseek;

    /* Loop until grib message is found. */
    while (*lgrib == 0 && nread == mseek)
    {
        /* Read partial section. */
        fseek(lugb, ipos, SEEK_SET);
        nread = fread(cbuf, sizeof(unsigned char), mseek, lugb);
        lim = nread - 8;

        /* Look for 'grib...' in partial section. */
        for (k = 0; k < lim; k++)
        {
            /* Look at the first 4 bytes - should be 'GRIB'. */
            gbit(cbuf, &start, k * BYTE, 4 * BYTE);

            /* Look at the 8th byte, it has the GRIB version. */
            gbit(cbuf, &vers, (k + 7) * BYTE, 1 * BYTE);

            /* If the message starts with 'GRIB', and is version 1 or
             * 2, then this is a GRIB message. */
            if (start == 1196575042 && (vers == 1 || vers == 2))
            {
                /* Find the length of the message. */
                if (vers == 1)
                    gbit(cbuf, &lengrib, (k + 4) * BYTE, 3 * BYTE);
                if (vers == 2)
                    gbit(cbuf, &lengrib, (k + 12) * BYTE, 4 * BYTE);
		LOG((4, "lengrib %ld", lengrib));

                /* Read the last 4 bytesof the message. */
                fseek(lugb, ipos + k + lengrib - 4, SEEK_SET);
                k4 = fread(&end, 4, 1, lugb);
                
                /* Look for '7777' at end of grib message. */
                if (k4 == 1 && end == 926365495)
                {
                    /* GRIB message found. */
                    *lskip = ipos + k;
                    *lgrib = lengrib;
		    LOG((4, "found end of message lengrib %ld", lengrib));
                    break;
                }
            }
        }
        ipos = ipos + lim;
    }

    free(cbuf);
}
