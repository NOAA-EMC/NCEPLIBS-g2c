/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the JPEG compression functions.
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
int enc_jpeg2000(unsigned char *cin, g2int width, g2int height, g2int nbits,
                 g2int ltype, g2int ratio, g2int retry, char *outjpc,
                 g2int jpclen);
int dec_jpeg2000(char *injpc, g2int bufsize, g2int *outfld);
void jpcpack(float *fld, g2int width, g2int height, g2int *idrstmpl,
             unsigned char *cpack, g2int *lcpack);
g2int jpcunpack(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
                float *fld);

int
main()
{
    printf("Testing JPEG functions.\n");
    printf("Testing enc_jpeg2000()/dec_jpeg2000() call...");
    {
        unsigned char data[DATA_LEN] = {1, 2, 3, 4};
        g2int width = 2, height = 2, nbits = 4;
        g2int ltype = 0, ratio = 0, retry = 0, jpclen = PACKED_LEN;
        char outjpc[PACKED_LEN];
        g2int outfld[DATA_LEN];
        int i;
        int ret;

        /* Encode some data. */
        if ((ret = enc_jpeg2000(data, width, height, nbits, ltype,
                                ratio, retry, outjpc, jpclen)) < 0)
        {
            return G2C_ERROR;
        }

        /* Now decode it. */
        if ((ret = dec_jpeg2000(outjpc, jpclen, outfld)))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            if (outfld[i] != data[i])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing jpcpack()/jpcunpack() call...");
    {
        g2int height = 2, width = 2;
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        g2int idrstmpl[7] = {0, 1, 1, 16, 0, 0, 0};
        int i;

        /* Pack the data. */
        jpcpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (jpcunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
        	return G2C_ERROR;
        }
    }
    printf("ok!\n");
    /* printf("Testing jpcpackd()/jpcunpackd() call..."); */
    /* { */
    /*     g2int height = 2, width = 2; */
    /*     g2int len = PACKED_LEN, ndpts = DATA_LEN; */
    /*     double fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0}; */
    /*     double fld_in[DATA_LEN]; */
    /*     unsigned char cpack[PACKED_LEN]; */
    /*     g2int lcpack = PACKED_LEN; */
    /*     g2int idrstmpl[7] = {0, 1, 1, 16, 0, 0, 0}; */
    /*     int i; */

    /*     /\* Pack the data. *\/ */
    /*     jpcpackd(fld, width, height, idrstmpl, cpack, &lcpack); */

    /*     /\* Unpack the data. *\/ */
    /*     if (jpcunpackd(cpack, len, idrstmpl, ndpts, fld_in)) */
    /*         return G2C_ERROR; */

    /*     for (i = 0; i < DATA_LEN; i++) */
    /*     { */
    /*         /\* printf("%g %g\n", fld[i], fld_in[i]); *\/ */
    /*         if (fld[i] != fld_in[i]) */
    /*     	return G2C_ERROR; */
    /*     } */
    /* } */
    /* printf("ok!\n"); */
    printf("Testing jpcpack()/jpcunpack() call with different drstmpl values...");
    {
        g2int height = 2, width = 2;
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml */
        g2int idrstmpl[7] = {
            0, /* Reference value (R) (IEEE 32-bit floating-point value) */
            0, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            32, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0, /* Type of original field values (see Code Table 5.1) */
            0, /* Type of Compression used. (see Code Table 5.40) */
            1 /* Target compression ratio, M:1 (with respect to the bit-depth specified in octet 20), when octet 22 indicates Lossy Compression. Otherwise, set to missing (see Note 3) */
        };
        int i;

        /* Pack the data. */
        jpcpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (jpcunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
        	return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing jpcpack()/jpcunpack() call with constant data field...");
    {
        g2int height = 2, width = 2;
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 1.0, 1.0, 1.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml */
        g2int idrstmpl[7] = {
            0, /* Reference value (R) (IEEE 32-bit floating-point value) */
            0, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            32, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0, /* Type of original field values (see Code Table 5.1) */
            0, /* Type of Compression used. (see Code Table 5.40) */
            1 /* Target compression ratio, M:1 (with respect to the bit-depth specified in octet 20), when octet 22 indicates Lossy Compression. Otherwise, set to missing (see Note 3) */
        };
        int i;

        /* Pack the data. */
        jpcpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (jpcunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
        	return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
