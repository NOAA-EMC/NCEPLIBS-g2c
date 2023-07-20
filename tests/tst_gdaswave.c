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
#define LAT_LEN 241
#define LON_LEN 151

int
main()
{
    printf("Testing g2c file functions with %s.\n", GDAS_FILE);
    printf("Testing g2c_inq_dim()...");
    {
        int g2cid;
        int num_msg;
        size_t len0;
        char dimname0[G2C_MAX_NAME + 1];
        float lat[LAT_LEN]
        /* float lon[LON_LEN]; */
        int d;

        /* Open GRIB2 file. */
	g2c_set_log_level(10);
        if (g2c_open(GDAS_FILE, 0, &g2cid))
            return G2C_ERROR;

        /* Find the number of messages. */
        if (g2c_inq(g2cid, &num_msg))
            return G2C_ERROR;
        printf("Number of messages: %d\n", num_msg);
        if (num_msg != 19)
            return G2C_ERROR;

        /* Find the dimensions of the product in the first message. */
        if (g2c_inq_dim(g2cid, 0, 0, 0, &len0, dimname0, lat))
            return G2C_ERROR;
        printf("len0 %ld dimname0 %s\n", len0, dimname0);
        for (d = 0; d < len0; d++)
            printf("lat[%d] = %f\n", d, lat[d]);

    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
