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
#define MSG_LEN 109
#define G2C_ERROR 2

int
main()
{
    printf("Testing g2_addlocal().\n");
    printf("Testing g2_addlocal() call...");
    {
        unsigned char cgrib[MSG_LEN];
        g2int lencurr;
        g2int listsec0[2] = {1, 2};
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int igds[5] = {0, 4, 0, 0, 0};
        g2int igdstmpl[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
        unsigned char expected_cgrib[MSG_LEN] = {71, 82, 73, 66, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0,
            109, 0, 0, 0, 21, 1, 0, 7, 0, 4, 24, 0, 0, 7, 229, 10, 24, 6, 54, 59, 7, 192, 0, 0, 0,
            72, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 3, 0, 0, 0, 4, 5, 0, 0, 0, 6, 0, 0,
            0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 13, 0, 0, 0, 14,
            0, 0, 0, 15, 0, 0, 0, 16, 0, 0, 0, 17, 18};
        unsigned char old_val;
        int i;
        int ret;

        if ((ret = g2_create(cgrib, listsec0, listsec1)) != SEC0_LEN + SEC1_LEN)
            return G2C_ERROR;

        /* Mess up section length. */
        old_val = cgrib[19];
        cgrib[19] = 99;

        /* Try to add the grid. Won't work, bad section length. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != -3)
            return G2C_ERROR;
        
        /* Fix the section length. */
        cgrib[19] = old_val;

        /* Add the grid. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != 109)
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < MSG_LEN; i++)
        {
            /* printf("%d %d %d\n", i, cgrib[i], expected_cgrib[i]);  */
            if (cgrib[i] != expected_cgrib[i])
                return G2C_ERROR;
        }

        gbit(cgrib, &lencurr, 96, 32);
        if (lencurr != MSG_LEN)
            return G2C_ERROR;

        /* Try to add section 3 again. Won't work. */
        if ((ret = g2_addgrid(cgrib, igds, igdstmpl, NULL, 0)) != -4)
            return G2C_ERROR;
        
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
