/* This is a test for the NCEPLIBS-g2c project. This test is for the
 * JPEG jasper library. It tests that jasper is not writing any
 * warnings to stdout.
 *
 * Ed Hartnett 10/26/23
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>

#define DATA_LEN 4
#define PACKED_LEN 200

int
main()
{
    printf("Testing JPEG functions.\n");
    /* g2c_set_log_level(10); */
    printf("Testing enc_jpeg2000()/dec_jpeg2000() call...");
    {
        unsigned char data[DATA_LEN] = {1, 2, 3, 4};
        g2int width = 2, height = 2, nbits = 4;
        g2int ltype = 0, ratio = 0, retry = 0, jpclen = PACKED_LEN;
        char outjpc[PACKED_LEN];
        g2int outfld[DATA_LEN];
        int i;
        int ret;

        /* Encode some data. */
        if ((ret = enc_jpeg2000(data, width, height, nbits, ltype,
                                ratio, retry, outjpc, jpclen)) < 0)
            return G2C_ERROR;

        /* Now decode it. */
        if ((ret = dec_jpeg2000(outjpc, jpclen, outfld)))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            if (outfld[i] != data[i])
                return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
