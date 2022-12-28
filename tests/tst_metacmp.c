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
    int g2cid1, g2cid2;
    
    printf("Testing g2c_metacmp\n");

    /* Open test file. */
    if (g2c_open(WAVE_FILE, 0, &g2cid1))
        return G2C_ERROR;
    
    printf("comparing file %s to itself...", WAVE_FILE);
    {
        if (g2c_open(WAVE_FILE, 0, &g2cid2))
            return G2C_ERROR;
        if (g2c_metadata_cmp(g2cid1, g2cid2))
            return G2C_ERROR;
        if (g2c_close(g2cid2))
            return G2C_ERROR;
    }
    printf("ok!\n");
#ifdef FTP_TEST_FILES    
    printf("comparing file %s to file %s...", WAVE_FILE, GDAS_FILE);
    {
        if (g2c_open(GDAS_FILE, 0, &g2cid2))
            return G2C_ERROR;
        if (!g2c_metadata_cmp(g2cid1, g2cid2))
            return G2C_ERROR;
        if (g2c_close(g2cid2))
            return G2C_ERROR;
    }
    printf("ok!\n");
#endif /* FTP_TEST_FILES */
    
    if (g2c_close(g2cid1))
        return G2C_ERROR;
    
    printf("SUCCESS!\n");
    return 0;
}
