/* This is a test for the NCEPLIBS-g2c project. This test is for
 * gbits.c.
 *
 * Ed Hartnett 7/19/21
 */

#include <stdio.h>
#include "grib2.h"

#define G2C_ERROR 2

int
main()
{
    
    printf("Testing sbit.\n");
    printf("Testing simple sbit() call...");
    {
	unsigned char out[1] = {0x00};
	g2int in[1] = {0x01};
	
	sbit(out, in, 0, 8);
	/* printf("in[0] 0x%02x out[0] 0x%02x\n", in[0], out[0]); */
	if (out[0] != 1)
	    return G2C_ERROR;
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
