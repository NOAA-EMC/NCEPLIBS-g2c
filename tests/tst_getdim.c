/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the getdim function.
 *
 * Ed Hartnett 10/28/21
 */

#include "grib2_int.h"
#include <stdio.h>
#include <stdlib.h>

#define SEC3_LEN 72

/* Prototypes for some functions tested in this program. */
g2int getdim(unsigned char *csec3, g2int *width, g2int *height, g2int *iscan);
g2int getpoly(unsigned char *csec3, g2int *jj, g2int *kk, g2int *mm);

int
main()
{
    printf("Testing getdim function.\n");
    printf("Testing getdim() call...");
    {
        g2int width, height, iscan;
        unsigned char csec3[SEC3_LEN] = {
            0x00, 0x00, 0x00, 0x48, /* len of sect 3 (72) */
            0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
            0x03, 0x00, 0x00, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
            0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00,
            0x00, 0x0c, 0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x11, 0x12};

        getdim(csec3, &width, &height, &iscan);
        /* printf("%ld %ld %ld\n", width, height, iscan); */
        if (width != 7 || height != 8 || iscan != 18)
            return G2C_ERROR;

        /* Try the getpoly() function. */
        g2int jj, kk, mm;
        getpoly(csec3, &jj, &kk, &mm);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
