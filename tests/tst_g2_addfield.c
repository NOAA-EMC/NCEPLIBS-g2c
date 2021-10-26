/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2_addfield.
 *
 * Ed Hartnett 10/25/21
 */

#include <stdio.h>
#include "grib2.h"

#define SEC0_LEN 16
#define SEC1_LEN 21
#define SEC3_LEN 34
#define MSG_LEN 109
#define G2C_ERROR 2

int
main()
{
    printf("Testing g2_addfield().\n");
    printf("Testing g2_create() call...");
    {
        unsigned char cgrib[MSG_LEN];
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int igds[5] = {0, 4, 0, 0, 0};
        g2int igdstmpl[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
        unsigned char expected_cgrib[MSG_LEN] = {71, 82, 73, 66, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0,
            109, 0, 0, 0, 21, 1, 0, 7, 0, 4, 24, 0, 0, 7, 229, 10, 24, 6, 54, 59, 7, 192, 0, 0, 0,
            72, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 3, 0, 0, 0, 4, 5, 0, 0, 0, 6, 0, 0,
            0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 13, 0, 0, 0, 14,
            0, 0, 0, 15, 0, 0, 0, 16, 0, 0, 0, 17, 18};
        int i;
        int ret;

        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != 109)
            return G2C_ERROR;
        for (i = 0; i < MSG_LEN; i++)
        {
            /* printf("%d %d %d\n", i, cgrib[i], expected_cgrib[i]);  */
            if (cgrib[i] != expected_cgrib[i])
                return G2C_ERROR;
        }

        /* Analysis or forecast at a horizontal level or in a
         * horizontal layer at a point in time. */
        g2int ipdsnum = 0;
        g2int ipdstmpl[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        g2float coordlist[1] = {1};
        g2int numcoord = 0;
        g2int idrsnum = 0; /* Grid Point Data - Simple Packing (see Template 5.0) */
        g2int idrstmpl[5] = {0, 1, 2, 3, 4};
        g2float fld[4] = {1, 2, 3, 4};
        g2int ngrdpts = 4;
        g2int ibmap = 0;
        g2int bmap[1] = {0};
        if ((ret = g2_addfield(cgrib, ipdsnum, ipdstmpl, coordlist, numcoord,
                               idrsnum, idrstmpl, fld, ngrdpts, ibmap, bmap)) != 176)
        {
            printf("%d\n", ret);
            return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
