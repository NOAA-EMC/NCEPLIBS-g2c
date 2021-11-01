/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the JPEG compression functions.
 *
 * Ed Hartnett 11/1/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define DATA_LEN 4
#define PACKED_LEN 80
#define G2C_ERROR 2

/* Prototypes we are testing. */
int enc_png(char *data, g2int width, g2int height, g2int nbits, char *pngbuf);
int dec_png(unsigned char *pngbuf, g2int *width, g2int *height, char *cout);
g2int pngunpack(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
                g2float *fld);
void pngpack(g2float *fld, g2int width, g2int height, g2int *idrstmpl, 
             unsigned char *cpack, g2int *lcpack);

int
main()
{
    printf("Testing JPEG functions.\n");
    printf("Testing enc_jpeg2000() call...");
    {
        unsigned char data[4] = {1, 2, 3, 4};
        g2int width = 1, height = 1, nbits = 32;
        g2int ltype = 1, ratio = 1, retry = 0, jpclen = 100;
        char outjpc[200];
        /* g2int width_in, height_in; */
        /* char cout[200]; */
        /* int i; */
        int ret;

        /* Encode some data. */
        if ((ret = enc_jpeg2000(data, width, height, nbits, ltype, ratio, retry, outjpc, jpclen)))
        {
            printf("%d\n", ret);
            return G2C_ERROR;
        }

        /* /\* Now decode it. *\/ */
        /* if ((ret = dec_png((unsigned char *)pngbuf, &width_in, &height_in, cout))) */
        /* { */
        /*     printf("%d\n", ret); */
        /*     return G2C_ERROR; */
        /* } */

        /* for (i = 0; i < 4; i++) */
        /*     if (cout[i] != data[i]) */
        /*         return G2C_ERROR; */
    }
    printf("ok!\n");
    /* printf("Testing pngpack()/pngunpack() calls..."); */
    /* { */
    /*     g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN; 	 */
    /*     g2float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0}; */
    /*     g2float fld_in[DATA_LEN]; */
    /*     unsigned char cpack[PACKED_LEN]; */
    /*     g2int lcpack; */
    /*     g2int idrstmpl[5] = {0, 1, 1, 16, 0}; */
    /*     int i; */

    /*     /\* Pack the data. *\/ */
    /*     pngpack(fld, width, height, idrstmpl, cpack, &lcpack); */

    /*     /\* Unpack the data. *\/ */
    /*     if (pngunpack(cpack, len, idrstmpl, ndpts, fld_in)) */
    /*         return G2C_ERROR; */

    /*     for (i = 0; i < DATA_LEN; i++) */
    /*     { */
    /*         /\* printf("%g %g\n", fld[i], fld_in[i]); *\/ */
    /*         if (fld[i] != fld_in[i]) */
    /*     	return G2C_ERROR; */
    /*     } */
    /* } */
    /* printf("ok!\n"); */
    printf("SUCCESS!\n");
    return 0;
}
