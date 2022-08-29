/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the complex compression functions.
 *
 * Ed Hartnett 11/2/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define DATA_LEN 4
#define PACKED_LEN 200

/* Prototypes we are testing. */
int comunpack(unsigned char *cpack, g2int lensec, g2int idrsnum,
              g2int *idrstmpl, g2int ndpts, float *fld);
void cmplxpack(float *fld, g2int ndpts, g2int idrsnum, g2int *idrstmpl,
               unsigned char *cpack, g2int *lcpack);

int
main()
{
    printf("Testing com functions.\n");
    printf("Testing compack()/comunpack() with table 5.2...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
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
    printf("Testing compack()/comunpack() with table 5.3...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-3.shtml
         * for the template meaning. */
        g2int idrstmpl[18] = {
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
            8, /* Number of bits used for the scaled group lengths (after subtraction of the reference value given in octets 38-41 and division by the length increment given in octet 42) */
            1, /* Order of spatial difference (see Code Table 5.6) */
            0  /* Number of octets required in the data section to specify extra descriptors needed for spatial differencing (octets 6-ww in data template 7.3) */
            };
        g2int idrsnum = 3;
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
    printf("Testing misspack()/comunpack() calls...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        g2int old_int_val;
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
            1, /* Missing value management used (see Code Table 5.5) */
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

        /* Change the missing value management field to something invalid. */
        old_int_val = idrstmpl[6];
        idrstmpl[6] = 3;
        
        /* This won't work, bad missing value management value. */
        misspack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);
        if (lcpack != -1)
            return G2C_ERROR;

        /* Fix the missing value management field. */
        idrstmpl[6] = old_int_val;

        /* Pack the data. */
        misspack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);

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
    printf("Testing misspack()/comunpack() calls with missopt = 2, no binary scaling...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-2.shtml
         * for the template meaning. */
        g2int idrstmpl[16] = {
            0, /* reference value (R) (IEEE 32-bit floating-point value) */
            0, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            8, /* Number of bits used for each packed value for simple packing, or for each group reference value for complex packing or spatial differencing */
            0, /* Type of original field values (see Code Table 5.1) */
            0, /* Group splitting method used (see Code Table 5.4) */
            2, /* Missing value management used (see Code Table 5.5) */
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
        misspack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);

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
    printf("Testing misspack()/comunpack() with table 5.3...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-3.shtml
         * for the template meaning. */
        g2int idrstmpl[18] = {
            0, /* reference value (R) (IEEE 32-bit floating-point value) */
            1, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            8, /* Number of bits used for each packed value for simple packing, or for each group reference value for complex packing or spatial differencing */
            0, /* Type of original field values (see Code Table 5.1) */
            0, /* Group splitting method used (see Code Table 5.4) */
            1, /* Missing value management used (see Code Table 5.5) */
            0, /* Primary missing value substitute */
            0, /* Secondary missing value substitute */
            1, /* NG ― number of groups of data values into which field is split */
            16, /* Reference for group widths (see Note 12) */
            8, /* Number of bits used for the group widths (after the reference value in octet 36 has been removed) */
            4, /* Reference for group lengths (see Note 13) */
            0, /* Length increment for the group lengths (see Note 14) */
            0, /* True length of last group */
            8, /* Number of bits used for the scaled group lengths (after subtraction of the reference value given in octets 38-41 and division by the length increment given in octet 42) */
            1, /* Order of spatial difference (see Code Table 5.6) */
            0  /* Number of octets required in the data section to specify extra descriptors needed for spatial differencing (octets 6-ww in data template 7.3) */
            };
        g2int idrsnum = 3;
        int i;

        /* Pack the data. */
        misspack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);

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
    printf("Testing misspack()/comunpack() with table 5.3 with second order spacial difference and different data...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {0.0, 0.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        /* See
         * https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-3.shtml
         * for the template meaning. */
        g2int idrstmpl[18] = {
            0, /* reference value (R) (IEEE 32-bit floating-point value) */
            1, /* Binary scale factor (E) */
            1, /* Decimal scale factor (D) */
            8, /* Number of bits used for each packed value for simple packing, or for each group reference value for complex packing or spatial differencing */
            0, /* Type of original field values (see Code Table 5.1) */
            0, /* Group splitting method used (see Code Table 5.4) */
            1, /* Missing value management used (see Code Table 5.5) */
            0, /* Primary missing value substitute */
            0, /* Secondary missing value substitute */
            1, /* NG ― number of groups of data values into which field is split */
            16, /* Reference for group widths (see Note 12) */
            8, /* Number of bits used for the group widths (after the reference value in octet 36 has been removed) */
            4, /* Reference for group lengths (see Note 13) */
            0, /* Length increment for the group lengths (see Note 14) */
            0, /* True length of last group */
            8, /* Number of bits used for the scaled group lengths (after subtraction of the reference value given in octets 38-41 and division by the length increment given in octet 42) */
            2, /* Order of spatial difference (see Code Table 5.6) */
            0  /* Number of octets required in the data section to specify extra descriptors needed for spatial differencing (octets 6-ww in data template 7.3) */
            };
        g2int idrsnum = 3;
        int i;

        /* Pack the data. */
        misspack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);

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
    printf("Testing cmplxpack()/comunpack() calls (expect and ignore error messages)...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        g2int old_int_val;
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
            1, /* Missing value management used (see Code Table 5.5) */
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

        /* Try with wrong missing value management flag. */
        old_int_val = idrstmpl[6];
        idrstmpl[6] = 3;
        cmplxpack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);
        if (lcpack != -1)
            return G2C_ERROR;
        idrstmpl[6] = old_int_val;

        /* Pack the data. */
        cmplxpack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);

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
    printf("Testing cmplxpack()/comunpack() calls without missing value management...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {1.0, 2.0, 3.0, 0.0};
        float fld_in[DATA_LEN];
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
        cmplxpack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);

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
    printf("Testing cmplxpack()/comunpack() calls (expect and ignore error messages)...");
    {
        g2int len = PACKED_LEN, ndpts = DATA_LEN;
        float fld[DATA_LEN] = {2.0, 2.0, 2.0, 2.0};
        float fld_in[DATA_LEN];
        unsigned char cpack[PACKED_LEN];
        g2int lcpack = PACKED_LEN;
        g2int old_int_val;
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
            1, /* Missing value management used (see Code Table 5.5) */
            2, /* Primary missing value substitute */
            3, /* Secondary missing value substitute */
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

        /* Try with wrong missing value management flag. */
        old_int_val = idrstmpl[6];
        idrstmpl[6] = 3;
        cmplxpack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);
        if (lcpack != -1)
            return G2C_ERROR;
        idrstmpl[6] = old_int_val;

        /* Pack the data. */
        cmplxpack(fld, ndpts, idrsnum, idrstmpl, cpack, &lcpack);

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
