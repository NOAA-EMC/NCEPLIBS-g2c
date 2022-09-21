/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2cparams.c.
 *
 * Ed Hartnett 9/21/22
 */
#include "grib2_int.h"

int
main()
{
    printf("Testing params handling for all g2c_param_g2tog1() calls.\n");

    printf("Testing all values with g2c_param_g2tog1()...");
    {
        int g1num, g1ver;
        int ret;
        
        /* This will work. */
        if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 1 || g1ver != 2)
            return G2C_ERROR;

        
    }
    printf("ok!\n");
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

