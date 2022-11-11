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
    printf("Testing simple calls with 4-byte ints...\n");
    {
        FILE *f;
        int val = 42;
        int neg_val = -42;
        int val_in;
        int ret;

        /* Open the test file. */
        if (!(f = fopen(TEST_FILE, "wb")))
            return G2C_EFILE;

        /* Write 4 bytes, thrice. */
        if ((ret = g2c_file_be_int4(f, G2C_FILE_WRITE, &val)))
            return ret;
        if ((ret = g2c_file_be_int4(f, G2C_FILE_WRITE, &neg_val)))
            return ret;
        if ((ret = g2c_file_be_int4(f, G2C_FILE_WRITE, &val)))
            return ret;

        /* Close file. */
        fclose(f);

        /* Reposition at start of file. */
        /* if (fseek(f, 0, SEEK_SET)) */
        /*     return G2C_EFILE; */

        /* Open the test file. */
        if (!(f = fopen(TEST_FILE, "rb")))
            return G2C_EFILE;

        /* Read three values. */
        if ((ret = g2c_file_be_int4(f, G2C_FILE_READ, &val_in)))
            return ret;
        if (val_in != val)
            return G2C_ERROR;
        if ((ret = g2c_file_be_int4(f, G2C_FILE_READ, &val_in)))
            return ret;
        if (val_in != neg_val)
            return G2C_ERROR;
        if ((ret = g2c_file_be_int4(f, G2C_FILE_READ, &val_in)))
            return ret;
        if (val_in != val)
            return G2C_ERROR;

        /* Close file. */
        fclose(f);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
