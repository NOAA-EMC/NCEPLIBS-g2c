/** @file
 * @brief Returns grid template information for a specified
 * Grid Definition Template 3.
 * @author Stephen Gilbert @date 2001-06-28
 */
#include <stdlib.h>
#include "grib2.h"
#include "gridtemplates.h"

/**
 * This function returns the index of specified Grid Definition
 * Template 3.NN (NN=number) in array templates.
 *
 * PROGRAM HISTORY LOG:
 * - 2001-06-28  Gilbert
 * - 2007-08-16  Vuong     -  Added GDT 3.204  Curvilinear Orthogonal Grid
 * - 2008-07-08  Vuong     -  Added GDT 3.32768 Rotate Lat/Lon E-grid (Arakawa)
 * - 2009-01-14  Vuong     -  Changed structure name template to gtemplate
 * - 2010-05-11  Vuong     -  Added GDT 3.32769 Rotate Lat/Lon Non-E Staggered grid (Arakawa)
 * - 2013-08-06  Vuong     -  Added GDT 3.4,3.5,3.12,3.101,3.140
 *
 * @paran number NN, indicating the number of the Grid Definition
 * Template 3.NN that is being requested.
 *
 * @return Index of GDT 3.NN in array templates, if template
 * exists. -1, otherwise.
 *
 * @author Stephen Gilbert @date 2001-06-28
 */
g2int
getgridindex(g2int number)
{
    g2int j,getgridindex=-1;

    for (j=0;j<MAXGRIDTEMP;j++) {
        if (number == templatesgrid[j].template_num) {
            getgridindex=j;
            return(getgridindex);
        }
    }

    return(getgridindex);
}

/**
 * This subroutine returns grid template information for a specified
 * Grid Definition Template 3.NN. The number of entries in the
 * template is returned along with a map of the number of octets
 * occupied by each entry. Also, a flag is returned to indicate
 * whether the template would need to be extended.
 *
 * PROGRAM HISTORY LOG:
 * - 2000-05-09  Gilbert
 * - 2007-08-16  Vuong     -  Added GDT 3.204  Curvilinear Orthogonal Grid
 * - 2008-07-08  Vuong     -  Added GDT 3.32768 Rotate Lat/Lon E-grid (Arakawa)
 * - 2010-05-11  Vuong     -  Added GDT 3.32769 Rotate Lat/Lon Non-E Staggered grid (Arakawa)
 * - 2009-01-14  Vuong     -  Changed structure name template to gtemplate
 *
 * @param number NN, indicating the number of the Grid Definition
 * Template 3.NN that is being requested.
 *
 * @return Pointer to the returned template struct. Returns NULL
 * pointer, if template not found.
 *
 * @author Stephen Gilbert @date 2000-05-09
 */
gtemplate *
getgridtemplate(g2int number)
{
    g2int index;
    gtemplate *new;

    index=getgridindex(number);

    if (index != -1) {
        new=(gtemplate *)malloc(sizeof(gtemplate));
        new->type=3;
        new->num=templatesgrid[index].template_num;
        new->maplen=templatesgrid[index].mapgridlen;
        new->needext=templatesgrid[index].needext;
        new->map=(g2int *)templatesgrid[index].mapgrid;
        new->extlen=0;
        new->ext=0;        /*NULL */
        return(new);
    }
    else {
        printf("getgridtemplate: GDT Template 3.%d not defined.\n",(int)number);
        return(0);        /* NULL */
    }

    return(0);        /* NULL */
}


/*
 * This subroutine generates the remaining octet map for a given Grid
 * Definition Template, if required. Some Templates can vary
 * depending on data values given in an earlier part of the Template,
 * and it is necessary to know some of the earlier entry values to
 * generate the full octet map of the Template.
 *
 * PROGRAM HISTORY LOG:
 * - 2000-05-09  Gilbert
 * - 2008-07-08  Vuong Added GDT 3.32768 Rotate Lat/Lon E-grid (Arakawa)
 * - 2009-01-14  Vuong Changed structure name template to gtemplate
 * - 2010-05-11  Vuong Added GDT 3.32769 Rotate Lat/Lon Non-E Staggered grid (Arakawa)
 * - 2013-08-06  Vuong Added GDT 3.4,3.5,3.12,3.101,3.140
 *
 * @param number NN, indicating the number of the Grid Definition
 * Template 3.NN that is being requested.
 * @param list The list of values for each entry in the Grid
 * Definition Template.
 *
 * @return Pointer to the returned template struct. Returns NULL
 * pointer, if template not found.
 *
 * @author Stephen Gilbert @date 2000-05-09
 */
gtemplate *
extgridtemplate(g2int number, g2int *list)
{
    gtemplate *new;
    g2int index,i;

    index=getgridindex(number);
    if (index == -1) return(0);

    new=getgridtemplate(number);

    if ( ! new->needext ) return(new);

    if ( number == 120 ) {
        new->extlen=list[1]*2;
        new->ext=(g2int *)malloc(sizeof(g2int)*new->extlen);
        for (i=0;i<new->extlen;i++) {
            if ( i%2 == 0 ) {
                new->ext[i]=2;
            }
            else {
                new->ext[i]=-2;
            }
        }
    }
    else if ( number == 4 ) {
        new->extlen=list[7];
        new->ext=(g2int *)malloc(sizeof(g2int)*new->extlen);
        for (i=0;i<new->extlen;i++) {
            new->ext[i]=4;
        }
        new->extlen=list[8];
        new->ext=(g2int *)malloc(sizeof(g2int)*new->extlen);
        for (i=0;i<new->extlen;i++) {
            new->ext[i]=-4;
        }
    }
    else if ( number == 5 ) {
        new->extlen=list[7];
        new->ext=(g2int *)malloc(sizeof(g2int)*new->extlen);
        for (i=0;i<new->extlen;i++) {
            new->ext[i]=4;
        }
        new->extlen=list[8];
        new->ext=(g2int *)malloc(sizeof(g2int)*new->extlen);
        for (i=0;i<new->extlen;i++) {
            new->ext[i]=-4;
        }
    }
    else if ( number == 1000 ) {
        new->extlen=list[19];
        new->ext=(g2int *)malloc(sizeof(g2int)*new->extlen);
        for (i=0;i<new->extlen;i++) {
            new->ext[i]=4;
        }
    }
    else if ( number == 1200 ) {
        new->extlen=list[15];
        new->ext=(g2int *)malloc(sizeof(g2int)*new->extlen);
        for (i=0;i<new->extlen;i++) {
            new->ext[i]=4;
        }
    }

    return(new);

}
