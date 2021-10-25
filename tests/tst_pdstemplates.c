/* This is a test for the NCEPLIBS-g2c project. This test is for
 * pdstemplates.c.
 *
 * Ed Hartnett 10/25/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2.h"

#define G2C_ERROR 2

/* Prototypes. */

int
main()
{
    
    printf("Testing pdstemplates.\n");
    printf("Testing simple getpdsindex() calls...");
    {
        /* g2int idx; */

        /* /\* Check for one that's there. *\/ */
        /* idx = getgridindex(1); */
        /* if (idx != 1) */
        /*     return G2C_ERROR; */

        /* /\* Check for one that's not there. *\/ */
        /* idx = getgridindex(-1); */
        /* if (idx != -1) */
        /*     return G2C_ERROR; */
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
