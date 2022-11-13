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
 * @param g2ctype The type to be read or written.
 * @param var Pointer to the int to be written, or pointer to the
 * storage that gets the int read.
 *
 * @return
 * - :: G2C_NOERROR No error.
 * - :: G2C_EINVAL Invalid input.
 * - :: G2C_EFILE Error reading/writing file.
 *
 * @author Ed Hartnett 11/7/22
 */
int
g2c_file_rw(FILE *f, int write, int g2ctype, void *var)
{
    unsigned int int_be, tmp_1;
    void *void_be;
    int neg;
    int *ivar;
    int type_len;
    int bitshift;

    /* Check inputs. */
    if (!f || !var || g2ctype < G2C_BYTE || g2ctype > G2C_UINT64)
        return G2C_EINVAL;

    switch (g2ctype)
    {
    case G2C_INT:
    case G2C_UINT:
        type_len = FOUR_BYTES;
        ivar = var;
        void_be = &int_be;
        bitshift = 31;
        if (write)
        {
            neg = *ivar < 0 ? 1 : 0;
        }
        break;
    default:
        return G2C_EBADTYPE;
    }

    if (write)
    {
        /* Are we writing a negative number? */
        if (neg)
        {
            tmp_1 = -1 * *ivar; /* Store as positive. */
            tmp_1 |= 1UL << bitshift; /* Set sign bit. */
        }
        else
            tmp_1 = *ivar;
        int_be = ntohl(tmp_1);
        if ((fwrite(&int_be, type_len, 1, f)) != 1)
            return G2C_EFILE;
    }
    else
    {
        /* Read from the file. */
        if ((fread(void_be, type_len, 1, f)) != 1)
            return G2C_EFILE;

        switch (g2ctype)
        {
        case G2C_INT:
        case G2C_UINT:
            *ivar = htonl(int_be);
            break;
        default:
            return G2C_EBADTYPE;
        }

        /* Did we read a negative number? Check the sign bit... */
        if (*ivar & 1 << bitshift)
        {
            *ivar &= ~(1UL << bitshift); /* Clear sign bit. */
            *ivar *= -1; /* Make it negative. */
        }
    }

    return G2C_NOERROR;
}

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
 * @param var Pointer to the int to be written, or pointer to the
 * storage that gets the int read.
 *
 * @return
 * - :: G2C_NOERROR No error.
 * - :: G2C_EINVAL Invalid input.
 * - :: G2C_EFILE Error reading/writing file.
 *
 * @author Ed Hartnett 11/7/22
 */
int
g2c_file_be_int4(FILE *f, int write, int *var)
{
    return g2c_file_rw(f, write, G2C_INT, var);
}

/**
 * Read or write a big-endian 4-byte unsigned int to an open file,
 * with conversion between native and big-endian format.
 *
 * @param f Pointer to the open FILE.
 * @param write Non-zero if function should write, otherwise function
 * will read.
 * @param var Pointer to the unsigned int to be written, or pointer to
 * the storage that gets the unsigned int read.
 *
 * @return
 * - :: G2C_NOERROR No error.
 * - :: G2C_EINVAL Invalid input.
 * - :: G2C_EFILE Error reading/writing file.
 *
 * @author Ed Hartnett 11/11/22
 */
int
g2c_file_be_uint4(FILE *f, int write, unsigned int *var)
{
    unsigned int int_be;

    /* Check inputs. */
    if (!f || !var)
        return G2C_EINVAL;

    if (write)
    {
        int_be = ntohl(*var);
        if ((fwrite(&int_be, FOUR_BYTES, 1, f)) != 1)
            return G2C_EFILE;
    }
    else
    {
        /* Read from the file. */
        if ((fread(&int_be, FOUR_BYTES, 1, f)) != 1)
            return G2C_EFILE;
        *var = htonl(int_be);
    }

    return G2C_NOERROR;
}

/**
 * Read or write a big-endian 4-byte int or unsigned int from or to an
 * open file, with conversion between native and big-endian format,
 * and handling of GRIB negative numbers. This is for template values.
 *
 * With template values, if the map value is negative, then the
 * template value may be negative.
 *
 * @param f Pointer to the open FILE.
 * @param rw_flag Non-zero if function should write, otherwise function
 * will read.
 * @param neg Non-zero if this may be a negative number, zero for
 * unsigned ints.
 * @param template_value Pointer to the template value to be written,
 * or pointer to the storage that gets the templage value read.
 *
 * @return
 * - :: G2C_NOERROR No error.
 * - :: G2C_EINVAL Invalid input.
 * - :: G2C_EFILE Error reading/writing file.
 *
 * @author Ed Hartnett 11/7/22
 */
int
g2c_file_template_int4(FILE *f, int rw_flag, int neg, int *template_value)
{
    int ret;
    
    if (neg)
    {
        if ((ret = g2c_file_be_int4(f, rw_flag, template_value)))
            return ret;
    }
    else
    {
        if ((ret = g2c_file_be_uint4(f, rw_flag, (unsigned int *)template_value)))
            return ret;
    }
    
    return G2C_NOERROR;
}
