/** @file
 * @brief Searches a file for the next GRIB message.
 * @author Stephen Gilbert @date 2002-10-28
 */
#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

/** 8 bits per byte. */
#define BITS_PER_BYTE 8

/**
 * This subprogram searches a file for the next GRIB Message. The
 * search is done starting at byte offset iseek of the file referenced
 * by lugb for mseek bytes at a time. If found, the starting position
 * and length of the message are returned in lskip and lgrib,
 * respectively. The search is terminated when an EOF or I/O error is
 * encountered.
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2002-10-28 | GILBERT | Modified from Iredell's skgb subroutine
 * 2009-01-16 | VUONG | Changed  lskip to 4 instead of sizof(g2int)
 *
 * @param lugb FILE pointer for the file to search. File must be
 * opened before this routine is called.
 * @param iseek number of bytes in the file to skip before search.
 * @param mseek number of bytes to search at a time (must be at least
 * 16).
 * @param lskip number of bytes to skip from the beggining of the file
 * to where the GRIB message starts.
 * @param lgrib number of bytes in message (set to 0, if no message
 * found).
 *
 * @author Stephen Gilbert @date 2002-10-28
 */
void
seekgb(FILE *lugb, g2int iseek, g2int mseek, g2int *lskip, g2int *lgrib)
{
    g2int k, k4, ipos, nread, lim, start, vers, lengrib;
    int end;
    unsigned char *cbuf;

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
            gbit(cbuf, &start, k * BITS_PER_BYTE, 4 * BITS_PER_BYTE);

            /* Look at the 8th byte, it has the GRIB version. */
            gbit(cbuf, &vers, (k + 7) * BITS_PER_BYTE, 1 * BITS_PER_BYTE);

            /* If the message starts with 'GRIB', and is version 1 or
             * 2, then this is a GRIB message. */
            if (start == 1196575042 && (vers == 1 || vers == 2))
            {
                /* Find the length of the message. */
                if (vers == 1)
                    gbit(cbuf, &lengrib, (k + 4) * BITS_PER_BYTE, 3 * BITS_PER_BYTE);
                if (vers == 2)
                    gbit(cbuf, &lengrib, (k + 12) * BITS_PER_BYTE, 4 * BITS_PER_BYTE);

                /* Read the last 4 bytesof the message. */
                fseek(lugb, ipos + k + lengrib - 4, SEEK_SET);
                k4 = fread(&end, 4, 1, lugb);
                
                /* Look for '7777' at end of grib message. */
                if (k4 == 1 && end == 926365495)
                {
                    /* GRIB message found. */
                    *lskip = ipos + k;
                    *lgrib = lengrib;
                    break;
                }
            }
        }
        ipos = ipos + lim;
    }

    free(cbuf);
}
