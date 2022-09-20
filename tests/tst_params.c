/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2cparams.c.
 *
 * Ed Hartnett 9/19/22
 */
#include "grib2_int.h"

int
main()
{
    printf("Testing params handling.\n");

    printf("Testing g2c_param_abbrev()...");
    {
        char abbrev[G2C_MAX_NOAA_ABBREV_LEN + 1];
        int ret;

        /* This will work. */
        if ((ret = g2c_param_abbrev(0, 3, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRES"))
            return G2C_ERROR;
        
        /* This will succeed, but accomplish nothing. */
        if ((ret = g2c_param_abbrev(0, 3, 0, NULL)))
            return ret;
        
        /* This will fail. */
        if (g2c_param_abbrev(0, 3000, 0, abbrev) != G2C_ENOPARAM)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing g2c_param_g1tog2()...");
    {
        int g2disc, g2cat, g2num;
        int ret;
        
        /* This will work. */
        if ((ret = g2c_param_g1tog2(1, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;

        /* This will work but do nothing. */
        if ((ret = g2c_param_g1tog2(1, 2, NULL, NULL, NULL)))
            return ret;

        /* This will fail. */
        if (g2c_param_g1tog2(1, 2000, &g2disc, &g2cat, &g2num) != G2C_ENOPARAM)
            return G2C_ERROR;
        
    }
    printf("ok!\n");
    printf("Testing g2c_param_g2tog1()...");
    {
        int g1num, g1ver;
        int ret;
        
        g2c_set_log_level(10);

        /* This will work. */
        if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 1 || g1ver != 2)
            return G2C_ERROR;

        /* This will work but do nothing. */
        if ((ret = g2c_param_g2tog1(0, 3, 0, NULL, NULL)))
            return ret;

        /* This will fail. */
        if (g2c_param_g2tog1(0, 2000, 0, &g1num, &g1ver) != G2C_ENOPARAM)
            return G2C_ERROR;
        
    }
    printf("ok!\n");
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

