/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the complex compression functions.
 *
 * Ed Hartnett 11/2/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define DATA_LEN 4
#define PACKED_LEN 200
#define G2C_ERROR 2

/* Prototypes we are testing. */
int comunpack(unsigned char *cpack, g2int lensec, g2int idrsnum,
              g2int *idrstmpl, g2int ndpts, g2float *fld);

int
main()
{
    printf("Testing com functions.\n");
    printf("Testing compack()/comunpack() calls...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        g2float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        g2float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-2.shtml
         * for the template meaning. */
        g2int idrstmpl[16] = {
            0, /* reference value (R) (IEEE 32-bit floating-point value) */
            1, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            8, /* Number of bits used for each packed value for simple packing, or for each group reference value for complex packing or spatial differencing */
            0, /* Type of original field values (see Code Table 5.1) */
            0, /* Group splitting method used (see Code Table 5.4) */
            0, /* Missing value management used (see Code Table 5.5) */
            0, /* Primary missing value substitute */
            0, /* Secondary missing value substitute */
            1, /* NG ― number of groups of data values into which field is split */
            16, /* Reference for group widths (see Note 12) */
            8, /* Number of bits used for the group widths (after the reference value in octet 36 has been removed) */
            4, /* Reference for group lengths (see Note 13) */
            0, /* Length increment for the group lengths (see Note 14) */
            0, /* True length of last group */
            8 /* Number of bits used for the scaled group lengths (after subtraction of the reference value given in octets 38-41 and division by the length increment given in octet 42) */
            };
        g2int idrsnum = 2;
        int i;

        /* Pack the data. */
        compack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);

        /* Unpack the data. */
        if (comunpack(cpack, len, idrsnum, idrstmpl, ndpts, fld_in))
            return G2C_ERROR;

        for (i = 0; i < DATA_LEN; i++)
        {
            /* printf("%g %g\n", fld[i], fld_in[i]); */
            if (fld[i] != fld_in[i])
        	return G2C_ERROR;
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
