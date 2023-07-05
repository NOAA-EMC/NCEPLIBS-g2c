/* This is a test for the NCEPLIBS-g2c project. This test is for the
 * g2c file functions on the GRIB2 file that's included in the
 * tests/data directory for testion,
 * gdaswave.t00z.wcoast.0p16.f000.grib2.
 *
 * Ed Hartnett 7/5/23
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define GDAS_FILE "data/gdaswave.t00z.wcoast.0p16.f000.grib2"

int
main()
{
    printf("Testing g2c file functions with %s.\n", GDAS_FILE);
    printf("Testing g2c_inq_dim()...");
    {
        int g2cid;
        int num_msg;
        int m;
        int ret;

        /* Open GRIB2 file. */
	g2c_set_log_level(10);
        if ((ret = g2c_open(GDAS_FILE, 0, &g2cid)))
            return ret;

        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 1)
            return ret;

    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
