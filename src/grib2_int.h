/** @file
 * @brief Header file with internal function prototypes NCEPLIBS-g2c
 * library.
 *
 * ### Program History Log
 * Date | Programmer | Comments
 * -----|------------|---------
 * 2021-11-08 | Ed Hartnett | Initial
 *
 * @author Ed Hartnett @date 2021-11-08
 */

#ifndef _grib2_int_H
#define _grib2_int_H

#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include "grib2.h"

#define ALOG2 (0.69314718) /**< ln(2.0) */

#define G2C_JASPER_JPEG_FORMAT_NAME "jpc" /**< Name of JPEG codec in Jasper. */

#define G2C_MIN_MAX_BYTES 16 /**< Minimum acceptable value for max_bytes parameter of g2c_get_msg(). */

#define G2C_ERROR 1 /**< Returned for test errors. */

#define G2C_MAGIC_HEADER "GRIB" /**< GRIB magic header string. */

#define G2C_MAGIC_HEADER_LEN 8 /**< Full length of magic header string (includes GRIB version byte). */

#define G2C_MAX_MESSAGES 1024 /**< Maximum number of messages in a file. */

/** This is the information about each message. */
typedef struct g2c_message_info
{
    size_t message_number; /**< Number of message in file. */
    int section0[G2C_SECTION0_LEN]; /**< Section 0 array. */
    int section1[G2C_SECTION1_LEN]; /**< Section 1 array. */
    int num_fields; /**< Number of fields in the message. */
    int num_local; /**< Number of local sections in the message. */
} G2C_MESSAGE_INFO_T;

/** This is the information about each open file. */
typedef struct g2c_file_info
{
    int g2cid; /**< ID of the file. */
    char path[G2C_MAX_NAME + 1]; /**< Path of the file. */
    FILE *f; /**< FILE pointer to open file. */
    size_t num_messages; /**< Number of messages in the file. */
    G2C_MESSAGE_INFO_T msg[G2C_MAX_MESSAGES]; /**< Information about the messages in the file. */
} G2C_FILE_INFO_T;

/**
 * Struct for GRIB template.
 */
struct gtemplate
{
    /** The template type:
     * 3 Grid Defintion Template.
     * 4 Product Defintion Template.
     * 5 Data Representation Template. */
    g2int type;

    g2int num; /**< The template number. */

    /** Number of entries in the static part of the template. */
    g2int maplen;

    /** Number of octets of each entry in the static part of the
     * template. */
    g2int *map;

    /** Indicates whether or not the template needs to be extended. */
    g2int needext;

    /** Number of entries in the template extension. */
    g2int extlen;

    /** Number of octets of each entry in the extension part of the
     * template. */
    g2int *ext;
};

typedef struct gtemplate gtemplate; /**< Struct for GRIB template. */

/* Legacy support functions. */
double int_power(double x, g2int y);
void mkieee(float *a, g2int *rieee, g2int num);
void rdieee(g2int *rieee, float *a, g2int num);

/* Get the various templates. */
gtemplate *getdrstemplate(g2int number);
gtemplate *extdrstemplate(g2int number, g2int *list);
gtemplate *getpdstemplate(g2int number);
gtemplate *extpdstemplate(g2int number, g2int *list);
gtemplate *getgridtemplate(g2int number);
gtemplate *extgridtemplate(g2int number, g2int *list);

/* Packing and unpacking data. */
void simpack(float *fld, g2int ndpts, g2int *idrstmpl,
             unsigned char *cpack, g2int *lcpack);
g2int simunpack(unsigned char *cpack, g2int *idrstmpl, g2int ndpts,
                float *fld);
void compack(float *fld, g2int ndpts, g2int idrsnum, g2int *idrstmpl,
             unsigned char *cpack, g2int *lcpack);
int comunpack(unsigned char *cpack, g2int lensec, g2int idrsnum,
              g2int *idrstmpl, g2int ndpts, float *fld);
void misspack(float *fld, g2int ndpts, g2int idrsnum, g2int *idrstmpl,
              unsigned char *cpack, g2int *lcpack);
void cmplxpack(float *fld, g2int ndpts, g2int idrsnum, g2int *idrstmpl,
               unsigned char *cpack, g2int *lcpack);
g2int getpoly(unsigned char *csec3, g2int *jj, g2int *kk, g2int *mm);
void specpack(float *fld, g2int ndpts, g2int JJ, g2int KK, g2int MM,
              g2int *idrstmpl, unsigned char *cpack, g2int *lcpack);
g2int specunpack(unsigned char *cpack, g2int *idrstmpl, g2int ndpts, g2int JJ,
                 g2int KK, g2int MM, float *fld);
g2int getdim(unsigned char *csec3, g2int *width, g2int *height, g2int *iscan);

int enc_png(unsigned char *data, g2int width, g2int height, g2int nbits,
            unsigned char *pngbuf);
int dec_png(unsigned char *pngbuf, g2int *width, g2int *height,
            unsigned char *cout);
void pngpack(float *fld, g2int width, g2int height, g2int *idrstmpl,
             unsigned char *cpack, g2int *lcpack);
g2int pngunpack(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
                float *fld);
int enc_jpeg2000(unsigned char *cin, g2int width, g2int height, g2int nbits,
                 g2int ltype, g2int ratio, g2int retry, char *outjpc,
                 g2int jpclen);
int dec_jpeg2000(char *injpc, g2int bufsize, g2int *outfld);
void jpcpack(float *fld, g2int width, g2int height, g2int *idrstmpl,
             unsigned char *cpack, g2int *lcpack);
g2int jpcunpack(unsigned char *cpack, g2int len, g2int *idrstmpl, g2int ndpts,
                float *fld);

/* Packing and unpacking bits. */
void gbit(unsigned char *in, g2int *iout, g2int iskip, g2int nbits);
void sbit(unsigned char *out, g2int *in, g2int iskip, g2int nbits);
void gbits(unsigned char *in, g2int *iout, g2int iskip, g2int nbits,
           g2int nskip, g2int n);
void sbits(unsigned char *out, g2int *in, g2int iskip, g2int nbits,
           g2int nskip, g2int n);

/* Deal with grib groups. */
int pack_gp(g2int *kfildo, g2int *ic, g2int *nxy,
            g2int *is523, g2int *minpk, g2int *inc, g2int *missp, g2int *misss,
            g2int *jmin, g2int *jmax, g2int *lbit, g2int *nov,
            g2int *ndg, g2int *lx, g2int *ibit, g2int *jbit, g2int *kbit,
            g2int *novref, g2int *lbitref, g2int *ier);

/* Check the message header and check for message termination. */
int g2c_check_msg(unsigned char *cgrib, g2int *lencurr, int verbose);

/* Handle logging. */
#ifdef LOGGING

/* To log something... */
void g2_log(int severity, const char *fmt, ...);

/** Log a message to stdout. This is used for debugging the library. */
#define LOG(e) g2_log e

#else /* LOGGING */

/** Ignore logging to stdout. Library was not built with LOGGING=ON. */
#define LOG(e)

#endif /* LOGGING */

#endif  /*  _grib2_int_H  */
