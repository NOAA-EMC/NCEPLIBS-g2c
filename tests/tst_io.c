/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2c I/O functions.
 *
 * Ed Hartnett 11/11/22
 */

#include "grib2_int.h"

#define WAVE_FILE "gdaswave.t00z.wcoast.0p16.f000.grib2"
#define TEST_FILE "tst_io.bin"

int
main()
{
    printf("Testing g2c I/O functions.\n");
    printf("Testing simple calls...\n");
    {
        FILE *f;
        int val = 42;
        int ret;

        /* Open the test file. */
        if (!(f = fopen(TEST_FILE, "wb")))
            return G2C_EFILE;

        /* Write 4 bytes. */
        if ((ret = g2c_file_be_int4(f, G2C_FILE_WRITE, &val)))
            return ret;

        /* Close file. */
        fclose(f);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
