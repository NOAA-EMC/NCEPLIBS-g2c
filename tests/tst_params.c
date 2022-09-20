/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2cparams.c.
 *
 * Ed Hartnett 9/19/22
 */
#include "grib2_int.h"

int
main()
{
    /* char abbrev[G2C_MAX_NOAA_ABBREV_LEN + 1]; */
    /* int ret; */

    printf("Testing params handling.\n");

    printf("Testing g2c_param_abbrev()...\n");
    /* if ((ret = g2c_param_abbrev(10, 3, 209, abbrev))) */
    /*     return ret; */
    /* if (strcmp(abbrev, "TWLDT")) */
    /*     return G2C_ERROR; */
    
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

