/** 
 * @file
 * @brief Functions for GRIB2 Data Representation Templates (DRT) for
 * the Data Representation Setcion.
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2001-06-28 | Gilbert | Initial
 * 2009-01-14 | Vuong | Changed structure name template to gtemplate
 *
 * @author Stephen Gilbert @date 2001-06-28
 */

#include <stdlib.h>
#include "grib2.h"
#include "drstemplates.h"

/**
 * This function returns the index of specified Data Representation
 * Template.
 *
 * @param number The number of the Data Representation Template that
 * is being requested.
 *
 * @return Index of the DRT in array gtemplates, if it exists. -1,
 * otherwise.
 *
 * @author Stephen Gilbert @date 2001-06-28
 */
g2int
getdrsindex(g2int number)
{
    g2int j, getdrsindex = -1;

    for (j = 0; j < MAXDRSTEMP; j++)
    {
        if (number == templatesdrs[j].template_num)
        {
            getdrsindex = j;
            return(getdrsindex);
        }
    }

    return(getdrsindex);
}

/**
 * This subroutine returns DRS template information for a specified
 * Data Representation Template. The number of entries in the
 * template is returned along with a map of the number of octets
 * occupied by each entry. Also, a flag is returned to indicate
 * whether the template would need to be extended.
 *
 * @param number The number of the Data Representation
 * Template that is being requested.
 *
 * @return Pointer to the returned template struct. Returns NULL
 * if template not found.
 *
 * @author Stephen Gilbert @date 2000-05-11
 */
gtemplate *
getdrstemplate(g2int number)
{
    g2int index;
    gtemplate *new;

    index = getdrsindex(number);

    if (index != -1)
    {
        new = malloc(sizeof(gtemplate));
        new->type = 5;
        new->num = templatesdrs[index].template_num;
        new->maplen = templatesdrs[index].mapdrslen;
        new->needext = templatesdrs[index].needext;
        new->map = (g2int *)templatesdrs[index].mapdrs;
        new->extlen = 0;
        new->ext = NULL;
        return(new);
    }
    else
    {
        printf("getdrstemplate: DRS Template 5.%d not defined.\n", (int)number);
        return(NULL);
    }

    return(NULL);
}

/**
 * This subroutine generates the remaining octet map for a given Data
 * Representation Template, if required. Some Templates can vary
 * depending on data values given in an earlier part of the Template,
 * and it is necessary to know some of the earlier entry values to
 * generate the full octet map of the Template.
 *
 * @param number The number of the Data Representation Template that
 * is being requested.
 * @param list The list of values for each entry in the the Data
 * Representation Template.
 *
 * @return Pointer to the returned template struct. Returns NULL
 * pointer, if template not found.
 *
 * @author Stephen Gilbert @date 2000-05-11
 */
gtemplate *
extdrstemplate(g2int number, g2int *list)
{
    gtemplate *new;
    g2int index, i;

    index = getdrsindex(number);
    if (index == -1)
        return(0);

    new = getdrstemplate(number);

    if (!new->needext)
        return(new);

    if (number == 1)
    {
        new->extlen = list[10] + list[12];
        new->ext = malloc(sizeof(g2int) * new->extlen);
        for (i = 0; i < new->extlen; i++)
        {
            new->ext[i] = 4;
        }
    }
    return(new);
}
