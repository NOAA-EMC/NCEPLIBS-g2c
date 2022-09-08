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
    printf("Testing error handling.\n");

    if (strncmp(g2c_strerror(0), "No error", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-50), "GRIB2 header not found", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-51), "GRIB message is already complete.", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-52), "Name too long", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-53), "Invalid input", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-54), "Error reading file", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-55), "Bad ID", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-56), "Too many files open", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-57), "Out of memory", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-58), "Error decoding message", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-59), "No GRIB message found", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-60), "Error parsing XML", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-61), "Table or entry not found", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-62), "Not GRIB 2", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-63), "Cannot find section 1", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-64), "Cannot find end of GRIB message", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-65), "End of message in wrong place", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-66), "Invalid section number", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(-67), "Error encoding/decoding JPEG data", MAX_LEN))
	return G2C_ERROR;
    if (strncmp(g2c_strerror(999), "Unknown Error", MAX_LEN))
	return G2C_ERROR;

    printf("SUCCESS!\n");
    return 0;
}

