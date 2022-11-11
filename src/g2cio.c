/**
 * @file
 * @brief File I/O functions for the g2c library.
 * @author Ed Hartnett @date Nov 11, 2022
 */

#include "grib2_int.h"

/**
 * Read or write a big-endian 4-byte int to an open file, with
 * conversion between native and big-endian format.
 *
 * GRIB2 handles negative numbers in a special way. Instead of storing
 * two-compliments, like every other programmer and computing
 * organization in the world, GRIB2 flips the first bit, then stores
 * the rest of the int as an unsigned number in the remaining 31
 * bits. How exciting!
 *
 * This function takes the excitement out of GRIB2 negative numbers.
 *
 * @param f Pointer to the open FILE.
 * @param write Non-zero if function should write, otherwise function
 * will read.
 * @param neg Non-zero if the number may be negative.
 * @param var Pointer to the int to be written, or pointer to the
 * storage that gets the int read.
 *
 * @return
 * - :: G2C_NOERROR No error.
 *
 * @author Ed Hartnett 11/7/22
 */
int
g2c_file_be_int4(FILE *f, int write, int neg, int *var)
{
    unsigned int int_be, tmp_1;

    if (write)
    {
        /* Are we writing a negative number? */
        if (neg && *var < 0)
        {
            tmp_1 = -1 * *var; /* Store as positive. */
            tmp_1 |= 1UL << 31; /* Set sign bit. */
        }
        else
            tmp_1 = *var;
        int_be = ntohl(tmp_1);
        if ((fwrite(&int_be, FOUR_BYTES, 1, f)) != 1)
            return G2C_EFILE;
    }
    else
    {
        /* Read from the file. */
        if ((fread(&int_be, FOUR_BYTES, 1, f)) != 1)
            return G2C_EFILE;

        *var = htonl(int_be);
        /* Did we read a negative number? Check the sign bit... */
        if (neg && (*var & 1<<31))
        {
            *var &= ~(1UL<<31); /* Clear sign bit. */
            *var *= -1; /* Make it negative. */
        }
    }

    return G2C_NOERROR;
}

