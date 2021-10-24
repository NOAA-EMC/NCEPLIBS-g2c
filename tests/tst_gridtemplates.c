/* This is a test for the NCEPLIBS-g2c project. This test is for
 * gridtemplates.c.
 *
 * Ed Hartnett 10/24/21
 */

#include <stdio.h>
#include "grib2.h"

#define G2C_ERROR 2

/* Prototypes. */
g2int getgridindex(g2int number);


int
main()
{
    
    printf("Testing gridtemplates.\n");
    printf("Testing simple getgridindex() calls...");
    {
        g2int idx;

        /* Check for one that's there. */
        idx = getgridindex(1);
        if (idx != 1)
            return G2C_ERROR;

        /* Check for one that's not there. */
        idx = getgridindex(-1);
        if (idx != -1)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing simple getgridtemplate() calls...");
    {
        gtemplate *tmpl;

        /* Check for one that's there. */
        if (!(tmpl = getgridtemplate(1)))
            return G2C_ERROR;

        /* Check for one that's not there. */
        if ((tmpl = getgridtemplate(-1)))
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
