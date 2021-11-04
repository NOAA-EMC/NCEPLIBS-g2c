/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the spectral compression functions.
 *
 * Ed Hartnett 11/1/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define DATA_LEN 4
#define PACKED_LEN 200
#define G2C_ERROR 2

/* Prototypes we are testing. */
void specpack(g2float *fld, g2int ndpts, g2int JJ, g2int KK, g2int MM, 
              g2int *idrstmpl, unsigned char *cpack, g2int *lcpack);
g2int specunpack(unsigned char *cpack, g2int *idrstmpl, g2int ndpts, g2int JJ,
                 g2int KK, g2int MM, g2float *fld);

int
main()
{
    printf("Testing spec functions.\n");
    printf("Testing specpack()/specunpack() calls...");
    {
        g2int ndpts = DATA_LEN * 2;
        g2float fld[DATA_LEN * 2] = {1.0, 2.0, 3.0, 0.0, 1.0, 2.0, 3.0, 0.0};
        g2float fld_in[DATA_LEN * 2];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-51.shtml. */
        g2int idrstmpl[10] = {
            0, /* Reference value (R) (IEEE 32-bit floating-point value) */
            1, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            16, /* Number of bits used for each packed value (field width) */
            1, /* P― Laplacian scaling factor (expressed in 10-6 units) */
            1, /* Js ― pentagonal resolution parameter of the unpacked subset (see Note1) */
            1, /* Ks ― pentagonal resolution parameter of the unpacked subset (see Note1) */
            1, /* Ms ― pentagonal resolution parameter of the unpacked subset (see Note1) */
            1, /* Ts ― total number of values in the unpacked subset (see Note1) */
            1 /* Precision of the unpacked subset (see Code Table 5.7) */
        };
        g2int JJ = 1, KK = 2, MM = 3;
        int i;

        /* Pack the data. */
        specpack(fld, ndpts, JJ, KK, MM, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (specunpack(cpack, idrstmpl, ndpts, JJ, KK, MM, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN * 2; i++)
        {
            printf("%g %g\n", fld[i], fld_in[i]);
            if (fld[i] != fld_in[i])
        	return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
