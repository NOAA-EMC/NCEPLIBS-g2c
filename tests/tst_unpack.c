/* This is a test for the NCEPLIBS-g2c project. This test is for
 * the g2_unpack functions.
 *
 * Ed Hartnett 10/27/21
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define SEC0_LEN 16
#define SEC1_LEN 21
#define SEC3_LEN 34
#define FULL_MSG_LEN 182

int
main()
{
    printf("Testing g2_unpack functions.\n");
    printf("Testing g2_unpack1() call...");
    {
        g2int listsec1[13] = {7, 4, 24, 0, 0, 2021, 10, 24, 6, 54, 59, 7, 192};
        g2int expected_igds[5] = {0, 4, 0, 0, 0};
        g2int expected_igdstmpl[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
        g2int expected_ipdstmpl[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        
        unsigned char cgrib[FULL_MSG_LEN] = {
            0x47, 0x52, 0x49, 0x42, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, /* section 0 */
            0x00, 0x00, 0x00, 0x15,                                                                         /* len of sect 1 (21) */
            0x01, 0x00, 0x07, 0x00, 0x04, 0x18, 0x00, 0x00, 0x07, 0xe5, 0x0a, 0x18, 0x06, 0x36, 0x3b, 0x07, 0xc0, /* section 1 */
            0x00, 0x00, 0x00, 0x48,                                                                         /* len of sect 3 (72) */            
            0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
            0x03, 0x00, 0x00, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
            0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00,
            0x00, 0x0c, 0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x11, 0x12,
            0x00, 0x00, 0x00, 0x22,                                                                         /* len of sect 4 (34) */            
            0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x05, 0x06, 0x07, 0x00, 0x00, /* section 4 */
            0x00, 0x08, 0x09, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x0c, 0x0d, 0x00, 0x00, 0x00, 0x0e,
            0x00, 0x00, 0x00, 0x15,                                                                         /* len of sect 5 (21) */            
            0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x42, 0xc8, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x03, 0x00, /* section 5 */
            0x00, 0x00, 0x00, 0x07,                                                                         /* len of sect 6 (7) */            
            0x06, 0x00, 0xf0,                                                                               /* section 6 */            
            0x00, 0x00, 0x00, 0x07,                                                                         /* len of sect 7 (7) */            
            0x07, 0x0a, 0x60,                                                                               /* section 7 */            
            0x37, 0x37, 0x37, 0x37};                                                                        /* "7777" (section 8) */            
        g2int iofst = 128, idslen;
        unsigned char old_val;
        g2int *ids;
        g2int lencsec2;
        unsigned char *csec2;
        g2int *igds, *igdstmpl, mapgridlen, *ideflist, idefnum;
        g2int ipdsnum, *ipdstmpl, mappdslen;
        float *coordlist;
        g2int numcoord;
        int i;

        /* Try and unpack section1 - with a bad section number. Won't work. */
        old_val = cgrib[20];
        cgrib[20] = 0;
        if (g2_unpack1(cgrib, &iofst, &ids, &idslen) != 2)
            return G2C_ERROR;
        cgrib[20] = old_val;
        
        /* Unpack section1 - starts at bit 128. */
        iofst = 128;
        if (g2_unpack1(cgrib, &iofst, &ids, &idslen))
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < 13; i++)
            if (ids[i] != listsec1[i])
                return G2C_ERROR;

        /* Free memory. */
        free(ids);

        /* Try to unpack section2 - won't work, because there is no section 2 in this message. */
        iofst = 128;
        if (g2_unpack2(cgrib, &iofst, &lencsec2, &csec2) != 2)
            return G2C_ERROR;
        if (csec2 || lencsec2)
            return G2C_ERROR;

        /* Try to read section 3 with bad section number. */
        old_val = cgrib[41];
        cgrib[41] = 1;
        iofst = 296;
        if (g2_unpack3(cgrib, &iofst, &igds, &igdstmpl, &mapgridlen, &ideflist, &idefnum) != 2)
            return G2C_ERROR;
        cgrib[41] = old_val;

        /* Try to read section 3 with bad grid template number. */
        old_val = cgrib[50];
        cgrib[50] = 127;
        iofst = 296;
        if (g2_unpack3(cgrib, &iofst, &igds, &igdstmpl, &mapgridlen, &ideflist, &idefnum) != 5)
            return G2C_ERROR;
        cgrib[50] = old_val;

        /* Read section 3. */
        iofst = 296;
        if (g2_unpack3(cgrib, &iofst, &igds, &igdstmpl, &mapgridlen, &ideflist, &idefnum))
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < 5; i++)
            if (igds[i] != expected_igds[i])
                return G2C_ERROR;
        for (i = 0; i < 19; i++)
            if (igdstmpl[i] != expected_igdstmpl[i])
                return G2C_ERROR;

        /* Free memory. */
        free(igds);
        free(igdstmpl);

        /* Try to read section with bad section number - won't work. */
        old_val = cgrib[113];
        cgrib[113] = 2;
        iofst = 872; /* 109 bytes */
        if (g2_unpack4(cgrib, &iofst, &ipdsnum, &ipdstmpl, &mappdslen, &coordlist, &numcoord) != 2)
            return G2C_ERROR;
        if (mappdslen || numcoord)
            return G2C_ERROR;
        cgrib[113] = old_val;

        /* Try to read section with bad product definition section template number - won't work. */
        old_val = cgrib[117];
        cgrib[117] = 230;
        iofst = 872; /* 109 bytes */
        if (g2_unpack4(cgrib, &iofst, &ipdsnum, &ipdstmpl, &mappdslen, &coordlist, &numcoord) != 5)
            return G2C_ERROR;
        if (mappdslen)
            return G2C_ERROR;
        cgrib[117] = old_val;

        /* Read section 4. */
        iofst = 872; /* 109 bytes */
        if (g2_unpack4(cgrib, &iofst, &ipdsnum, &ipdstmpl, &mappdslen, &coordlist, &numcoord))
            return G2C_ERROR;

        /* Check results. */
        for (i = 0; i < 15; i++)
            if (ipdstmpl[i] != expected_ipdstmpl[i])
                return G2C_ERROR;

        /* Free memory. */
        free(ipdstmpl);
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
