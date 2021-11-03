/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2_addlocal.
 *
 * Ed Hartnett 11/3/21
 */

#include <stdio.h>
#include "grib2.h"

#define SEC0_LEN 16
#define SEC1_LEN 21
#define SEC3_LEN 34
#define MSG_LEN 52
#define G2C_ERROR 2

int
main()
{
    printf("Testing g2_addlocal().\n");
    printf("Testing g2_addlocal() call...");
    {
        unsigned char cgrib[MSG_LEN];
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        unsigned char expected_cgrib[MSG_LEN] = {71, 82, 73, 66, 0, 0, 1, 2, 0,
            0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 21, 1, 0, 7, 0, 4, 24, 0, 0, 7, 229,
            10, 24, 6, 54, 59, 7, 192, 0, 0, 0, 15, 2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        unsigned char csec2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        g2int lcsec2 = 10;
        /* unsigned char old_val; */
        int i;
        int ret;

        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

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
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
