/* This is a test for the NCEPLIBS-g2c project.
 *
 * This test is for the g2c_degrib2() function, which prints a summary
 * of the GRIB2 file.
 *
 * Ed Hartnett 9/17/22
 */
#include "g2ctest.h"
#include "grib2_int.h"
#include <libgen.h>

#define FILE_NAME "tst_degrib2.txt"
#define WAVE_FILE "data/gdaswave.t00z.wcoast.0p16.f000.grib2"
#define REF_FILE "data/ref_gdaswave.t00z.wcoast.0p16.f000.grib2.degrib2"
#define DEGRIB2_FILE "gdaswave.t00z.wcoast.0p16.f000.degrib2"
#define REF_INDEX_FILE "data/ref_gdaswave.t00z.wcoast.0p16.f000.grb2index"
#define TEST_INDEX_FILE "tst_gdaswave.t00z.wcoast.0p16.f000.grb2index"

/* The first message of the file has the following degrib2 output in the g2 project:

 GRIB MESSAGE  1  starts at 1

  SECTION 0:  0 2 15254
  SECTION 1:  7 0 2 1 1 2021 11 30 0 0 0 0 1
  Contains  0  Local Sections  and  1  data fields.

  FIELD  1
  SECTION 0:  0 2
  SECTION 1:  7 0 2 1 1 2021 11 30 0 0 0 0 1
  SECTION 3:  0 36391 0 0 0
  GRID TEMPLATE 3. 0 :  6 0 0 0 0 0 0 241 151 0 0 50000000 210000000 48 25000000 250000000 166667 166667 0
  NO Optional List Defining Number of Data Points.
  PRODUCT TEMPLATE 4. 0: ( PARAMETER = WIND     0 2 1 )  2 1 2 0 11 0 0 1 0 1 0 1 255 0 0
  FIELD: WIND     Surface valid  0 hour after 2021113000:00:00
  NO Optional Vertical Coordinate List.
  Num. of Data Points =  11041    with BIT-MAP  0
  DRS TEMPLATE 5. 40 :  1092616192 0 2 11 0 0 255
  Data Values:
  Num. of Data Points =  11041   Num. of Data Undefined = 0
( PARM= WIND ) :  MIN=               0.09999999 AVE=               5.64625025 MAX=              16.43000031
*/

int
main()
{
    printf("Testing g2c degrib2 function.\n");
#ifdef JPEG
    printf("Testing g2c_degrib2() on file %s...", WAVE_FILE);
    {
        int g2cid;
        int ret;

        if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
            return ret;
        if ((ret = g2c_degrib2(g2cid, FILE_NAME)))
            return ret;
        if ((ret = g2c_close(g2cid)))
            return ret;

        if ((ret = compare_degrib2_files2(FILE_NAME, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
    printf("Testing g2c_open_index() to make a degrib2 file...");
    {
        int g2cid;
        int num_msg;
        int ret;

        /* g2c_set_log_level(4); */
        /* Open the data file using the index file. */
        if ((ret = g2c_open_index(WAVE_FILE, REF_INDEX_FILE, 0, &g2cid)))
            return ret;

        /* Check some stuff. */
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 19)
            return G2C_ERROR;

        /* Output a degrib2 file. */
        if ((ret = g2c_degrib2(g2cid, DEGRIB2_FILE)))
            return ret;

        /* Close the data file. */
        if ((ret = g2c_close(g2cid)))
            return ret;

        /* Compare the degrib2 output to our reference file. */
        if ((ret = compare_degrib2_files2(DEGRIB2_FILE, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
    printf("Testing g2c_write_index() make an index and then to make a degrib2 file from it...");
    {
        int g2cid;
        int num_msg;
        int ret;

        /* g2c_set_log_level(10); */
        /* Open the data file using the index file. */
        if ((ret = g2c_open(WAVE_FILE, 0, &g2cid)))
            return ret;

        /* Check some stuff. */
        if ((ret = g2c_inq(g2cid, &num_msg)))
            return ret;
        if (num_msg != 19)
            return G2C_ERROR;

        /* Write an index file. */
        if ((ret = g2c_write_index(g2cid, G2C_CLOBBER, TEST_INDEX_FILE)))
            return ret;

        /* Close the data file. */
        if ((ret = g2c_close(g2cid)))
            return ret;

        /* Reopen the data file, using the index we just generated. */
        if ((ret = g2c_open_index(WAVE_FILE, TEST_INDEX_FILE, 0, &g2cid)))
            return ret;

        /* Output a degrib2 file. */
        if ((ret = g2c_degrib2(g2cid, DEGRIB2_FILE)))
            return ret;

        /* Close the data file. */
        if ((ret = g2c_close(g2cid)))
            return ret;

        /* Compare the degrib2 output to our reference file. */
        if ((ret = compare_degrib2_files2(DEGRIB2_FILE, REF_FILE)))
            return ret;
    }
    printf("ok!\n");
#endif /* JPEG */
    printf("SUCCESS!\n");
    return 0;
}
