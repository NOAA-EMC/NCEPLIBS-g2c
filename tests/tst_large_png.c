/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the PNG decode function on a large test file.
 *
 * Alyson Stahl 11/21/24
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>

#define TEST_FILE "data/ref_large_png.grib2"

int
main()
{
    printf("Testing dec_png() on large test file...\n");
    {
        float *data;
        int g2cid, num_data_points;
        int ret = G2C_NOERROR;

        /* Open the data file. */
        if ((ret = g2c_open(TEST_FILE, 0, &g2cid)))
            return ret;

        /* Get the size of the data from message 0, product 0. */
        if ((ret = g2c_get_prod(g2cid, 0, 0, &num_data_points, NULL)))
            return ret;

        /* Allocate storage for the data. */
        if (!(data = malloc(num_data_points * sizeof(float))))
            return G2C_ERROR;

        /* Get the data from message 0, product 0. */
        if ((ret = g2c_get_prod(g2cid, 0, 0, NULL, data)))
            return ret;

        /* Close the data file. */
        if ((ret = g2c_close(g2cid)))
            return ret;

        /* Free the memory allocated to hold the data. */
        free(data);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
