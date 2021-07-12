/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2_create.
 *
 * Ed Hartnett 7/11/21
 */

#include <stdio.h>
#include "grib2.h"

#define MSG_LEN 25
#define G2C_ERROR 2

int
main()
{
    printf("Testing g2_create().\n");
    {
	unsigned char cgrib[MSG_LEN];
	g2int listsec0[2] = {0, 2};
	g2int listsec1[13] = {0, 0, 0, 0, 0, 2021, 9, 22, 0, 0, 0, 0, 0};
    
	if (g2_create(cgrib, listsec0, listsec1))
	    return G2C_ERROR;
    }
    printf("SUCCESS!\n");
    return 0;
}
