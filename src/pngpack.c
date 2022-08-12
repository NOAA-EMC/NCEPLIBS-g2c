/** @file
 * @brief Function to pack data with PNG compression.
 * @author Stephen Gilbert @date 2003-08-27
 */
#include <stdlib.h>
#include <math.h>
#include "grib2_int.h"

/**
 * This internal function packs up float or double data into PNG image
 * format. This is called by pngpack() and pngpackd().
 *
 * After the data field is scaled, and the reference value is
 * subtracted out, it is treated as a grayscale image and passed to a
 * PNG encoder. It also fills in GRIB2 Data Representation Template
 * 5.41 or 5.40010 with the appropriate values.
 *
 * @param fld Pointer to array of float or double that contains the
 * data values to pack.
 * @param fld_is_double If non-zero, then fld is double, otherwise float.
 * @param width Number of points in the x direction.
 * @param height Number of points in the y direction.
 * @param idrstmpl Contains the array of values for Data
 * Representation
 * [Template 5.41](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml)
 * or 5.40010.
 * - 0 Reference value - ignored on input, set by pngpack routine.
 * - 1 Binary Scale Factor - used on input.
 * - 2 Decimal Scale Factor - used on input.
 * - 3 number of bits for each grayscale pixel value - ignored on
 input.
 * - 4 Original field type - currently ignored on input, set = 0 on
 output. Data values assumed to be reals.
 * @param cpack The packed data field.
 * @param lcpack length of packed field cpack.
 * @return void
 *
 * @author Ed Hartnett @date Aug 8, 2022
 */
static void
pngpack_int(void *fld, int fld_is_double, g2int width, g2int height, g2int *idrstmpl, 
	    unsigned char *cpack, g2int *lcpack)
{
    g2int *ifld = NULL;
    static float alog2 = ALOG2;       /*  ln(2.0) */
    g2int j, nbits, imin, imax, maxdif;
    g2int ndpts, nbytes;
    float bscale, dscale, rmax, rmin, temp;
    double rmaxd, rmind;
    unsigned char *ctemp;
    float *ffld = fld;
    double *dfld = fld;

    ndpts = width * height;
    bscale = int_power(2.0, -idrstmpl[1]);
    dscale = int_power(10.0, idrstmpl[2]);

    /* Find max and min values in the data. Either rmax and rmin will
     * be used (if fld_is_double is not true), or rmaxd and rmind will
     * be used (if fld_is_double is true). */
    rmaxd = dfld[0];
    rmind = dfld[0];
    rmax = ffld[0];
    rmin = ffld[0];
    if (fld_is_double)
    {
	for (j = 1; j < ndpts; j++)
	{
	    if (dfld[j] > rmaxd)
		rmaxd = dfld[j];
	    if (dfld[j] < rmind)
		rmind = dfld[j];
	}
	maxdif = (g2int)rint((rmaxd - rmind) * dscale * bscale);
    }
    else
    {
	for (j = 1; j < ndpts; j++)
	{
	    if (ffld[j] > rmax)
		rmax = ffld[j];
	    if (ffld[j] < rmin)
		rmin = ffld[j];
	}
	maxdif = (g2int)rint((rmax - rmin) * dscale * bscale);
    }

    /* If max and min values are not equal, pack up field. If they are
     * equal, we have a constant field, and the reference value (rmin)
     * is the value for each point in the field and set nbits to 0. */
    if (((fld_is_double && rmind != rmaxd) || (!fld_is_double && rmin != rmax)) && maxdif != 0)
    {
        ifld = malloc(ndpts * sizeof(g2int));

        /* Determine which algorithm to use based on user-supplied
         * binary scale factor and number of bits. */
        if (idrstmpl[1] == 0)
        {
            /* No binary scaling and calculate minumum number of bits
             * in which the data will fit. */
            imin = (g2int)rint((fld_is_double ? rmind : rmin) * dscale);
            imax = (g2int)rint((fld_is_double ? rmaxd : rmax) * dscale);
            maxdif = imax - imin;
            temp = log((double)(maxdif + 1)) / alog2;
            nbits = (g2int)ceil(temp);
            /*   scale data */
	    if (fld_is_double)
	    {
		rmind = (float)imin;
		for(j = 0; j < ndpts; j++)
		    ifld[j] = (g2int)rint(dfld[j] * dscale) - imin;
	    }
	    else
	    {
		rmin = (float)imin;
		for(j = 0; j < ndpts; j++)
		    ifld[j] = (g2int)rint(ffld[j] * dscale) - imin;
	    }
        }
        else
        {
            /* Use binary scaling factor and calculate minumum number
             * of bits in which the data will fit. */
	    if (fld_is_double)
	    {
		rmind = rmind * dscale;
		rmaxd = rmaxd * dscale;
		maxdif = (g2int)rint((rmaxd - rmind) * bscale);
	    }
	    else
	    {
		rmin = rmin * dscale;
		rmax = rmax * dscale;
		maxdif = (g2int)rint((rmax - rmin) * bscale);
	    }
            temp = log((double)(maxdif + 1)) / alog2;
            nbits = (g2int)ceil(temp);
            /*   scale data */
	    if (fld_is_double)
	    {
		for (j = 0; j < ndpts; j++)
		    ifld[j] = (g2int)rint(((dfld[j] * dscale) - rmind) * bscale);
	    }
	    else
	    {
		for (j = 0; j < ndpts; j++)
		    ifld[j] = (g2int)rint(((ffld[j] * dscale) - rmin) * bscale);
	    }		
        }

        /* Pack data into full octets, then do PNG encode and
         * calculate the length of the packed data in bytes. */
        if (nbits <= 8) 
            nbits = 8;
        else if (nbits <= 16) 
            nbits = 16;
        else if (nbits <= 24) 
            nbits = 24;
        else 
            nbits = 32;

        nbytes = (nbits / 8) * ndpts;
        ctemp = calloc(nbytes, 1);
        sbits(ctemp, ifld, 0, nbits, 0, ndpts);

        /* Encode data into PNG Format. */
        if ((*lcpack = (g2int)enc_png(ctemp, width, height, nbits,
                                      cpack)) <= 0)
            printf("pngpack: ERROR Packing PNG = %d\n", (int)*lcpack);
        
        free(ctemp);
    }
    else
    {
        nbits = 0;
        *lcpack = 0;
    }

    /* Fill in ref value and number of bits in Template 5.0. */
    if (fld_is_double)
	rmin = (float)rmind;
    mkieee(&rmin, idrstmpl, 1);   /* ensure reference value is IEEE format */
    idrstmpl[3] = nbits;
    idrstmpl[4] = 0;         /* original data were reals */
    
    if (ifld)
        free(ifld);
}

/**
 * This subroutine packs up a float data field into PNG image format. 
 *
 * After the data field is scaled, and the reference value is
 * subtracted out, it is treated as a grayscale image and passed to a
 * PNG encoder. It also fills in GRIB2 Data Representation Template
 * 5.41 or 5.40010 with the appropriate values.
 *
 * @param fld Pointer to array of float that contains the data values
 * to pack.
 * @param width Number of points in the x direction.
 * @param height Number of points in the y direction.
 * @param idrstmpl Contains the array of values for Data
 * Representation
 * [Template 5.41](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml)
 * or 5.40010.
 * - 0 Reference value - ignored on input, set by pngpack routine.
 * - 1 Binary Scale Factor - used on input.
 * - 2 Decimal Scale Factor - used on input.
 * - 3 number of bits for each grayscale pixel value - ignored on
 input.
 * - 4 Original field type - currently ignored on input, set = 0 on
 output. Data values assumed to be reals.
 * @param cpack The packed data field.
 * @param lcpack length of packed field cpack.
 *
 * @author Stephen Gilbert @date 2003-08-27
 * @author Ed Hartnett
 */
void
pngpack(float *fld, g2int width, g2int height, g2int *idrstmpl, 
        unsigned char *cpack, g2int *lcpack)
{
    pngpack_int(fld, 0, width, height, idrstmpl, cpack, lcpack);
}

/**
 * This subroutine packs up a double data field into PNG image format. 
 *
 * After the data field is scaled, and the reference value is
 * subtracted out, it is treated as a grayscale image and passed to a
 * PNG encoder. It also fills in GRIB2 Data Representation Template
 * 5.41 or 5.40010 with the appropriate values.
 *
 * @param fld Pointer to array of double that contains the data values
 * to pack.
 * @param width Number of points in the x direction.
 * @param height Number of points in the y direction.
 * @param idrstmpl Contains the array of values for Data
 * Representation
 * [Template 5.41](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml)
 * or 5.40010.
 * - 0 Reference value - ignored on input, set by pngpack routine.
 * - 1 Binary Scale Factor - used on input.
 * - 2 Decimal Scale Factor - used on input.
 * - 3 number of bits for each grayscale pixel value - ignored on
 input.
 * - 4 Original field type - currently ignored on input, set = 0 on
 output. Data values assumed to be reals.
 * @param cpack The packed data field.
 * @param lcpack length of packed field cpack.
 *
 * @author Ed Hartnett @date Aug 8, 2022
 */
void
pngpackd(double *fld, g2int width, g2int height, g2int *idrstmpl, 
	 unsigned char *cpack, g2int *lcpack)
{
    pngpack_int(fld, 1, width, height, idrstmpl, cpack, lcpack);
}

