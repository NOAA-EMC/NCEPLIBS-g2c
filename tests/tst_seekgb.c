/* This is a test for the NCEPLIBS-g2c project. This test is for
 * seekgb.c.
 *
 * Ed Hartnett 12/9/21
 */

#include <stdio.h>
#include "grib2_int.h"

#define GRIB2_FILE "data/gdaswave.t00z.wcoast.0p16.f000.grib2"
#define GRIB2_INDEX_FILE "data/gdaswave.t00z.wcoast.0p16.f000.grib2.idx"

int
main()
{
    printf("Testing seekgb.\n");
    printf("Testing simple seekgb() call...");
    {
        FILE *f;
        g2int lskip, lgrib;

        /* Open test data file. */
        if (!(f = fopen(GRIB2_FILE, "r")))
            return G2C_ERROR;

        /* Run seekgb() on data file. */
        seekgb(f, 0, 16, &lskip, &lgrib);

        /* Check results. */
        if (lgrib != 15254 || lskip)
            return G2C_ERROR;

        /* Close test data file. */
        fclose(f);
    }
    printf("ok!\n");
    printf("Testing seekgb() call on non-data file...");
    {
        FILE *f;
        g2int lskip, lgrib;

        /* Open test data file. */
        if (!(f = fopen(GRIB2_INDEX_FILE, "r")))
            return G2C_ERROR;

        /* Run seekgb() on non-data file. */
        seekgb(f, 0, 16, &lskip, &lgrib);

        /* Check results. */
        if (lgrib != 0)
            return G2C_ERROR;

        /* Close test data file. */
        fclose(f);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
