/** @file
 * @brief Contains a function to unpack data packed with PNG
 * compression.
 * @author Stephen Gilbert @date 2003-08-27
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

/**
 * This subroutine unpacks a data field that was packed into a PNG
 * image format using info from the GRIB2 Data Representation Template
 * 5.41 or 5.40010.
 *
 * @param cpack The packed data field (character*1 array).
 * @param len The length of packed field cpack().
 * @param idrstmpl Pointer to array of values for Data Representation
 * [Template
 * 5.41](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml)
 * or 5.40010.
 * @param ndpts The number of data values to unpack.
 * @param fld Pointer that will get the unpacked data values.
 * @param fld_is_double If non-zero, then fld will get data as double,
 * otherwise float.
 *
 * @return 0 for success, 1 for memory allocation error.
 *
 * @author Stephen Gilbert, Ed Hartnett @date Aug 8, 2022
 */
static g2int
pngunpack_int(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
	      void *fld, int fld_is_double)
{
    g2int *ifld;
    g2int j, nbits, width, height;
    float ref, bscale, dscale;
    unsigned char *ctemp;
    float *ffld = fld;
    double *dfld = fld;

    LOG(("pngunpack_int len %ld ndpts %ld fld_is_double %d", len, ndpts, fld_is_double));

    rdieee(idrstmpl, &ref, 1);
    bscale = int_power(2.0, idrstmpl[1]);
    dscale = int_power(10.0, -idrstmpl[2]);
    nbits = idrstmpl[3];
    LOG(("bscale %g dscale %g nbits %ld", bscale, dscale, nbits));
    
    /* If nbits equals 0, we have a constant field where the reference
     * value is the data value at each gridpoint. */
    if (nbits != 0)
    {
        ifld = calloc(ndpts, sizeof(g2int));
        ctemp = calloc(ndpts * 4, 1);
        if (!ifld || !ctemp)
        {
            fprintf(stderr,"Could not allocate space in jpcunpack.\n  Data field NOT upacked.\n");
            return G2_JPCUNPACK_MEM;
        }
        dec_png(cpack, &width, &height, ctemp);
        gbits(ctemp, ifld, 0, nbits, 0, ndpts);
        for (j = 0; j < ndpts; j++)
	{
	    if (fld_is_double)
		dfld[j] = (((double)ifld[j] * bscale) + ref) * dscale;
	    else
		ffld[j] = (((float)ifld[j] * bscale) + ref) * dscale;
	}
        free(ctemp);
        free(ifld);
    }
    else
    {
        for (j = 0; j < ndpts; j++)
	{
	    if (fld_is_double)
		dfld[j] = ref;
	    else
		ffld[j] = ref;
	}
    }

    return 0;
}

/**
 * This subroutine unpacks a data field that was packed into a PNG
 * image format using info from the GRIB2 Data Representation Template
 * 5.41 or 5.40010.
 *
 * @param cpack The packed data field (character*1 array).
 * @param len length of packed field cpack().
 * @param idrstmpl Pointer to array of values for Data Representation
 * [Template 5.41](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml) or 5.40010.
 * @param ndpts The number of data values to unpack.
 * @param fld Contains the unpacked data values.
 *
 * @return 0 for success, 1 for memory allocation error.
 *
 * @author Stephen Gilbert @date 2003-08-27
 * @author Ed Hartnett
 */
g2int
pngunpack(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
          float *fld)
{
    return pngunpack_int(cpack, len, idrstmpl, ndpts, fld, 0);
}

/**
 * This subroutine unpacks a data field that was packed into a PNG
 * image format using info from the GRIB2 Data Representation Template
 * 5.41 or 5.40010.
 *
 * @param cpack The packed data field (character*1 array).
 * @param len length of packed field cpack().
 * @param idrstmpl Pointer to array of values for Data Representation
 * [Template 5.41](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml) or 5.40010.
 * @param ndpts The number of data values to unpack.
 * @param fld Contains the unpacked data values.
 *
 * @return 0 for success, 1 for memory allocation error.
 *
 * @author Ed Hartnett @date Aug 8, 2022
 */
g2int
pngunpackd(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
	   double *fld)
{
    return pngunpack_int(cpack, len, idrstmpl, ndpts, fld, 1);
}
