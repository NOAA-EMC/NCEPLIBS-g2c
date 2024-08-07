/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2ccsv.c.
 *
 * Ed Hartnett, Alyson Stahl 8/5/24
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

int
main()
{
    int ret;
    char desc[G2C_MAX_GRIB_DESC_LEN + 1];
    
    printf("Testing CSV ingestion...\n");
    if (g2c_csv_init())
	return G2C_ERROR;

    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

