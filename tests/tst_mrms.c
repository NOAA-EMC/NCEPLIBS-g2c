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

#define MRMS_FILE "data/MRMS_MultiSensor_QPE_24H_Pass2_00.00_20230621-110000.grib2"
#define LAT_LEN 3500
#define LON_LEN 7000
#define LATITUDE "Latitude"
#define LONGITUDE "Longitude"

int
main()
{
    printf("Testing g2c file functions with %s.\n", MRMS_FILE);
    printf("Testing g2c_inq_dim()...");
    {
        int g2cid;
        int num_msg;
        size_t len0;
        char dimname0[G2C_MAX_NAME + 1];
        size_t len1;
        char dimname1[G2C_MAX_NAME + 1];
        float lat[LAT_LEN];
        float lon[LON_LEN];
        /* int d; */

        /* Open GRIB2 file. */
	g2c_set_log_level(10);
        if (g2c_open(MRMS_FILE, 0, &g2cid))
            return G2C_ERROR;

        /* Find the number of messages. */
        if (g2c_inq(g2cid, &num_msg))
            return G2C_ERROR;
        printf("Number of messages: %d\n", num_msg);
        if (num_msg != 1)
            return G2C_ERROR;

        /* Find the dimensions of the product in the first message. */
        if (g2c_inq_dim(g2cid, 0, 0, 0, &len0, dimname0, lat))
            return G2C_ERROR;
        printf("len0 %ld dimname0 %s\n", len0, dimname0);
        printf("lat[0] = %f lat[%ld] = %f\n", lat[0], len0 - 1, lat[len0 - 1]);
        if (len0 != LAT_LEN || strcmp(dimname0, LATITUDE))
            return G2C_ERROR;
        if (lat[0] != 54995000 || lat[len0 - 1] != 20005000)
            return G2C_ERROR;

        if (g2c_inq_dim(g2cid, 0, 0, 1, &len1, dimname1, lon))
            return G2C_ERROR;
        if (len1 != LON_LEN || strcmp(dimname1, LONGITUDE))
            return G2C_ERROR;
        printf("len1 %ld dimname1 %s\n", len1, dimname1);
        printf("lon[0] = %f lon[%ld] = %f\n", lon[0], len1 - 1, lon[len1 - 1]);
        if (len1 != LON_LEN || strcmp(dimname1, LONGITUDE))
            return G2C_ERROR;
        if (lon[0] != 230004992 || lon[len1 - 1] != 160014992)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
