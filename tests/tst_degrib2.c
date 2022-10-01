/* This is a test for the NCEPLIBS-g2c project. 
 *
 * This test is for the g2c_degrib2() function, which prints a summary
 * of the GRIB2 file.
 *
 * Ed Hartnett 9/17/22
 */
#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define FILE_NAME "tst_degrib2.txt"
#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"

int
main()
{
    printf("Testing g2c degrib2 function.\n");
    printf("Testing g2c_degrib2() on file %s...", WAVE_FILE);
    {
	int g2cid;
	int ret;

	g2c_set_log_level(10);
	if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
	    return ret;
        if ((ret = g2c_write_grib2_index(g2cid, FILE_NAME)))
            return ret;
	if ((ret = g2c_close(g2cid)))
	    return ret;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
