/** 
 * @file
 * @brief Internal utility functions for the g2c library.
 * @author Ed Hartnett @date Nov 11, 2021
 */

#include "grib2_int.h"

/**
 * Check for 'GRIB' at the beginning of a GRIB message, and check to
 * see if the message is already terminated with '7777'.
 *
 * @param cgrib Buffer that contains the GRIB message.
 * @param lencurr Pointer that gets the length of the GRIB message.
 * @param verbose If non-zero, print any error messages to stdout.
 *
 * @return
 * - ::G2C_NO_ERROR No error.
 * - ::G2C_NOT_GRIB GRIB header not found.
 * - ::G2C_MSG_COMPLETE GRIB message already complete.
 *
 * @author Ed Hartnett @date Nov 11, 2021
 */
int
g2c_check_msg(unsigned char *cgrib, g2int *lencurr, int verbose)
{
    unsigned char G = 0x47;       /* 'G' */
    unsigned char R = 0x52;       /* 'R' */
    unsigned char I = 0x49;       /* 'I' */
    unsigned char B = 0x42;       /* 'B' */
    unsigned char seven = 0x37;   /* '7' */

    assert(cgrib && lencurr);

    /* Check to see if beginning of GRIB message exists. */
    if (cgrib[0] != G || cgrib[1] != R || cgrib[2] != I || cgrib[3] != B)
    {
        if (verbose)
            printf("GRIB not found in given message. A call to routine g2_create() "
                   "is required to to initialize GRIB messge.\n");
        return G2C_NOT_GRIB;
    }

    /* Get current length of GRIB message. */
    gbit(cgrib, lencurr, 96, 32);

    /* Check to see if GRIB message is already complete. */
    if (cgrib[*lencurr - 4] == seven && cgrib[*lencurr - 3] == seven &&
        cgrib[*lencurr - 2] == seven && cgrib[*lencurr - 1] == seven)
    {
        if (verbose)
            printf("GRIB message already complete.  Cannot add new section.\n");
        return G2C_MSG_COMPLETE;
    }

    return G2C_NO_ERROR;
}
