/*
 * This is part of the NCEPLIBS-g2c project.
 *
 * This is a test for error handling.
 *
 * Ed Hartnett 8/30/22
 */

#include "grib2_int.h"

#define MAX_LEN 512

int main()
{
    char error_string[MAX_LEN + 1];
    
    printf("Testing error handling.\n");

    strncpy(error_string, g2c_strerror(0), MAX_LEN);
    if (strncmp(error_string, "No error", MAX_LEN))
	return G2C_ERROR;

    printf("%s\n", g2c_strerror(0));

    printf("SUCCESS!\n");
    return 0;
}

