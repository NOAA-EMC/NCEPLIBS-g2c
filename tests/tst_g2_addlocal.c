/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2_addlocal.
 *
 * Ed Hartnett 11/3/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define SEC0_LEN 16
#define SEC1_LEN 21
#define MSG_LEN 52
#define G2C_ERROR 2

g2int g2_unpack2(unsigned char *cgrib, g2int *iofst, g2int *lencsec2,
                 unsigned char **csec2);

int
main()
{
    printf("Testing g2_addlocal().\n");
    printf("Testing g2_addlocal() call (expect and ignore error messages)...");
    {
        unsigned char cgrib[MSG_LEN];
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        unsigned char expected_cgrib[MSG_LEN] = {71, 82, 73, 66, 0, 0, 1, 2, 0,
            0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 21, 1, 0, 7, 0, 4, 24, 0, 0, 7, 229,
            10, 24, 6, 54, 59, 7, 192, 0, 0, 0, 15, 2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        unsigned char csec2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        g2int lcsec2 = 10;
        g2int iofst;
        unsigned char *csec2_in;
        g2int lensec2_in;
        unsigned char old_val;
        int i;
        int ret;

        /* Create the grib message with sections 0 and 1. */
        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

        /* Change the first char of the message. Just to be dumb. */
        old_val = cgrib[0];
        cgrib[0] = 0;

        /* Try to add the local section. Won't work. */
        if ((ret = g2_addlocal(cgrib, csec2, lcsec2)) != -1)
            return G2C_ERROR;

        /* Change the first char back. */
        cgrib[0] = old_val;

        /* Add the local section. */
        if ((ret = g2_addlocal(cgrib, csec2, lcsec2)) != MSG_LEN)
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < MSG_LEN; i++)
        {
            /* printf("%d, ", cgrib[i]); */
            if (cgrib[i] != expected_cgrib[i])
                return G2C_ERROR;
        }

        /* Unpack the local section. */
        iofst = (SEC0_LEN + SEC1_LEN) * 8;
        if (g2_unpack2(cgrib, &iofst, &lensec2_in, &csec2_in))
            return G2C_ERROR;
        if (iofst != 416)
            return G2C_ERROR;
        if (lensec2_in != 10)
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < 10; i++)
            if (csec2_in[i] != csec2[i])
                return G2C_ERROR;

        free(csec2_in);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
