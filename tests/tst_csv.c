/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2ccsv.c.
 *
 * Ed Hartnett 11/6/22
 */
#include "grib2_int.h"

int
main()
{
    printf("Testing GRIB2 CSV file ingestion...\n");
    if (g2c_csv_init())
	return G2C_ERROR;
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

