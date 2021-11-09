/** @file
 * @brief Unpack Section 4 (Product Definition Section) as defined in
 * GRIB Edition 2.
 * @author Stephen Gilbert @date 2002-10-31
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

/**
 * This subroutine unpacks [Section 4 (Product Definition
 * Section)](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_sect4.shtml)
 * as defined in GRIB Edition 2.
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|--------- 
 * 2002-10-31 | Gilbert | Initial
 * 2009-01-14 | Vuong | Changed structure name template to gtemplate
 *
 * @param cgrib Array containing Section 4 of the GRIB2 message.
 * @param iofst Bit offset of the beginning of Section 4 in
 * cgrib. Returned with updated bit offset.
 * @param ipdsnum Product Definition Template Number (see [Table
 * 4.0](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table4-0.shtml)).
 * @param ipdstmpl Pointer that gets an integer array containing the data
 * values for the Product Definition Template specified by ipdsnum.
 * @param mappdslen Number of elements in ipdstmpl - i.e. number of
 * entries in Product Defintion Template specified by ipdsnum.
 * @param coordlist Pointer that gets an array containing floating
 * point values intended to document the vertical discretisation
 * associated to model data on hybrid coordinate vertical levels.
 * @param numcoord number of values in array coordlist.
 *
 * @returns
 * - 0 no error
 * - 2 Not section 4
 * - 5 "GRIB" message contains an undefined Product Definition Template.
 * - 6 memory allocation error
 *
 * @author Stephen Gilbert @date 2002-10-31
 */
g2int
g2_unpack4(unsigned char *cgrib, g2int *iofst, g2int *ipdsnum, g2int **ipdstmpl,
           g2int *mappdslen, g2float **coordlist, g2int *numcoord)
{

    g2int ierr, needext, i, j, nbits, isecnum;
    g2int lensec, isign, newlen;
    g2int *coordieee;
    g2int *lipdstmpl = 0;
    g2float *lcoordlist;
    gtemplate *mappds;

    ierr = 0;
    *ipdstmpl = NULL;
    *coordlist = NULL;

    gbit(cgrib, &lensec, *iofst, 32);        /* Get Length of Section */
    *iofst = *iofst + 32;
    gbit(cgrib, &isecnum, *iofst, 8);         /* Get Section Number */
    *iofst = *iofst + 8;

    if (isecnum != 4)
    {
        ierr = 2;
        *numcoord = 0;
        *mappdslen = 0;
        return(ierr);
    }

    gbit(cgrib, numcoord, *iofst, 16);    /* Get num of coordinate values */
    *iofst = *iofst + 16;
    gbit(cgrib, ipdsnum, *iofst, 16);    /* Get Prod. Def Template num. */
    *iofst = *iofst + 16;

    /* Get Product Definition Template */
    mappds = getpdstemplate(*ipdsnum);
    if (mappds == 0)
    {       /* undefine template */
        ierr = 5;
        *mappdslen = 0;
        return(ierr);
    }
    *mappdslen = mappds->maplen;
    needext = mappds->needext;

    /* Unpack each value into array ipdstmpl from the the
     * appropriate number of octets, which are specified in
     * corresponding entries in array mappds. */
    if (*mappdslen > 0)
        lipdstmpl = calloc(*mappdslen, sizeof(g2int));
    if (lipdstmpl == 0)
    {
        ierr = 6;
        *mappdslen = 0;
        *ipdstmpl = NULL;
        if (mappds)
            free(mappds);
        return(ierr);
    }
    *ipdstmpl = lipdstmpl;

    for (i = 0; i < mappds->maplen; i++)
    {
        nbits = abs(mappds->map[i]) * 8;
        if (mappds->map[i] >= 0)
        {
            gbit(cgrib, lipdstmpl + i, *iofst, nbits);
        }
        else
        {
            gbit(cgrib, &isign, *iofst, 1);
            gbit(cgrib, lipdstmpl + i, *iofst + 1, nbits - 1);
            if (isign == 1) lipdstmpl[i] = -1 * lipdstmpl[i];
        }
        *iofst = *iofst + nbits;
    }

    /* Check to see if the Product Definition Template needs to be
     * extended. The number of values in a specific template may
     * vary depending on data specified in the "static" part of the
     * gtemplate. */
    if (needext == 1)
    {
        free(mappds);
        mappds = extpdstemplate(*ipdsnum, lipdstmpl);
        newlen = mappds->maplen+mappds->extlen;
        lipdstmpl = realloc(lipdstmpl, newlen * sizeof(g2int));
        *ipdstmpl = lipdstmpl;
        /*   Unpack the rest of the Product Definition Template */
        j = 0;
        for (i = *mappdslen; i < newlen; i++)
        {
            nbits = abs(mappds->ext[j]) * 8;
            if (mappds->ext[j] >= 0)
            {
                gbit(cgrib, lipdstmpl + i, *iofst, nbits);
            }
            else
            {
                gbit(cgrib, &isign, *iofst, 1);
                gbit(cgrib, lipdstmpl + i, *iofst+1, nbits-1);
                if (isign == 1)
                    lipdstmpl[i] = -1 * lipdstmpl[i];
            }
            *iofst = *iofst + nbits;
            j++;
        }
        *mappdslen = newlen;
    }
    if (mappds->ext)
        free(mappds->ext);
    if (mappds)
        free(mappds);

    /* Get Optional list of vertical coordinate values after the
     * Product Definition Template, if necessary. */
    *coordlist = 0;    /* NULL */
    if (*numcoord != 0)
    {
        coordieee = calloc(*numcoord, sizeof(g2int));
        lcoordlist = calloc(*numcoord, sizeof(g2float));
        if (coordieee == 0 || lcoordlist == 0)
        {
            ierr = 6;
            *numcoord = 0;
            *coordlist = 0;    /* NULL */
            if (coordieee)
                free(coordieee);
            if (lcoordlist)
                free(lcoordlist);
            return(ierr);
        }
        else
        {
            *coordlist = lcoordlist;
        }
        gbits(cgrib, coordieee, *iofst, 32, 0, *numcoord);
        rdieee(coordieee, *coordlist, *numcoord);
        free(coordieee);
        *iofst = *iofst + (32 * (*numcoord));
    }

    return(ierr);    /* End of Section 4 processing */

}
