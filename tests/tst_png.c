/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the PNG compression functions.
 *
 * Ed Hartnett 10/29/21
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>

#define DATA_LEN 4
#define PACKED_LEN 80
#define EPSILON .0001

int
main()
{
    printf("Testing PNG functions.\n");
    printf("Testing enc_png() call...");
    {
        unsigned char data[4] = {1, 2, 3, 4};
        g2int width = 1, height = 1, nbits = 32;
        g2int width_in, height_in;
        unsigned char pngbuf[200];
        unsigned char cout[200];
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
    printf("Testing g2c_enc_png()/g2c_dec_png() calls...");
    {
        unsigned char data[4] = {1, 2, 3, 4};
        int width = 1, height = 1, nbits = 32;
        int width_in, height_in;
        unsigned char pngbuf[200];
        unsigned char cout[200];
        int i, ret;

        /* Encode some data. */
        if ((ret = g2c_enc_png(data, width, height, nbits, pngbuf)) != 70)
        {
            printf("%d\n", ret);
            return G2C_ERROR;
        }

        /* Now decode it. */
        if ((ret = g2c_dec_png((unsigned char *)pngbuf, &width_in, &height_in, cout)))
        {
            printf("%d\n", ret);
            return G2C_ERROR;
        }

        for (i = 0; i < 4; i++)
            if (cout[i] != data[i])
                return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing pngpack()/pngunpack() calls...");
    {
        g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack;
        g2int idrstmpl[5] = {0, 1, 1, 16, 0};
        int i;

        /* Pack the data. */
        pngpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (pngunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing pngpack()/pngunpack() calls bit_depth 1 ...");
    {
        g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 1.0, 2.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack;
        g2int idrstmpl[5] = {0, 0, 0, 0, 0};
        int i;

        /* Pack the data. */
        pngpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (pngunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        if (idrstmpl[3] != 1)
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing pngpack()/pngunpack() calls bit_depth 2 ...");
    {
        g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 4.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack;
        g2int idrstmpl[5] = {0, 0, 0, 0, 0};
        int i;

        /* Pack the data. */
        pngpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (pngunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        if (idrstmpl[3] != 2)
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing pngpack()/pngunpack() calls bit_depth 4 ...");
    {
        g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN;
        float fld[DATA_LEN] = {1.0, 4.0, 8.0, 16.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack;
        g2int idrstmpl[5] = {0, 0, 0, 0, 0};
        int i;

        /* Pack the data. */
        pngpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (pngunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        if (idrstmpl[3] != 4)
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing g2c_pngpackd()/g2c_pngunpackd() calls...");
    {
        size_t height = 2, width = 2;
        size_t ndpts = DATA_LEN, len = PACKED_LEN;
        double fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        double fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        int lcpack;
        int idrstmpl[5] = {0, 1, 1, 16, 0};
        int i;

        /* Pack the data. */
        g2c_pngpackd(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (g2c_pngunpackd(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (abs(fld[i] - fld_in[i]) > EPSILON)
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing pngpack()/pngunpack() calls with different settings...");
    {
        g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack;
        /* See https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml */
        g2int idrstmpl[5] = {
            0,  /* Reference value (R) (IEEE 32-bit floating-point value) */
            0,  /* Binary scale factor (E) */
            1,  /* Decimal scale factor (D) */
            32, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0   /* Type of original field values (see Code Table 5.1) */
        };
        int i;

        /* Pack the data. */
        pngpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (pngunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing g2c_pngpackd()/g2c_pngunpackd() calls with different settings...");
    {
        size_t height = 2, width = 2;
        size_t ndpts = DATA_LEN, len = PACKED_LEN;
        double fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        double fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        int lcpack;
        /* See https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml */
        int idrstmpl[5] = {
            0,  /* Reference value (R) (IEEE 32-bit floating-point value) */
            0,  /* Binary scale factor (E) */
            1,  /* Decimal scale factor (D) */
            32, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0   /* Type of original field values (see Code Table 5.1) */
        };
        int i;

        /* Pack the data. */
        g2c_pngpackd(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (g2c_pngunpackd(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (abs(fld[i] - fld_in[i]) > EPSILON)
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing pngpack()/pngunpack() calls with constant data...");
    {
        g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN;
        float fld[DATA_LEN] = {1.0, 1.0, 1.0, 1.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack;
        /* See https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml */
        g2int idrstmpl[5] = {
            0,  /* Reference value (R) (IEEE 32-bit floating-point value) */
            0,  /* Binary scale factor (E) */
            1,  /* Decimal scale factor (D) */
            24, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0   /* Type of original field values (see Code Table 5.1) */
        };
        int i;

        /* Pack the data. */
        pngpack(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (pngunpack(cpack, len, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("Testing g2c_pngpackd()/g2c_pngunpackd() calls with constant data...");
    {
        size_t height = 2, width = 2;
        size_t ndpts = DATA_LEN, len = PACKED_LEN;
        double fld[DATA_LEN] = {1.0, 1.0, 1.0, 1.0};
        double fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        int lcpack;
        /* See https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml */
        int idrstmpl[5] = {
            0,  /* Reference value (R) (IEEE 32-bit floating-point value) */
            0,  /* Binary scale factor (E) */
            1,  /* Decimal scale factor (D) */
            24, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0   /* Type of original field values (see Code Table 5.1) */
        };
        int i;

        /* Pack the data. */
        g2c_pngpackd(fld, width, height, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (g2c_pngunpackd(cpack, len, idrstmpl, ndpts, fld_in))
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