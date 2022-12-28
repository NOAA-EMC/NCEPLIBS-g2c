/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c metadata comparison function.
 *
 * Ed Hartnett 12/28/22
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define WAVE_FILE "data/gdaswave.t00z.wcoast.0p16.f000.grib2"
#define GDAS_FILE "data/gdas.t12z.pgrb2.1p00.anl.grib2"

int
main()
{
    printf("Testing g2c_metacmp\n");
    printf("testing g2c_metacmp on file %s...", WAVE_FILE);
    {
        int g2cid1, g2cid2;
        
        if (g2c_open(WAVE_FILE, 0, &g2cid1))
            return G2C_ERROR;
        if (g2c_open(WAVE_FILE, 0, &g2cid2))
            return G2C_ERROR;
        if (g2c_close(g2cid1))
            return G2C_ERROR;
        if (g2c_close(g2cid2))
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
