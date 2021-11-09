/** @file
 *
 * This C struct contains info on all the available GRIB2 Data
 * Representation Templates used in Section 5 (DRS). The information
 * decribing each template is stored in the drstemplate structure
 * defined below.
 *
 * Each Template has three parts:
 * 1. The number of entries in the template (mapdrslen).
 * 2. A map of the template (mapdrs), which contains the number of
 * octets in which to pack each of the template values.
 * 3. A logical value (needext) that indicates whether the
 * Template needs to be extended. In some cases the number of entries
 * in a template can vary depending upon values specified in the
 * "static" part of the template. (See Template 5.1 as an example.)
 *
 * @note Array mapdrs contains the number of octets in which the
 * corresponding template values will be stored. A negative value in
 * mapdrs is used to indicate that the corresponding template entry
 * can contain negative values. This information is used later when
 * packing (or unpacking) the template data values. Negative data
 * values in GRIB are stored with the left most bit set to one, and a
 * negative number of octets value in mapdrs indicates that this
 * possibility should be considered. The number of octets used to
 * store the data value in this case would be the absolute value of
 * the negative value in mapdrs.
 *
 * @author Stephen Gilbeert @date 2002-10-26
 */

#ifndef _drstemplates_H
#define _drstemplates_H

#include "grib2_int.h"

#define MAXDRSTEMP 9 /**< maximum number of templates */
#define MAXDRSMAPLEN 200 /**< maximum template map length */

/**
 * Stuct for GRIB2 Data Representation Section (DRS) template.
 */
struct drstemplate
{
    g2int template_num; /**< The number of entries in the template. */
    g2int mapdrslen; /**< Length of map of the template. */
    g2int needext; /**< Whether the Template needs to be extended. */
    g2int mapdrs[MAXDRSMAPLEN]; /**< A map of the template. */
};

/**
 * Stuct holding data for GRIB2 Data Representation Section (DRS)
 * template.
 */
const struct drstemplate templatesdrs[MAXDRSTEMP] =
{
    /** [5.0: Grid point data - Simple
     * Packing](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-0.shtml) */
    { 0, 5, 0, {4,-2,-2,1,1} },

    /** [5.2: Grid point data - Complex
     * Packing](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-2.shtml) */
    { 2, 16, 0, {4,-2,-2,1,1,1,1,4,4,4,1,1,4,1,4,1} },

    /** [5.3: Grid point data - Complex Packing and spatial
     * differencing](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-3.shtml) */
    { 3, 18, 0, {4,-2,-2,1,1,1,1,4,4,4,1,1,4,1,4,1,1,1} },

    /** [5.50: Spectral Data - Simple
     * Packing](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-50.shtml) */
    { 50, 5, 0, {4,-2,-2,1,4} },

    /** [5.51: Spherical Harmonics data - Complex
     * packing](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-51.shtml) */
    { 51, 10, 0, {4,-2,-2,1,-4,2,2,2,4,1} },

    /* 5.1: Matrix values at gridpoint - Simple packing.
     * Comment from Stephen Gilbert in 2021:
     *
     * This encoder/decoder was written in the early days of GRIB2
     * adoption as a standard. It was used to help WMO validate the
     * templates in the specification by sharing GRIB2 encoded message
     * with other organizations to verify that the data could be
     * transmitted and processed successfully.
     *
     * We did not have a use case for DRS template 5.1 at that time
     * and did not produce any GRIB2 messages using that template. It
     * appears that other organizations did not work on it as
     * well. The latest GRIB2 specification still includes the DRS
     * Template 5.1 definition, but there is a disclaimer to use it
     * with caution, since it has not yet been validated. I assume we
     * commented it out because it was not validated, which means it's
     * definition could possibly change during any validation attempts
     * in the future.
     */

    /* { 1, 15, 1, {4,-2,-2,1,1,1,4,2,2,1,1,1,1,1,1} }, */

    /** [5.40: Grid point data - JPEG2000
     * encoding](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-40.shtml) */
    { 40, 7, 0, {4,-2,-2,1,1,1,1} },

    /** [5.41: Grid point data - PNG
     * encoding](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp5-41.shtml) */
    { 41, 5, 0, {4,-2,-2,1,1} },

    /** 5.40000: Grid point data - JPEG2000 encoding
     *
     * This is a local template number, from a time before WMO standardized use of JPEG2000
     * with 5.40. This should not be used in new data files. Use 5.40 instead. */
    { 40000, 7, 0, {4,-2,-2,1,1,1,1} },

    /** 5.40010: Grid point data - PNG encoding
     *
     * This is a local template number, from a time before WMO standardized use of PNG
     * with 5.41. This should not be used in new data files. Use 5.41 instead. */
    { 40010, 5, 0, {4,-2,-2,1,1} }
} ;

#endif  /*  _drstemplates_H  */
