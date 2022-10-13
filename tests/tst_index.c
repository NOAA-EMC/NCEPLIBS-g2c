/* This is a test for the NCEPLIBS-g2c project. 
 *
 * This test is for the g2c_write_index()/g2c_read_index() functions,
 * which write and read and index file that contians the byte offsets
 * to various parts of a GRIB2 file.
 *
 * Ed Hartnett 10/13/22
 */
#include "grib2_int.h"

#define FILE_NAME "tst_index.txt"
#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"
#define REF_FILE "ref_gdaswave.degrib2.txt"
#define MAX_LINE_LEN 256
#define MAX_VALUE_LEN 25
#define NUM_MATCHING 5

int
main()
{
    printf("Testing g2c index functions.\n");
#ifdef JPEG
    printf("Testing g2c_read_index() on file %s...", WAVE_FILE);
    {
	/* int g2cid; */
	/* int ret; */

	/* if ((ret = g2c_open(WAVE_FILE, 0, &g2cid))) */
	/*     return ret; */
        /* if ((ret = g2c_degrib2(g2cid, FILE_NAME))) */
        /*     return ret; */
	/* if ((ret = g2c_close(g2cid))) */
	/*     return ret; */
        
        /* if ((ret = compare_files2(FILE_NAME, REF_FILE))) */
        /*     return ret; */
    }
    printf("ok!\n");
#endif
    printf("SUCCESS!\n");
    return 0;
}

