/** @file
 * @brief Unpack Section 2 (Local Use Section) as defined in
 * GRIB Edition 2.
 * @author Stephen Gilbert @date 2002-10-31
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

/**
 * This subroutine unpacks [Section 2 (Local Use
 * Section)](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_sect2.shtml)
 * as defined in GRIB Edition 2.
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2002-10-31 | Gilbert | Initial
 * 2008-12-23 | Wesley | Initialize lencsec2 Length of Local Use data
 * 2010-08-05 | Vuong | If section 2 has zero length, ierr=0
 *
 * @param cgrib char array containing Section 2 of the GRIB2 message.
 * @param iofst Pointer that contains the bit offset for the beginning
 * of Section 2 in cgrib. The modified version will be returned.
 * @param lencsec2 Length (in octets) of Local Use data.
 * @param csec2 Pointer to a pointer that will get an allocated array
 * containing local use data. This memory must be freed by the caller.
 *
 * @return
 * - 0 no error
 * - 2 Array passed is not section 2
 * - 6 memory allocation error
 *
 * @author Stephen Gilbert @date 2002-10-31
 */
g2int
g2_unpack2(unsigned char *cgrib, g2int *iofst, g2int *lencsec2,
           unsigned char **csec2)
{
    g2int ierr = 0, isecnum;
    g2int lensec, ipos, j;

    *lencsec2 = 0;
    *csec2 = NULL;

    gbit(cgrib, &lensec, *iofst, 32);        /* Get Length of Section */
    *iofst = *iofst + 32;
    *lencsec2 = lensec - 5;
    gbit(cgrib, &isecnum, *iofst, 8);         /* Get Section Number */
    *iofst = *iofst + 8;
    ipos = *iofst / 8;

    if ( isecnum != 2 )
    {
        ierr = 2;
        *lencsec2 = 0;
        fprintf(stderr, "g2_unpack2: Not Section 2 data.\n");
        return ierr;
    }

    if (*lencsec2 == 0)
    {
        ierr = 0;
        return ierr;
    }

    if (!(*csec2 = malloc(*lencsec2 + 1)))
    {
        ierr = 6;
        *lencsec2 = 0;
        return ierr;
    }

    for (j = 0; j < *lencsec2; j++)
        (*csec2)[j] = cgrib[ipos + j];

    *iofst = *iofst + (*lencsec2 * 8);

    return ierr;    /* End of Section 2 processing */
}
