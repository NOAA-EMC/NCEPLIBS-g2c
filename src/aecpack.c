/** @file
 * @brief Pack array of float/double using AEC/CCSDS compression.
 * @author Eric Engle @date 2023-09-10
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2023-09-10 | Engle | Initial; Adapted from jpcpack.c.
 */

#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "grib2_int.h"

/** 
 * This internal function packs up a float or double array into a
 * AEC/CCSDS code stream.
 *
 * @param fld Pointer to the float or double data values to pack.
 * @param fld_is_double If non-zero, then fld points to array of
 * doubles, otherwise an array of floats.
 * @param width The number of points in the x direction.
 * @param height The number of points in the y direction.
 * @param idrstmpl Contains the array of values for Data
 * Representation Template [Table
 * 5.40](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml)
 * or 5.40000. May be modified in this function.
 * @param cpack A pointer that will get the packed data field. Must be
 * allocated before this function is called. Pass the allocated size
 * in the lcpack parameter.
 * @param lcpack Pointer that gets the length of packed field in
 * cpack. This must also be set by the calling function to the size
 * available in cpack.
 * @param verbose If non-zero, error messages will be printed in case
 * of error. Otherwise, error codes will be return but no error
 * messages printed. Calls to the original g2c API may cause error
 * messages to be printed in case of error. For the new g2c_ API, no
 * error messages will be printed - instead an error code will be
 * returned. Call g2c_strerror() to get the error message for any
 * error code.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EJPEG Error encoding/decoding JPEG data.
 *
 * @author Eric Engle 
 */
void aecpack(float *fld, g2int width, g2int height, g2int *idrstmpl,
             unsigned char *cpack, g2int *lcpack)
{
    int iret;
    int ctemplen;
    g2int *ifld = NULL;
    g2int j;
    g2int imin, imax;
    g2int maxdiff, maxnum, nbits, ndpts, nbytes;
    g2int ccsds_flags, ccsds_block_size, ccsds_rsi;
    float bscale, dscale, rmax, rmin, temp;
    static float alog2 = ALOG2; /* ln(2.0) */
    unsigned char *ctemp;

    ctemplen = 0;
    iret = 0;
    ccsds_flags = 0;
    ccsds_block_size = 0;
    ccsds_rsi = 0;

    ndpts = width * height;
    bscale = int_power(2.0, -idrstmpl[1]);
    dscale = int_power(10.0, idrstmpl[2]); 

    /* Set nbits accordingly. */
    if (idrstmpl[3] <= 0 || idrstmpl[3] > 31)
        nbits = 0;
    else
        nbits = idrstmpl[3];

    /* Find max and min values in the data. */
    rmax = fld[0];
    rmin = fld[0];
    for (j = 1; j < ndpts; j++)
    {
        if (fld[j] > rmax) rmax = fld[j];
        if (fld[j] < rmin) rmin = fld[j];
    }
    //printf("aecpack:, ndpts = %d\n",ndpts);
    //printf("aecpack:, rmin, rmax = %g, %g\n",rmin,rmax);

    /* Allocate memory for scaled data. */
    ifld = malloc(ndpts * sizeof(g2int));

    /* If max and min values are not equal, pack up field. If they are
     * equal, we have a constant field, and the reference value (rmin)
     * is the value for each point in the field and set nbits to 0. */
    if (rmin != rmax)
    {

        /* Determine which algorithm to use based on user-supplied
	 * binary scale factor and number of bits. */
        if (nbits == 0 && idrstmpl[1] == 0)
        {

            /* No binary scaling and calculate minumum number of bits
	     * in which the data will fit. */
            imin = (g2int)rint(rmin * dscale);
            imax = (g2int)rint(rmax * dscale);
            maxdiff = imax - imin;
            temp = log((double)(maxdiff + 1)) / alog2;
            nbits = (g2int)ceil(temp);
            rmin = (float)imin;
            /* Scale data */
            for(j = 0; j < ndpts; j++)
                ifld[j] = (g2int)rint(fld[j] * dscale) - imin;
        }
        else if (nbits != 0 && idrstmpl[1] == 0)
        {

            /* Use minimum number of bits specified by user and adjust
	     * binary scaling factor to accomodate data. */
            rmin = rmin * dscale;
            rmax = rmax * dscale;
            maxnum = int_power(2.0, nbits) - 1;
            temp = log(maxnum / (rmax - rmin)) / alog2;
            idrstmpl[1] = (g2int)ceil(-1.0 * temp);
            bscale = int_power(2.0, -idrstmpl[1]);
            /* Scale data */
            for (j = 0; j < ndpts; j++)
                ifld[j] = (g2int)rint(((fld[j] * dscale) - rmin) * bscale);
        }
        else if (nbits == 0 && idrstmpl[1] != 0)
        {

            /* Use binary scaling factor and calculate minumum number
	     * of bits in which the data will fit. */
            rmin = rmin * dscale;
            rmax = rmax * dscale;
            maxdiff = (g2int)rint((rmax - rmin) * bscale);
            temp = log((double)(maxdiff + 1)) / alog2;
            nbits = (g2int)ceil(temp);
            /* Scale data */
            for (j = 0; j < ndpts; j++)
                ifld[j] = (g2int)rint(((fld[j] * dscale) - rmin) * bscale);
        }
        else if (nbits != 0 && idrstmpl[1] != 0)
        {

            /* Use binary scaling factor and use minumum number of
	     * bits specified by user. Dangerous - may loose
	     * information if binary scale factor and nbits not set
	     * properly by user. */
            rmin = rmin * dscale;
            /* Scale data */
            for (j = 0; j < ndpts; j++)
                ifld[j] = (g2int)rint(((fld[j] * dscale) - rmin) * bscale);
        }


        /* Pack data into full octets, then do PNG encode and
         * calculate the length of the packed data in bytes. */
        nbytes = (nbits + 7) / 8;
	//printf("aecpack: ndpts, nbytes = %d, %d\n",ndpts, nbytes);
        ctemp = calloc(ndpts, nbytes);
	ctemplen = ndpts*nbytes;
        sbits(ctemp, ifld, 0, nbytes*8, 0, ndpts);

        /* Pack */
        ccsds_flags = idrstmpl[5];
        ccsds_block_size = idrstmpl[6];
        ccsds_rsi = idrstmpl[7];
        iret = enc_aec(ctemp, ctemplen, nbits, ccsds_flags, ccsds_block_size, ccsds_rsi, cpack, lcpack);
        if (iret < 0)
        {
            if (verbose) printf("aecpack: ERROR Packing AEC = %d\n",iret);
            nbits = 0;
            *lcpack = 0
        }

        *lcpack = iret;
        free(ctemp);

    }
    else
    {
        nbits = 0;
        *lcpack = 0;
    }

    // Set values in idrstmpl
    mkieee(&rmin, idrstmpl, 1);   /* ensure reference value is IEEE format. */
    idrstmpl[3] = nbits;
    idrstmpl[5] = ccsds_flags;
    idrstmpl[6] = ccsds_block_size;
    idrstmpl[7] = ccsds_rsi;
}
