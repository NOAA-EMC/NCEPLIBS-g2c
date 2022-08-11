/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the PNG compression functions.
 *
 * Ed Hartnett 10/29/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define DATA_LEN 4
#define PACKED_LEN 80
#define G2C_ERROR 2
#define EPSILON .0001

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
    printf("Testing pngpack()/pngunpack() calls...");
    {
	g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN; 	
	g2float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
	g2float fld_in[DATA_LEN];
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
    printf("Testing pngpackd()/pngunpackd() calls...");
    {
	g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN; 	
	double fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
	double fld_in[DATA_LEN];
	unsigned char cpack[PACKED_LEN];
	g2int lcpack;
        g2int idrstmpl[5] = {0, 1, 1, 16, 0};
	int i;

	/* Pack the data. */
	pngpackd(fld, width, height, idrstmpl, cpack, &lcpack);

	/* Unpack the data. */
	if (pngunpackd(cpack, len, idrstmpl, ndpts, fld_in))
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
	g2float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
	g2float fld_in[DATA_LEN];
	unsigned char cpack[PACKED_LEN];
	g2int lcpack;
        /* See https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml */
        g2int idrstmpl[5] = {
            0, /* Reference value (R) (IEEE 32-bit floating-point value) */
            0, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            32, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0  /* Type of original field values (see Code Table 5.1) */
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
    printf("Testing pngpack()/pngunpack() calls with constant data...");
    {
	g2int height = 2, width = 2, ndpts = DATA_LEN, len = PACKED_LEN; 	
	g2float fld[DATA_LEN] = {1.0, 1.0, 1.0, 1.0};
	g2float fld_in[DATA_LEN];
	unsigned char cpack[PACKED_LEN];
	g2int lcpack;
        /* See https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml */
        g2int idrstmpl[5] = {
            0, /* Reference value (R) (IEEE 32-bit floating-point value) */
            0, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            24, /* Number of bits required to hold the resulting scaled and referenced data values. (i.e. The depth of the grayscale image.) (see Note 2) */
            0  /* Type of original field values (see Code Table 5.1) */
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
    printf("SUCCESS!\n");
    return 0;
}
