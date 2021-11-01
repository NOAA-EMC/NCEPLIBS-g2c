/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the spectral compression functions.
 *
 * Ed Hartnett 11/1/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define DATA_LEN 4
#define PACKED_LEN 200
#define G2C_ERROR 2

/* Prototypes we are testing. */

int
main()
{
    printf("Testing spec functions.\n");
    /* printf("Testing jpcpack()/jpcunpack() calls..."); */
    /* { */
    /*     g2int height = 2, width = 2; */
    /*     g2int len = PACKED_LEN, ndpts = DATA_LEN; */
    /*     g2float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0}; */
    /*     g2float fld_in[DATA_LEN]; */
    /*     unsigned char cpack[PACKED_LEN]; */
    /*     g2int lcpack = PACKED_LEN; */
    /*     g2int idrstmpl[7] = {0, 1, 1, 16, 0, 0, 0}; */
    /*     int i; */

    /*     /\* Pack the data. *\/ */
    /*     jpcpack(fld, width, height, idrstmpl, cpack, &lcpack); */

    /*     /\* Unpack the data. *\/ */
    /*     if (jpcunpack(cpack, len, idrstmpl, ndpts, fld_in)) */
    /*         return G2C_ERROR; */

    /*     for (i = 0; i < DATA_LEN; i++) */
    /*     { */
    /*         /\* printf("%g %g\n", fld[i], fld_in[i]); *\/ */
    /*         if (fld[i] != fld_in[i]) */
    /*     	return G2C_ERROR; */
    /*     } */
    /* } */
    /* printf("ok!\n"); */
    /* printf("Testing enc_jpeg2000() call..."); */
    /* { */
    /*     unsigned char data[4] = {1, 2, 3, 4}; */
    /*     g2int width = 2, height = 2, nbits = 4; */
    /*     g2int ltype = 0, ratio = 0, retry = 0, jpclen = 200; */
    /*     char outjpc[200]; */
    /*     g2int outfld[4]; */
    /*     /\* int i; *\/ */
    /*     int ret; */

    /*     /\* Encode some data. *\/ */
    /*     /\* 168 on Linux, but 133 on windows? *\/ */
    /*     if ((ret = enc_jpeg2000(data, width, height, nbits, ltype, ratio, retry, outjpc, jpclen)) < 133) */
    /*     { */
    /*         printf("%d\n", ret); */
    /*         return G2C_ERROR; */
    /*     } */

    /*     /\* Now decode it. *\/ */
    /*     if ((ret = dec_jpeg2000(outjpc, jpclen, outfld))) */
    /*     { */
    /*         printf("%d\n", ret); */
    /*         return G2C_ERROR; */
    /*     } */

    /*     /\* for (i = 0; i < 4; i++) *\/ */
    /*     /\*     if (cout[i] != data[i]) *\/ */
    /*     /\*         return G2C_ERROR; *\/ */
    /* } */
    /* printf("ok!\n"); */
    printf("SUCCESS!\n");
    return 0;
}
