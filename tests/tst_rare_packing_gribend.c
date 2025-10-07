/* This is a test for the NCEPLIBS-g2c project. This test is for a rare scenario where
 * the last 4 bytes of the packed data section could be all 55 or hex 0x37, which when
 * converted to ASCII, will resemble the GRIB end message terminator of "7777".
 *
 * This test purposely builds a very small GRIB2 message, with data values purposely
 * set so that when using simple packing with no scaling and nbits = 0, will make
 * the last 4 bytes of the packed data mimic the GRIB terminator.
 *
 * Eric Engle 3/17/25
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>

#define SEC0_LEN 16
#define SEC1_LEN 21
#define SEC3_LEN 72
#define SEC4_LEN 58
#define SEC5_LEN 21
#define SEC6_LEN 6
#define SEC7_LEN 11
#define FULL_MSG_LEN 209

int
main()
{
    printf("Testing rare packing condition and grid end.\n");
    printf("Testing full message creation (expect and ignore error messages)...\n");
    {
        unsigned char cgrib[FULL_MSG_LEN];
        g2int listsec0[2] = {0, 2};
        g2int listsec1[13] = {7, 0, 2, 1, 1, 2023, 9, 29, 0, 0, 0, 0, 1};
        g2int igds[5] = {0, 6, 0, 0, 0};
        g2int igdstmpl[19] = {6, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 50000, 50000, 64};
        g2int ipdsnum = 8;
        g2int ipdstmpl[29] = {1, 8, 2, 0, 250, 0, 0, 1, 0, 1, 0, 0, 255, 0, 0, 2023, 9, 30, 0, 0, 0, 1, 0, 1, 2, 1, 24, 255, 0};
        float coordlist[1] = {1};
        g2int numcoord = 0;
        g2int idrsnum = 0; /* Grid Point Data - Simple Packing (see Template 5.0) */
        g2int idrstmpl[5] = {0, 0, 0, 0, 0};
        float fld[6] = {0.0, 176.9375, 54.9, 55.1, 54.7, 55.3};
        g2int ngrdpts = 6;
        g2int ibmap = 255; // No bit map
        g2int bmap[6] = {1, 1, 1, 1, 1, 1};
        int ret;

        /* Initialize empty message to quiet valgrind errors. */
        for (int i = 0; i < FULL_MSG_LEN; i++)
            cgrib[i] = 0;

        /* Create the message, filling in sections 0 and 1. */
        printf("Calling g2_create()... ");
        ret = g2_create(cgrib, listsec0, listsec1);
        printf("ret = %d\n", ret);
        if (ret != SEC0_LEN + SEC1_LEN)
            return 1;

        /* Add section 3. */
        printf("Calling g2_addgrid()... ");
        ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0);
        printf("ret = %d\n", ret);
        if (ret != SEC0_LEN + SEC1_LEN + SEC3_LEN)
            return 1;

        /* Add sections 4, 5, 6, and 7. */
        printf("Calling g2_addfield()... ");
        ret = g2_addfield(cgrib, ipdsnum, ipdstmpl, coordlist, numcoord,
                          idrsnum, idrstmpl, fld, ngrdpts, ibmap, bmap);
        printf("ret = %d\n", ret);
        if (ret != SEC0_LEN + SEC1_LEN + SEC3_LEN + SEC4_LEN + SEC5_LEN + SEC6_LEN + SEC7_LEN)
            return 1;

        /* Add section 8. */
        printf("Calling g2_gribend()... ");
        ret = g2_gribend(cgrib);
        if (ret != FULL_MSG_LEN)
            return 1;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
