/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2cparams.c.
 *
 * Ed Hartnett 9/19/22
 */
#include "grib2_int.h"

int
main()
{
    char abbrev[G2C_MAX_NOAA_ABBREV_LEN + 1];
    int ret;

    printf("Testing params handling.\n");

    g2c_set_log_level(10);
    printf("Testing g2c_param_abbrev()...\n");
    if ((ret = g2c_param_abbrev(0, 3, 0, abbrev)))
        return ret;
    if (strcmp(abbrev, "PRES"))
        return G2C_ERROR;
    
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

