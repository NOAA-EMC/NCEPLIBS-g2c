/* This is a test for the NCEPLIBS-g2c project.
 *
 * This test is for the internal functions used by g2c_degrib2()
 * function.
 *
 * Ed Hartnett 11/16/22
 */
#include "grib2_int.h"

#define FILE_NAME "tst_degrib2.txt"
#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"
#define REF_FILE "ref_gdaswave.degrib2.txt"
#define DEGRIB2_FILE "gdaswave.t00z.wcoast.0p16.f000.degrib2"
#define REF_INDEX_FILE "ref_gdaswave.t00z.wcoast.0p16.f000.grb2index"
#define TEST_INDEX_FILE "tst_gdaswave.t00z.wcoast.0p16.f000.grb2index"
#define FTP_FILE "WW3_Regional_US_West_Coast_20220718_0000.grib2"
#define REF_FTP_INDEX_FILE "ref_WW3_Regional_US_West_Coast_20220718_0000.grb2index"
#define FTP_DEGRIB2_FILE "WW3_Regional_US_West_Coast_20220718_0000.degrib2"
#define REF_FTP_DEGRIB2_FILE "ref_WW3_Regional_US_West_Coast_20220718_0000.degrib2"

#define MAX_LINE_LEN 256
#define MAX_VALUE_LEN 25
#define NUM_MATCHING 5
#define FTP_NUM_MSG 688

int
main()
{
    printf("Testing g2c degrib2 internal functions.\n");
    printf("Testing g2c_get_level_desc()...");
    {
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
