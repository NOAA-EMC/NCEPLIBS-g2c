/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2cxml.c.
 *
 * Ed Hartnett 8/27/22
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

int
main()
{
    printf("Testing XML ingestion...\n");
    if (g2c_xml_init())
	return G2C_ERROR;
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

