/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the PNG compression functions.
 *
 * Ed Hartnett 10/29/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define G2C_ERROR 2

/* Prototypes we are testing. */
int enc_png(char *data, g2int width, g2int height, g2int nbits, char *pngbuf);
int dec_png(unsigned char *pngbuf, g2int *width, g2int *height, char *cout);

int
main()
{
    printf("Testing PNG functions.\n");
    printf("Testing enc_png() call...");
    {
        char data[4] = {1, 2, 3, 4};
        g2int width = 1, height = 1, nbits = 32;
        g2int width_in, height_in;
        char pngbuf[200];
        char cout[200];
        int i, ret;

        /* Encode some data. */
        if ((ret = enc_png(data, width, height, nbits, pngbuf)) != 70)
        {
            printf("%d\n", ret);
            return G2C_ERROR;
        }

        /* Now decode it. */
        if ((ret = dec_png((unsigned char *)pngbuf, &width_in, &height_in, cout)))
        {
            printf("%d\n", ret);
            return G2C_ERROR;
        }

        for (i = 0; i < 4; i++)
            if (cout[i] != data[i])
                return G2C_ERROR;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
