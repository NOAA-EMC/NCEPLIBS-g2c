/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the PNG compression functions.
 *
 * Ed Hartnett 10/29/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define G2C_ERROR 2

int enc_png(char *data, g2int width, g2int height, g2int nbits, char *pngbuf);

int
main()
{
    printf("Testing PNG functions.\n");
    printf("Testing enc_png() call...");
    {
        char data[4] = {1, 2, 3, 4};
        g2int width = 4, height = 1, nbits = 32;
        /* char *pngbuf = NULL; */
        char pngbuf[100];
        int ret;
        
        ret = enc_png(data, width, height, nbits, pngbuf);
        printf("%d\n", ret);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
