/* This is a test in the NCEPLIBS-g2c project.
 *
 * This test is for decoding full grib2 message.
 *
 * Dusan Jovic, July, 2021
 * Ed Hartnett
 */

#include "grib2_int.h"
#include <stdio.h>

int main()
{
    unsigned char cgrib[] = {
        0x47, 0x52, 0x49, 0x42, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xc3, 0x00, 0x00, 0x00, 0x15, 0x01, 0x00, 0x07, 0x00,
        0x00, 0x02, 0x01, 0x01, 0x07, 0xe5, 0x07, 0x0e, 0x06, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x48, 0x03, 0x00, 0x00, 0x00, 0x00, 0x79, 0x00,
        0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x00,
        0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01,
        0xc9, 0xc3, 0x80, 0x01, 0x31, 0x2d, 0x00, 0x30, 0x02, 0x62, 0x5a, 0x00,
        0x01, 0xc9, 0xc3, 0x80, 0x00, 0x0f, 0x42, 0x40, 0x00, 0x0f, 0x42, 0x40,
        0x40, 0x00, 0x00, 0x00, 0x22, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x60, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x06, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x15, 0x05, 0x00, 0x00, 0x00, 0x79, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x06,
        0x06, 0xff, 0x00, 0x00, 0x00, 0x15, 0x07, 0xff, 0xef, 0xf7, 0xe0, 0x00,
        0x00, 0x00, 0x08, 0x00, 0x01, 0x83, 0x38, 0xee, 0x3f, 0xa7, 0x80, 0x37,
        0x37, 0x37, 0x37
    };

    g2int listsec0[3];
    g2int listsec0_ok[3] = {2, 2, 195};
    g2int listsec1[13];
    g2int listsec1_ok[13] = {7, 0, 2, 1, 1, 2021, 7, 14, 6, 0, 0, 0, 1};
    g2int numfields;
    g2int numlocal;

    float fld_ok[121] = {   /* 11x11 grid */
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
        1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1,
        0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
        1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1
    };

    gribfield* gfld = NULL;
    int i;
    int ret;

    printf("Testing decoding full grib2 message.\n");

    if ((ret = g2_info(cgrib, listsec0, listsec1, &numfields, &numlocal)) != 0)
        return G2C_ERROR;

    for (i = 0; i < 3; i++) {
        if (listsec0[i] != listsec0_ok[i])
            return G2C_ERROR;
    }
    for (i = 0; i < 13; i++) {
        if (listsec1[i] != listsec1_ok[i])
            return G2C_ERROR;
    }
    if (numfields != 1)
        return G2C_ERROR;
    if (numlocal != 0)
        return G2C_ERROR;

    /* Now check the new g2c_info() function, it does more or less the
     * same thing as the g2_info() function, but with some additional
     * parameters. */
    {
	int listsec0_int[3];
	int listsec0_ok_int[3] = {2, 2, 195};
	int listsec1_int[13];
	int listsec1_ok_int[13] = {7, 0, 2, 1, 1, 2021, 7, 14, 6, 0, 0, 0, 1};
	int numfields_int;
	int numlocal_int;
	
        if ((ret = g2c_info(cgrib, listsec0_int, listsec1_int, &numfields_int, &numlocal_int)) != 0)
            return G2C_ERROR;

        for (i = 0; i < 3; i++)
            if (listsec0_int[i] != listsec0_ok_int[i])
                return G2C_ERROR;

        for (i = 0; i < 13; i++) 
            if (listsec1_int[i] != listsec1_ok_int[i])
                return G2C_ERROR;

        if (numfields_int != 1)
            return G2C_ERROR;
        if (numlocal_int != 0)
            return G2C_ERROR;

	/* NULL may be passed for any parameter. */
        if ((ret = g2c_info(cgrib, listsec0_int, listsec1_int, NULL, &numlocal_int)) != 0)
            return G2C_ERROR;
        if ((ret = g2c_info(cgrib, listsec0_int, listsec1_int, &numfields_int, NULL)) != 0)
            return G2C_ERROR;
        if ((ret = g2c_info(cgrib, listsec0_int, listsec1_int, NULL, NULL)) != 0)
            return G2C_ERROR;
        if ((ret = g2c_info(cgrib, NULL, listsec1_int, NULL, NULL)) != 0)
            return G2C_ERROR;
        if ((ret = g2c_info(cgrib, listsec0_int, NULL, NULL, NULL)) != 0)
            return G2C_ERROR;
        if ((ret = g2c_info(cgrib, NULL, NULL, NULL, NULL)) != 0)
            return G2C_ERROR;
    }

    if ((ret = g2_getfld(cgrib, 1, 1, 1, &gfld)) != 0)
        return G2C_ERROR;

    if (gfld->version != 2)
        return G2C_ERROR;

    if (gfld->ndpts != 121) /* 11x11 grid */
        return G2C_ERROR;

    for (i = 0; i < gfld->ndpts; i++) {
        if (gfld->fld[i] != fld_ok[i])
            return G2C_ERROR;
    }

    g2_free(gfld);

    printf("SUCCESS!\n");
    return 0;
}
