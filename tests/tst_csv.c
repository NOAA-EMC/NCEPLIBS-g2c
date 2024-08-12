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
    if ((ret = g2c_find_desc("Code table 0.0", 0, desc)))
	return ret;
    if (strcmp("Meteorological products", desc))
	return G2C_ERROR;
    if ((ret = g2c_find_desc_str("Code table 0.0", "0", desc)))
	return ret;
    if (strcmp("Meteorological products", desc))
	return G2C_ERROR;

    /* Calling init again is harmless. */
    if (g2c_csv_init())
	return G2C_ERROR;
    
    g2c_free_tables();

    /* Calling free again is harmless. */
    g2c_free_tables();
    
    printf("desc %s\n", desc);
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

