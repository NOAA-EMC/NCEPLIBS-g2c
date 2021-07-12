/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2_create.
 *
 * Ed Hartnett 7/11/21
 */

#include <stdio.h>
#include "grib2.h"

#define MSG_LEN 37
#define G2C_ERROR 2

int
main()
{
    printf("Testing g2_create().\n");
    {
	unsigned char cgrib[MSG_LEN];
	unsigned char expected_cgrib[MSG_LEN] = {71, 82, 73, 66, 0, 0, 0, 2, 0, 0,
						 0, 0, 0, 0, 0, 37, 0, 0, 0, 21, 1,
						 0, 0, 0, 0, 0, 0, 0, 7, 229, 9, 22,
						 0, 0, 0, 0, 0};
	g2int listsec0[2] = {0, 2};
	g2int listsec1[13] = {0, 0, 0, 0, 0, 2021, 9, 22, 0, 0, 0, 0, 0};
	
	int i;
	int ret;
    
	if ((ret = g2_create(cgrib, listsec0, listsec1)) != MSG_LEN)
	    return G2C_ERROR;
	for (i = 0; i < MSG_LEN; i++)
	{
	    /* printf("%d %d %d\n", i, cgrib[i], expected_cgrib[i]); */
	    if (cgrib[i] != expected_cgrib[i])
	    	return G2C_ERROR;
	}
    }
    printf("SUCCESS!\n");
    return 0;
}
