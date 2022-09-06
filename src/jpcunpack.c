/** @file
 * @brief Unpack a data field that was packed into a JPEG2000 code
 * stream
 * @author Stephem Gilbert @date 2003-08-27
 */
#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

/**
 * Unpack JPEG2000 compressed data into an array of floats, using info
 * from the GRIB2 Data Representation [Template
 * 5.40](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml)
 * or 5.40000.
 *
 * @param cpack The packed data.
 * @param len The length of the packed data.
 * @param idrstmpl Pointer to array of values for Data Representation
 * [Template
 * 5.40](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml)
 * or 5.40000.
 * @param ndpts The number of data values to unpack.
 * @param fld A pointer that gets the unpacked data values.
 * @param fld_is_double Non-zero if the data are to be unpacked into a
 * double array, otherwise data will be unpacked into a float array.
 *
 * @return 0 for success, 1 for memory allocation error.
 *
 * @author Stephem Gilbert @date 2003-08-27
 * @author Ed Hartnett
 */
static g2int
jpcunpack_int(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
	      void *fld, int fld_is_double)
{
    g2int *ifld;
    g2int j, nbits;
    float ref, bscale, dscale;
    float *ffld = fld;
    double *dfld = fld;

    LOG((2, "len %ld ndpts %ld fld_is_double %d", len, ndpts, fld_is_double));

    rdieee(idrstmpl, &ref, 1);
    bscale = int_power(2.0, idrstmpl[1]);
    dscale = int_power(10.0, -idrstmpl[2]);
    nbits = idrstmpl[3];

    /* If nbits equals 0, we have a constant field where the reference
     * value is the data value at each gridpoint. */
    if (nbits != 0)
    {
        if (!(ifld = calloc(ndpts, sizeof(g2int))))
        {
            fprintf(stderr, "Could not allocate space in jpcunpack.\n  Data field NOT upacked.\n");
            return G2_JPCUNPACK_MEM;
        }
        dec_jpeg2000((char *)cpack, len, ifld);
	if (fld_is_double)
	{
	    for (j = 0; j < ndpts; j++)
		dfld[j] = (((float)ifld[j] * bscale) + ref) * dscale;
	}
	else
	{
	    for (j = 0; j < ndpts; j++)
		ffld[j] = (((float)ifld[j] * bscale) + ref) * dscale;
	}
        free(ifld);
    }
    else
    {
	if (fld_is_double)
	{
	    for (j = 0; j < ndpts; j++)
		dfld[j] = ref;
	}
	else
	{
	    for (j = 0; j < ndpts; j++)
		ffld[j] = ref;
	}
    }

    return G2_NO_ERROR;
}

/**
 * Unpack JPEG2000 compressed data into an array of floats, using info
 * from the GRIB2 Data Representation [Template
 * 5.40](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml)
 * or 5.40000.
 *
 * @param cpack The packed data.
 * @param len The length of the packed data.
 * @param idrstmpl Pointer to array of values for Data Representation
 * [Template
 * 5.40](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml)
 * or 5.40000.
 * @param ndpts The number of data values to unpack.
 * @param fld A pointer that gets the unpacked data values as an array
 * of float.
 *
 * @return 0 for success, 1 for memory allocation error.
 *
 * @author Stephem Gilbert @date 2003-08-27
 * @author Ed Hartnett
 */
g2int
jpcunpack(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
          float *fld)
{
    return jpcunpack_int(cpack, len, idrstmpl, ndpts, fld, 0);
}

/**
 * Unpack JPEG2000 compressed data into an array of doubles, using
 * info from the GRIB2 Data Representation [Template
 * 5.40](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml)
 * or 5.40000.
 *
 * @param cpack The packed data.
 * @param len The length of the packed data.
 * @param idrstmpl Pointer to array of values for Data Representation
 * [Template
 * 5.40](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml)
 * or 5.40000.
 * @param ndpts The number of data values to unpack.
 * @param fld A pointer that gets the unpacked data values as an array
 * of double.
 *
 * @return 0 for success, 1 for memory allocation error.
 *
 * @author Ed Hartnett @date 2022-08-12
 */
g2int
jpcunpackd(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
	   double *fld)
{
    return jpcunpack_int(cpack, len, idrstmpl, ndpts, fld, 1);
}
