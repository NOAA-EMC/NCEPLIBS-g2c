/** @file
 *
 * @brief Unpack Section 1 (Identification Section) as defined in GRIB
 * Edition 2.
 *
 * @author Stephen Gilbert @date 2002-10-29
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

/**
 * This subroutine unpacks [Section 1 - Identification
 * Section](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_sect1.shtml)
 * as defined in GRIB Edition 2.
 *
 * @param cgrib char array containing Section 1 of the GRIB2 message.
 * @param iofst Bit offset for the beginning of Section 1 in cgrib.

 * @param ids Pointer that gets an array which contians the
 * information read from Section 1, the Identification section. This
 * array is allocated by this function, and must be freed by caller
 * (using g2_free()).
 * - ids[0] Identification of originating Centre (see [Table
     0](https://www.nco.ncep.noaa.gov/pmb/docs/on388/table0.html)).
 * - ids[1] Identification of originating Sub-centre (see [Table
     C](https://www.nco.ncep.noaa.gov/pmb/docs/on388/tablec.html)).
 * - ids[2] GRIB Master Tables Version Number (see [Table
     1.0](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-0.shtml)).
 * - ids[3] GRIB Local Tables Version Number (see [Table
     1.1](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-1.shtml)).
 * - ids[4] Significance of Reference Time (see [Table
     1.2](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-2.shtml)).
 * - ids[5] Year (4 digits)
 * - ids[6] Month
 * - ids[7] Day
 * - ids[8] Hour
 * - ids[9] Minute
 * - ids[10] Second
 * - ids[11] Production status of processed data (see [Table
     1.3](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-3.shtml)).
 * - ids[12] Type of processed data (see [Table
     1.4](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-4.shtml)).
 * @param idslen Number of elements in ids.
 *
 * @returns
 * - 0 no error
 * - 2 Array passed is not section 1
 * - 6 memory allocation error
 *
 * @author Stephen Gilbert @date 2002-10-29
 */
g2int
g2_unpack1(unsigned char *cgrib, g2int *iofst, g2int **ids, g2int *idslen)
{

    g2int i, lensec, nbits, ierr, isecnum;
    /* The map holds the number of bytes used by each value in section
     * 1. */
    g2int mapid[13]={2, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1};

    ierr = 0;
    *idslen = 13;
    *ids = 0;

    gbit(cgrib, &lensec, *iofst, 32);        /* Get Length of Section */
    *iofst = *iofst + 32;
    gbit(cgrib, &isecnum, *iofst, 8);         /* Get Section Number */
    *iofst = *iofst + 8;

    if (isecnum != 1)
    {
        ierr = 2;
        *idslen = 13;
        fprintf(stderr, "g2_unpack1: Not Section 1 data.\n");
        return(ierr);
    }

    /* Unpack each value into array ids from the appropriate number of
     * octets, which are specified in` corresponding entries in array
     * mapid. */
    *ids = calloc(*idslen, sizeof(g2int));
    if (*ids == 0)
    {
        ierr = 6;
        return(ierr);
    }

    for (i = 0; i < *idslen; i++)
    {
        nbits = mapid[i] * 8;
        gbit(cgrib, *ids + i, *iofst, nbits);
        *iofst = *iofst + nbits;
    }

    return(ierr);    // End of Section 1 processing
}
