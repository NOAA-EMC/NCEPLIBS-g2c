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
#define MOST_MSG_LEN 178
#define FULL_MSG_LEN 182
#define G2C_ERROR 2

int
main()
{
    printf("Testing g2_addfield().\n");
    printf("Testing full message creation (expect and ignore error messages)...\n");
    {
        unsigned char cgrib[FULL_MSG_LEN];
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int igds[5] = {0, 4, 0, 0, 0};
        g2int igdstmpl[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
        unsigned char expected_cgrib[FULL_MSG_LEN] = {0x47, 0x52, 0x49, 0x42, 0x00, 0x00, 0x01, 0x02, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x00, 0x00, 0x00, 0x15, 0x01, 0x00, 0x07, 0x00, 0x04,
            0x18, 0x00, 0x00, 0x07, 0xe5, 0x0a, 0x18, 0x06, 0x36, 0x3b, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x48,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
            0x03, 0x00, 0x00, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
            0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00,
            0x00, 0x0c, 0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x11, 0x12, 0x00, 0x00, 0x00, 0x22, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02,
            0x03, 0x04, 0x00, 0x05, 0x06, 0x07, 0x00, 0x00, 0x00, 0x08, 0x09, 0x0a, 0x00, 0x00, 0x00, 0x0b,
            0x0c, 0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x15, 0x05, 0x00, 0x00, 0x00, 0x04, 0x00,
            0x00, 0x42, 0xc8, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x07, 0x06,
            0x00, 0xf0, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0a, 0x60, 0x37, 0x37, 0x37, 0x37};
        unsigned char old_val;
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
        g2int bmap[4] = {1, 1, 1, 1};
        g2int listsec0_in[3], listsec1_in[13];
        g2int numfields, numlocal;
        int i;
        int ret;

        /* Create the message, filling in sections 0 and 1. */
        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

        /* Add section 3. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != 109)
            return G2C_ERROR;

        /* Try to add section 8 - this will fail because section 7 is
         * not defined yet. */
        if ((ret = g2_gribend(cgrib)) != -4)
            return G2C_ERROR;

        /* Add sections 4, 5, 6, and 7. */
        if ((ret = g2_addfield(cgrib, ipdsnum, ipdstmpl, coordlist, numcoord,
                               idrsnum, idrstmpl, fld, ngrdpts, ibmap, bmap)) != MOST_MSG_LEN)
            return G2C_ERROR;

        /* Change the first char of the message. Just to be dumb. */
        old_val = cgrib[0];
        cgrib[0] = 0;
        
        /* Try to add section 8 - this will fail because we changed
         * first char of message. */
        if ((ret = g2_gribend(cgrib)) != -1)
            return G2C_ERROR;

        /* Change the first char back. */
        cgrib[0] = old_val;
        
        /* Add section 8. */
        if ((ret = g2_gribend(cgrib)) != FULL_MSG_LEN)
            return G2C_ERROR;

        /* Check the contents of the message for correctness. */
        for (i = 0; i < FULL_MSG_LEN; i++)
        {
            /* printf("0x%2.2lx, ", cgrib[i]); */
            if (cgrib[i] != expected_cgrib[i])
                return G2C_ERROR;
        }

        /* Try to re-add section 3 - this will fail. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != -2)
            return G2C_ERROR;

        /* Use g2_info() to learn about our messaage. */
        if ((ret = g2_info(cgrib, listsec0_in, listsec1_in, &numfields, &numlocal)))
            return G2C_ERROR;

        /* Check results. */
        if (numlocal || numfields != 1 || listsec0_in[0] != 1 || listsec0_in[1] != 2 ||
            listsec0_in[2] != FULL_MSG_LEN)
            return G2C_ERROR;
        for (i = 0; i < 13; i++)
            if (listsec1_in[i] != listsec1[i])
                return G2C_ERROR;
        
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
