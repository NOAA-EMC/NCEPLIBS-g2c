/* This is a test for the NCEPLIBS-g2c project. This test is for
 * gbits.c.
 *
 * Ed Hartnett 7/19/21
 */

#include <stdio.h>
#include "grib2.h"

#define G2C_ERROR 2

int
main()
{
    
    printf("Testing sbit.\n");
    printf("Testing simple sbit() call...");
    {
	unsigned char out[1] = {0x00};
	g2int in[1] = {0x01};
	
	sbit(out, in, 0, 8);
	if (out[0] != 1)
	    return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing sbit() call as used in g2_create()...");
    {
	unsigned char cgrib[16]; /* Section 0 is 16 bytes long. */
        g2int listsec0[2] = {1, 2};
        g2int zero = 0;        

        /* This code matches code in g2_create(). See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_sect0.shtml. */
        /* Pack Section 0 - Indicator Section (except for total length of
         * GRIB message). */
        cgrib[0] = 0x47; /* 'G' */
        cgrib[1] = 0x52; /* 'R' */
        cgrib[2] = 0x49; /* 'I' */
        cgrib[3] = 0x42; /* 'B' */
        sbit(cgrib, &zero, 32, 16); /* reserved for future use */
        if (cgrib[4] != 0 || cgrib[5] != 0) return G2C_ERROR;
        sbit(cgrib, &listsec0[0], 48, 8); /* Discipline */
        if (cgrib[6] != 1) return G2C_ERROR;
        sbit(cgrib, &listsec0[1], 56, 8); /* GRIB edition number */
        if (cgrib[7] != 2) return G2C_ERROR;
    }
    printf("ok!\n");
    /* printf("Testing more sbit() calls..."); */
    /* { */
    /* 	unsigned char out; */
    /* 	g2int in = 1; */
    /* 	g2int expected_out[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01}; */
    /* 	int i; */

    /* 	for (i = 0; i < 8; i++) */
    /* 	{ */
    /* 	    sbit(&out, &in, 0, i + 1); */
    /* 	    /\* printf("in 0x%02x out 0x%02x\n", in, out); *\/ */
    /* 	    if (out != expected_out[i]) */
    /* 		return G2C_ERROR; */
    /* 	} */
    /* } */
    /* printf("ok!\n"); */
    printf("SUCCESS!\n");
    return 0;
}
