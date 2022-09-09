/** @file
 *
 * @brief Search through a GRIB2 message and returns the number of
 * gridded fields found in the message and the number (and maximum
 * size) of Local Use Sections.
 *
 * @author Stephen Gilbeert @date 2002-10-28
 */

#include <stdio.h>
#include <stdlib.h>
#include "grib2_int.h"

#define G2C_BYTES_TO_SEARCH 100 /**< Number of bytes to search for magic header 'GRIB'. */

/**
 * This subroutine searches through a GRIB2 message and returns the
 * number of gridded fields found in the message and the number (and
 * maximum size) of Local Use Sections. Also various checks are
 * performed to see if the message is a valid GRIB2 message.
 *
 * @param cgrib Pointer to a buffer containing the GRIB2 message.
 * @param listsec0 Pointer to an array that gets the information
 * decoded from GRIB Indicator Section 0. Must be allocated with >= 3
 * elements (see ::G2C_SECTION0_LEN).
 * - listsec0(0) Discipline-GRIB Master Table Number ([Code Table 0.0]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table0-0.shtml)).
 * - listsec0[1] GRIB Edition Number (currently 2).
 * - listsec0[2] Length of GRIB message.
 * @param listsec1 Pointer to an array that gets the information read
 * from GRIB Identification Section 1. Must be allocated with >= 13
 * elements (see ::G2C_SECTION1_LEN).
 * - listsec1[0] Id of orginating centre ([Table 0]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/on388/table0.html)).
 * - listsec1[1] Id of orginating sub-centre ([Table C]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/on388/tablec.html)).
 * - listsec1[2] GRIB Master Tables Version Number ([Table 1.0]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-0.shtml)).
 * - listsec1[3] GRIB Local Tables Version Number ([Table 1.1]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-1.shtml)).
 * - listsec1[4] Significance of Reference Time ([Table 1.2]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-1.shtml))
 * - listsec1[5] Reference Time - Year (4 digits)
 * - listsec1[6] Reference Time - Month
 * - listsec1[7] Reference Time - Day
 * - listsec1[8] Reference Time - Hour
 * - listsec1[9] Reference Time - Minute
 * - listsec1[10] Reference Time - Second
 * - listsec1[11] Production status of data ([Table 1.3]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-3.shtml)).
 * - listsec1[12] Type of processed data ([Table 1.4]
 *  (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-4.shtml)).
 * @param numfields A pointer that gets the number of gridded fields
 * found in the GRIB message. That is, the number of occurences of
 * Sections 4 - 7.
 * @param numlocal A pointer that gets the number of Local Use
 * Sections (section 2) found in the GRIB message.
 *
 * @returns 0 for success, otherwise:
 * - ::G2_INFO_NO_GRIB Beginning characters "GRIB" not found.
 * - ::G2_INFO_GRIB_VERSION GRIB message is not Edition 2.
 * - ::G2_INFO_NO_SEC1 Could not find Section 1, where expected.
 * - ::G2_INFO_WRONG_END End string "7777" found, but not where expected.
 * - ::G2_INFO_BAD_END End string "7777" not found at end of message.
 * - ::G2_INFO_INVAL_SEC Invalid section number found.
 *
 * @author Stephen Gilbeert @date 2002-10-28
 */
g2int
g2_info(unsigned char *cgrib, g2int *listsec0, g2int *listsec1,
        g2int *numfields, g2int *numlocal)
{
    int listsec0_int[G2C_SECTION0_LEN];
    int listsec1_int[G2C_SECTION1_LEN];
    int numfields_int, numlocal_int;
    int i;
    int ret;

    /* The g2c version of this function does the work. */
    ret = g2c_info(cgrib, listsec0_int, listsec1_int, &numfields_int,
                   &numlocal_int, NULL, NULL, NULL);

    /* Translate int types back to g2int. */
    *numfields = numfields_int;
    *numlocal = numlocal_int;
    for (i = 0; i < G2C_SECTION0_LEN; i++)
	listsec0[i] = listsec0_int[i];
    for (i = 0; i < G2C_SECTION1_LEN; i++)
	listsec1[i] = listsec1_int[i];

    /* Translate the error code, and print error message. */
    if (ret == G2C_ENOTGRIB2)
    {
        printf("g2_info: can only decode GRIB edition 2.");	
	return G2_INFO_GRIB_VERSION;
    }
    else if (ret == G2C_ENOTGRIB)
    {
        printf("g2_info:  Beginning characters GRIB not found.");
        return G2_INFO_NO_GRIB;
    }
    else if (ret == G2C_ENOSECTION1)
    {
        printf("g2_info: Could not find section 1.");
        return G2_INFO_NO_SEC1;
    }
    else if (ret == G2C_ENOEND)
    {
	printf("g2_info: '7777'  not found at end of GRIB message.\n");
	return G2_INFO_BAD_END;
    }
    else if (ret == G2C_EBADSECTION)
    {
	printf("g2_info: Invalid section number found in GRIB message\n");
	return G2_INFO_INVAL_SEC;
    }
    else if (ret == G2C_EBADEND)
    {
	printf("g2_info: '7777' found, but not where expected.\n");
	return G2_INFO_WRONG_END;
    }	
    return ret;
}

/**
 * Get information about a GRIB2 message.
 * 
 * This subroutine searches through a GRIB2 message and returns the
 * number of gridded fields found in the message and the number (and
 * maximum size) of Local Use Sections. Also various checks are
 * performed to see if the message is a valid GRIB2 message.
 *
 * @param cgrib Pointer to a buffer containing the GRIB2 message.
 * @param listsec0 Pointer to an array that gets the information
 * decoded from GRIB Indicator Section 0. Must be allocated with >= 3
 * elements (see ::G2C_SECTION0_LEN). Ignored if NULL.
 * - listsec0(0) Discipline-GRIB Master Table Number ([Code Table 0.0]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table0-0.shtml)).
 * - listsec0[1] GRIB Edition Number (currently 2).
 * - listsec0[2] Length of GRIB message.
 * @param listsec1 Pointer to an array that gets the information read
 * from GRIB Identification Section 1. Must be allocated with >= 13
 * elements (see ::G2C_SECTION1_LEN). Ignored if NULL.
 * - listsec1[0] Id of orginating centre ([Table 0]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/on388/table0.html)).
 * - listsec1[1] Id of orginating sub-centre ([Table C]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/on388/tablec.html)).
 * - listsec1[2] GRIB Master Tables Version Number ([Table 1.0]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-0.shtml)).
 * - listsec1[3] GRIB Local Tables Version Number ([Table 1.1]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-1.shtml)).
 * - listsec1[4] Significance of Reference Time ([Table 1.2]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-1.shtml))
 * - listsec1[5] Reference Time - Year (4 digits)
 * - listsec1[6] Reference Time - Month
 * - listsec1[7] Reference Time - Day
 * - listsec1[8] Reference Time - Hour
 * - listsec1[9] Reference Time - Minute
 * - listsec1[10] Reference Time - Second
 * - listsec1[11] Production status of data ([Table 1.3]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-3.shtml)).
 * - listsec1[12] Type of processed data ([Table 1.4]
 *  (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table1-4.shtml)).
 * @param numfields A pointer that gets the number of gridded fields
 * found in the GRIB message. That is, the number of occurences of
 * Sections 4 - 7. Ignored if NULL.
 * @param numlocal A pointer that gets the number of Local Use
 * Sections (section 2) found in the GRIB message. Ignored if NULL.
 * @param numsection A pointer that gets the number of sections in the
 * message. Ignored if NULL.
 * @param section_number A pointer that gets an array of the section
 * numbers in the message. This array must be allocated by the
 * caller. Ignored if NULL.
 * @param section_offset A pointer that gets an array of the byte offsets
 * to each section in the message. This array must be allocated by the
 * caller. Ignored if NULL.
 *
 * @returns 0 for success, otherwise:
 * - ::G2C_ENOTGRIB Beginning characters "GRIB" not found.
 * - ::G2C_ENOTGRIB2 GRIB message is not Edition 2.
 * - ::G2C_ENOSECTION1 Could not find Section 1, where expected.
 * - ::G2C_EBADEND End string "7777" found, but not where expected.
 * - ::G2C_ENOEND End string "7777" not found at end of message.
 * - ::G2C_EBADSECTION Invalid section number found.
 * - ::G2C_ENOMEM Out of memory.
 *
 * @author Ed Hartnett @date 2022-08-31
 */
int
g2c_info(unsigned char *cgrib, int *listsec0, int *listsec1,
	 int *numfields, int *numlocal, int *numsection, int *section_number,
         size_t *section_offset)
{
    int mapsec1[G2C_SECTION1_LEN] = {2, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1};
    int ipos, nbits, lensec;
    int offset, istart = -1, lengrib, lensec0, lensec1, secnum;
    int my_listsec0[G2C_SECTION0_LEN], my_listsec1[G2C_SECTION1_LEN];
    int my_numlocal = 0, my_numfields = 0;
    int ns = 0; /* number of sections */
    int my_section_number[G2C_MAX_NUM_SECTIONS];
    size_t my_section_offset[G2C_MAX_NUM_SECTIONS];
    int i;

    LOG((2, "g2c_info"));

    /* Check for beginning of GRIB message in the first 100 bytes. */
    for (i = 0; i < G2C_BYTES_TO_SEARCH; i++)
    {
        if (cgrib[i] == 'G' && cgrib[i + 1] == 'R' && cgrib[i + 2] == 'I' &&
            cgrib[i + 3] == 'B')
        {
            istart = i;
            break;
        }
    }
    if (istart == -1)
	return G2C_ENOTGRIB;

    LOG((3, "msg found at byte %d", istart));

    /* Unpack Section 0 - Indicator Section. */
    offset = BYTE * (istart + 6); /* Discipline starts at byte 7. */
    g2c_gbit_int(cgrib, &my_listsec0[0], offset, BYTE);     /* Discipline */
    offset += BYTE;
    g2c_gbit_int(cgrib, &my_listsec0[1], offset, BYTE);     /* GRIB edition number */
    offset += BYTE + WORD;
    g2c_gbit_int(cgrib, &lengrib, offset, WORD);        /* Length of GRIB message */
    offset += WORD;
    my_listsec0[2] = lengrib;
    lensec0 = G2C_SECTION0_BYTES;
    ipos = istart + lensec0;
    LOG((3, "unpacked section 0, lengrib %d now at byte %d", lengrib, ipos));
    my_section_number[ns] = 0;
    my_section_offset[ns] = istart;
    my_section_offset[ns + 1] = offset;
    ns++;
    
    /* This function handles only GRIB Edition 2. */
    if (my_listsec0[1] != 2)
	return G2C_ENOTGRIB2;

    /* Unpack Section 1 - Identification Section */
    g2c_gbit_int(cgrib, &lensec1, offset, WORD);        /* Length of Section 1 */
    offset += WORD;
    g2c_gbit_int(cgrib, &secnum, offset, BYTE);         /* Section number (1) */
    offset += BYTE;
    if (secnum != 1)
	return G2C_ENOSECTION1;

    /* Unpack each input value in array listsec1 into the
       appropriate number of octets, which are specified in
       corresponding entries in array mapsec1. */
    for (i = 0; i < G2C_SECTION1_LEN; i++)
    {
        nbits = mapsec1[i] * BYTE;
        g2c_gbit_int(cgrib, &my_listsec1[i], offset, nbits);
        offset += nbits;
    }
    ipos += lensec1;
    LOG((3, "unpacked section 1, now at byte %d", ipos));    
    my_section_number[ns] = 1;
    my_section_offset[ns + 1] = offset / BYTE;
    ns++;

    /* Loop through the remaining sections to see if they are
       valid. Also count the number of times Section 2 and Section 4
       appear. */
    for (;;)
    {
        if (cgrib[ipos] == '7' && cgrib[ipos + 1] == '7' && cgrib[ipos + 2] == '7' &&
            cgrib[ipos + 3] == '7')
        {
	    LOG((3, "found 7777 at byte %d", ipos));
            ipos += 4;
            if (ipos != (istart + lengrib))
		return G2C_EBADEND;
            my_section_number[ns] = 8;  /* Section 8 is the end of message. */
            break;
        }

        offset = ipos * BYTE;
        g2c_gbit_int(cgrib, &lensec, offset, WORD);        /* Get Length of Section */
        offset += WORD;
        g2c_gbit_int(cgrib, &secnum, offset, BYTE);         /* Get Section number */
	LOG((3, "found section number %d of length %d", secnum, lensec));
        offset += BYTE;
        ipos += lensec;                 /* Update beginning of section pointer */

        /* Remember this information. */
        my_section_number[ns] = (int)secnum;
        my_section_offset[ns + 1] = ipos;
        ns++;
        
        if (ipos > (istart + lengrib))
	    return G2C_ENOEND;

        if (secnum >= 2 && secnum <= 7)
        {
            /* Increment counter for total number of local sections
             * or fields found. */
            if (secnum == 2)
                my_numlocal++;
            else if (secnum == 4)
                my_numfields++;
        }
        else
	    return G2C_EBADSECTION;
    }

    /* Return values of interest to caller. */
    if (listsec0)
	for (i = 0; i < G2C_SECTION0_LEN; i++)
	    listsec0[i] = my_listsec0[i];
    if (listsec1)
	for (i = 0; i < G2C_SECTION1_LEN; i++)
	    listsec1[i] = my_listsec1[i];
    if (numlocal)
	*numlocal = my_numlocal;
    if (numfields)
	*numfields = my_numfields;
    if (numsection)
        *numsection = ns;
    if (section_number)
        for (i = 0; i < ns; i++)
            section_number[i] = my_section_number[i];
    if (section_offset)
        for (i = 0; i < ns; i++)
            section_offset[i] = my_section_offset[i];

    return G2C_NOERROR;
}
