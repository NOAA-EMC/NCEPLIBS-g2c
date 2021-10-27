/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2_unpack functions.
 *
 * Ed Hartnett 10/27/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define SEC0_LEN 16
#define SEC1_LEN 21
#define SEC3_LEN 34
#define MSG_LEN 109
#define G2C_ERROR 2

int
main()
{
    printf("Testing g2_unpack functions.\n");
    printf("Testing g2_unpack1() call...");
    {
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        /* We have:
           0-15 - section0
           16-19 - length of section 1
           20-41 - section1
         */
        unsigned char cgrib[MSG_LEN] = {71, 82, 73, 66, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 109,
            0, 0, 0, 21,
            1, 0, 7, 0, 4, 24, 0, 0, 7, 229, 10, 24, 6, 54, 59, 7, 192, 0, 0, 0, 72, 3,
            0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 3, 0, 0, 0, 4, 5, 0, 0, 0, 6, 0, 0,
            0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 13, 0, 0, 0, 14,
            0, 0, 0, 15, 0, 0, 0, 16, 0, 0, 0, 17, 18};
        g2int iofst = 128, idslen;
        g2int *ids;
        int i;

        /* Unpack section1 - starts at bit 128. */
        if (g2_unpack1(cgrib, &iofst, &ids, &idslen))
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < 13; i++)
            if (ids[i] != listsec1[i])
                return G2C_ERROR;

        /* Free memory. */
        free(ids);

    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
