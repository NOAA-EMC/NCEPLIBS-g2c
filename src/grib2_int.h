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

#include <stdio.h>
#include <stdint.h>
#include "grib2.h"

#define ALOG2 (0.69314718) /**< ln(2.0) */

/*  Prototypes for supporting routines  */
extern double int_power(double,  g2int);
extern void mkieee(g2float *, g2int *, g2int);
void rdieee(g2int *, g2float *, g2int);
extern gtemplate *getpdstemplate(g2int);
extern gtemplate *extpdstemplate(g2int, g2int *);
extern gtemplate *getdrstemplate(g2int);
extern gtemplate *extdrstemplate(g2int, g2int *);
extern gtemplate *getgridtemplate(g2int);
extern gtemplate *extgridtemplate(g2int, g2int *);
extern void simpack(g2float *, g2int, g2int *, unsigned char *, g2int *);
extern void compack(g2float *, g2int, g2int, g2int *, unsigned char *, g2int *);
void misspack(g2float *, g2int , g2int , g2int *,  unsigned char *,  g2int *);
void gbit(unsigned char *, g2int *, g2int , g2int);
void sbit(unsigned char *, g2int *, g2int , g2int);
void gbits(unsigned char *, g2int *, g2int , g2int , g2int , g2int);
void sbits(unsigned char *, g2int *, g2int , g2int , g2int , g2int);

int pack_gp(g2int *,  g2int *,  g2int *,
            g2int *,  g2int *,  g2int *,  g2int *,  g2int *,
            g2int *,  g2int *,  g2int *,  g2int *,
            g2int *,  g2int *,  g2int *,  g2int *,  g2int *,
            g2int *,  g2int *,  g2int *);

#endif  /*  _grib2_int_H  */
