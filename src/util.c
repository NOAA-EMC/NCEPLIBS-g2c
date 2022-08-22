/** 
 * @file
 * @brief Internal utility functions for the g2c library.
 * @author Ed Hartnett @date Nov 11, 2021
 */

#include "grib2_int.h"
#include <stdarg.h>

/** Global file information. */
extern G2C_FILE_INFO g2c_file[G2C_MAX_FILES + 1];

/**
 * Check for 'GRIB' at the beginning of a GRIB message, and check to
 * see if the message is already terminated with '7777'.
 *
 * @param cgrib Buffer that contains the GRIB message.
 * @param lencurr Pointer that gets the length of the GRIB message.
 * @param verbose If non-zero, print any error messages to stdout.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_ENOTGRIB GRIB header not found.
 * - ::G2C_EMSGCOMPLETE GRIB message already complete.
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
        return G2C_ENOTGRIB;
    }

    /* Get current length of GRIB message. */
    gbit(cgrib, lencurr, 96, 32);

    /* Check to see if GRIB message is already complete. */
    if (cgrib[*lencurr - 4] == seven && cgrib[*lencurr - 3] == seven &&
        cgrib[*lencurr - 2] == seven && cgrib[*lencurr - 1] == seven)
    {
        if (verbose)
            printf("GRIB message already complete.  Cannot add new section.\n");
        return G2C_EMSGCOMPLETE;
    }

    return G2C_NOERROR;
}

#ifdef LOGGING
/* This is the severity level of messages which will be logged. Use
   severity 0 for errors, 1 for important log messages, 2 for less
   important, etc. */
int g2_log_level = -1;

/* This function prints out a message, if the severity of
 * the message is lower than the global g2_log_level. To use it, do
 * something like this:
 *
 * g2_log(0, "this computer will explode in %d seconds", i);
 *
 * After the first arg (the severity), use the rest like a normal
 * printf statement. Output will appear on stderr.
 *
 * This function is not included in the build unless NCEPLIBS-g2c was
 * built with -DLOGGING.
 *
 * Ed Hartnett
 */
void
g2_log(int severity, const char *fmt, ...)
{
    va_list argp;
    int t;
    FILE *f = stderr;

    /* If the severity is greater than the log level, we don't print
     * this message. */
    if (severity > g2_log_level)
        return;

    /* If the severity is zero, this is an error. Otherwise insert that
       many tabs before the message. */
    if (!severity)
        fprintf(f, "ERROR: ");
    for (t = 0; t < severity; t++)
        fprintf(f, "\t");

    /* Print out the variable list of args with vprintf. */
    va_start(argp, fmt);
    vfprintf(f, fmt, argp);
    va_end(argp);

    /* Put on a final linefeed. */
    fprintf(f, "\n");
    fflush(f);
}
#endif /* LOGGING */

/**
 * Use this to set the global log level. 
 * 
 * Set it to -1 to turn off all logging. Set it
 * to 0 to show only errors, and to higher numbers to show more and
 * more logging details. If logging is not enabled when building
 * NCEPLIBS-g2c, this function will do nothing.
 *
 * @param new_level The new logging level.
 *
 * @return ::G2C_NOERROR No error.
 * @author Ed Hartnett
 */
int
g2c_set_log_level(int new_level)
{
#ifdef LOGGING
    /* Remember the new level. */
    g2_log_level = new_level;

    LOG((1, "log_level changed to %d", g2_log_level));
#endif
    return G2C_NOERROR;
}

/**
 * Print a summary of the contents of an open GRIB2 file. If the
 * NCEPLIBS-g2c library is built without the LOGGING option, this
 * function will do nothing.
 * 
 * @param g2cid The file ID, returned by g2c_open() or g2c_create().
 *
 * @return 
 * - ::G2C_NOERROR No error.
 * - ::G2C_EBADID g2cid not found.
 *
 * @author Ed Hartnett 8/22/22
 */
int
g2c_log_file(int g2cid)
{
#ifdef LOGGING
    int m;
    
    /* Find the open file struct. */
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;

    LOG((1, "path %s", g2c_file[g2cid].path));
    LOG((1, "num_messages %ld", g2c_file[g2cid].num_messages));
    for (m = 0; m < g2c_file[g2cid].num_messages; m++)
    {
	G2C_MESSAGE_INFO *msg = &g2c_file[g2cid].msg[m];
	LOG((1, "message %ld num_fields %d num_local %d msg->section0 (%d, %d, %d)", msg->message_number,
	     msg->num_fields, msg->num_local, msg->section0[0], msg->section0[1], msg->section0[2]));
    }

#endif
    return G2C_NOERROR;
}
