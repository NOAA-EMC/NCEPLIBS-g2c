/** 
 * @file
 * @brief Write summary output to a file, as is done by utility
 * grb2index.
 *
 * @author Ed Hartnett @date Sep 17, 2022
 */
#include "grib2_int.h"
#include <stdarg.h>

/** Global file information. */
extern G2C_FILE_INFO_T g2c_file[G2C_MAX_FILES + 1];

/** Pointer to the list of code tables. */
extern G2C_CODE_TABLE_T *g2c_table;

/** Maximum length of "Type of first fixed surface" string. */
#define G2C_MAX_TYPE_OF_FIXED_SURFACE_LEN  40

/**
 * Convert date and time from GRIB2 info to string output.
 *
 * @note This function is based on the prvtime() function in
 * NCEPLIBS-grib_utils.
 *
 * @param[in] ipdtn Product Definition Template Number ([Code Table
 * 4.0]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table4-0.shtml)).
 * @param ipdtmpl Array of data values for the Product Definition
 * Template specified by ipdtn.
 * @param listsec1 Contains information read from GRIB
 * Identification Section 1. Must be dimensioned >= 13.
 * @param tabbrev Character array that will get the date and time
 * string. Must be of length 100.
 *
 * @author Ed Hartnett @date Sep 28, 2022
 */
static int
prvtime(int ipdtn, int *ipdtmpl, short year, unsigned char month, unsigned char day,
        unsigned char hour, unsigned char minute, unsigned char second, char *tabbrev)
{
    int iutpos, iutpos2, iunit, iunit2;
    char tunit[16], tunit2[16];
    char reftime[16];
    int itemp;
  /* character(len = 16) :: reftime, endtime */
  /* character(len = 10) :: tmpval, tmpval2 */
  /* character(len = 10) :: tunit, tunit2 */
  /* integer, dimension(200) :: ipos, ipos2 */
  /* integer :: is, itemp, itemp2, iunit, iuni2t2, iunit2, iutpos, iutpos2, j */
  
  /* data ipos  /7*0, 16, 23, 17, 19, 18, 32, 31, 27*0, 17, 20, 0, 0, 22,  & */
  /*      25, 43*0, 23, 109*0/ */

  /* data ipos2 /7*0, 26, 33, 27, 29, 28, 42, 41, 27*0, 22, 30, 0, 0, 32,  & */
  /*      35, 43*0, 33, 109*0/ */

  /* tabbrev(1:100) = " " */

    /* Check inputs. */
    assert(ipdtn >= 0 && ipdtmpl && tabbrev);

    /* The unit of time range is stored in the product template, but
     * stored at different places for different template numbers. Find
     * where it is stored for this product template number. */
    if (ipdtn <= 15 || ipdtn == 32 || ipdtn == 50 || ipdtn == 51 || ipdtn == 91) 
        iutpos = 7;
    else if (ipdtn >= 40 && ipdtn <= 43) 
        iutpos = 8;
    else if (ipdtn >= 44 && ipdtn <= 47)
        iutpos = 13;
    else if (ipdtn == 48)
        iutpos = 18;
    else if (ipdtn == 52)
        iutpos = 10;
    else
        iutpos = 7;

    /* Determine first unit of time range. */
    switch (ipdtmpl[iutpos])
    {
    case 0:
        strcpy(tunit, "minute");
        iunit = 1;
        break;
    case 1:
        strcpy(tunit, "hour");
        iunit = 1;
        break;
    case 2:
        strcpy(tunit, "day");
        iunit = 1;
        break;
    case 3:
        strcpy(tunit, "month");
        iunit = 1;
        break;
    case 4:
        strcpy(tunit, "year");
        iunit = 1;
        break;
    case 10:
        strcpy(tunit, "hour");
        iunit = 3;
        break;
    case 11:
        strcpy(tunit, "hour");
        iunit = 6;
        break;
    default:
        strcpy(tunit, "hour");
        iunit = 1;
    }

    /* Determine second unit of time range. */
    /* iutpos2 = ipos2[ipdtn]; */
    iutpos2 = 0;
    switch (ipdtmpl[iutpos2])
    {
    case 0:
        strcpy(tunit2, "minute");
        iunit2 = 1;
        break;
    case 1:
        strcpy(tunit2, "hour");
        iunit2 = 1;
        break;
    case 2:
        strcpy(tunit2, "day");
        iunit2 = 1;
        break;
    case 3:
        strcpy(tunit2, "month");
        iunit2 = 1;
        break;
    case 4:
        strcpy(tunit2, "year");
        iunit2 = 1;
        break;
    case 10:
        strcpy(tunit2, "hour");
        iunit2 = 3;
        break;
    case 11:
        strcpy(tunit2, "hour");
        iunit2 = 6;
        break;
    default:
        strcpy(tunit2, "hour");
        iunit2 = 1;
    }

    /* Write a string with the date and time from section 1 of the message. */
    sprintf(reftime, "%d%d%d%d:%d:%d", year, month, day, hour, minute, second);

    itemp = abs(ipdtmpl[iutpos + 1]) * iunit;
    
  /* write(tmpval, '(I0)') itemp */

    sprintf(tabbrev, "valid at  %d", ipdtmpl[iutpos + 1]);
  /* write(tabbrev, fmt = '("valid at  ", i4)') ipdtmpl(iutpos + 1) */

  /* Determine Reference Time: Year, Month, Day, Hour, Minute, Second. */
    
    if ((ipdtn >= 0 && ipdtn <= 7) || ipdtn == 15 || ipdtn == 20 || (ipdtn >= 30 && ipdtn <= 32) || ipdtn == 40 ||
        ipdtn == 41 || ipdtn == 44 || ipdtn == 45 || ipdtn == 48 || (ipdtn >= 50 && ipdtn <= 52)) /*  Point in time. */
    {
        sprintf(tabbrev, "valid  %d %s after %s", itemp, tunit, reftime);
    }
    else
    {
  /*    is = ipos(ipdtn) ! Continuous time interval */
  /*    write(endtime, fmt = '(i4,3i2.2,":",i2.2,":",i2.2)') (ipdtmpl(j), j = is, is + 5) */
  /*    if (ipdtn == 8 && ipdtmpl(9) .lt. 0) then */
  /*       tabbrev = "(" // trim(tmpval) // " -" // trim(tmpval2) // ") valid  " // trim(tmpval) // " " // trim(tunit) // " before " // reftime // " to " //endtime */

  /*                                             else if ((ipdtn >= 8 && ipdtn <= 14) || (ipdtn >= 42 && ipdtn <= 47) || ipdtn == 91) then /\* Continuous time interval *\/ */
  /*       itemp2 = abs (ipdtmpl(iutpos2 + 1)) * iunit2 */
  /*       itemp2 = itemp + itemp2 */
  /*       write(tmpval2, '(I0)') itemp2 */

  /*       tabbrev = "(" // trim(tmpval) // " -" // trim(tmpval2) // " hr) valid  " // trim(tmpval) // " " // trim(tunit) // " after " // reftime // " to " // endtime */

  /*    endif */
  /* endif */
    }

    return G2C_NOERROR;
}

/**
 * Determine the string that describes the level information, given
 * the GRIB2 Product Definition Template information.
 *
 * This subroutine finds the "Type of first fixed surface" (see [Code
 * table
 * 4.5](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_temp4-0.shtml))
 * using the product definition template value and product template
 * array. The location in the template array varies depending on the
 * template number.
 *
 * @param ipdtn Product Definition Template Number ([Code Table
 * 4.0]
 * (https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/grib2_table4-0.shtml)).
 * @param ipdtmpl Array of data values for the Product Definition
 * Template specified by ipdtn.
 * @param labbrev Character array which gets the string
 * describing the level. Must be of length 40.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date Sep 28, 2022
 */
static int
get_level_abbrev(int ipdtn, int *ipdtmpl, char *labbrev)
{
    int ipos;

    /* Check inputs. */
    assert(ipdtn >= 0 && ipdtmpl && labbrev);

    /* Use the template number to determine which element of the
     * product template array holds the "Type of first fixed surface"
     * value (which will be stored in ipos). */
    if (ipdtn <= 15)
        ipos = 9;
    else if (ipdtn >= 40 && ipdtn <= 43)
        ipos = 10;
    else if (ipdtn >= 44 && ipdtn <= 47)
        ipos = 15;
    else if (ipdtn == 48)
        ipos = 20;
    else if (ipdtn >= 50 && ipdtn <= 51)
        ipos = 9;
    else if (ipdtn == 52)
        ipos = 12;
    else if (ipdtn == 91)
        ipos = 9;
    else
        ipos = 9;

    /* Pressure Level. */
  if (ipdtmpl[ipos] == 100 && ipdtmpl[ipos + 3] == 255)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1) + 2) */
     /* labbrev = trim(tmpval1)//" mb" */
  }
  /* Pressure Layer. */
  else if (ipdtmpl[ipos] == 100 && ipdtmpl[ipos + 3] == 100)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1) + 2) */
     /* call frmt(tmpval2, ipdtmpl(ipos + 5), ipdtmpl(ipos + 4) + 2) */
     /* labbrev = trim(tmpval1)//" - "//trim(tmpval2)//" mb" */
  }
  else if (ipdtmpl[ipos] == 101)
  {
      strcpy(labbrev, " Mean Sea Level ");
  }
  /* Altitude above MSL. */
  else if (ipdtmpl[ipos] == 102 && ipdtmpl[ipos + 3] == 255)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* labbrev = trim(tmpval1)//" m above MSL" */
  }
  /* Height above Ground. */
  else if (ipdtmpl[ipos] == 103 && ipdtmpl[ipos + 3] == 255)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* labbrev = trim(tmpval1)//" m above ground" */
  }
  /* Height above Ground. */
  else if (ipdtmpl[ipos] == 103 && ipdtmpl[ipos + 3] == 103)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* call frmt(tmpval2, ipdtmpl(ipos + 5), ipdtmpl(ipos + 4)) */
     /* labbrev = trim(tmpval1)//" - "//trim(tmpval2)//" m AGL" */
  }
  /* Sigma Level. */
  else if (ipdtmpl[ipos] == 104 && ipdtmpl[ipos + 3] == 255)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* labbrev = trim(tmpval1)//" sigma" */
  }
  /* Sigma Layer. */
  else if (ipdtmpl[ipos] == 104 && ipdtmpl[ipos + 3] == 104)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* call frmt(tmpval2, ipdtmpl(ipos + 5), ipdtmpl(ipos + 4)) */
     /* labbrev = trim(tmpval1)//" - "//trim(tmpval2)//" sigma" */
  }
  /* Hybrid Level. */
  else if (ipdtmpl[ipos] == 105 && ipdtmpl[ipos + 3] == 255)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* labbrev = trim(tmpval1)//" hybrid lvl" */
  }
  /* Hybrid Level. */
  else if (ipdtmpl[ipos] == 105 && ipdtmpl[ipos + 3] == 105)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* call frmt(tmpval2, ipdtmpl(ipos + 5), ipdtmpl(ipos + 4)) */
     /* labbrev = trim(tmpval1)//" - "//trim(tmpval2)//" hybrid lvl" */
  }
  /* Depth Below Land Sfc. */
  else if (ipdtmpl[ipos] == 106 && ipdtmpl[ipos + 3] == 255)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* labbrev = trim(tmpval1)//" m below land" */
  }
  /* Depth Below Land Sfc Layer. */
  else if (ipdtmpl[ipos] == 106 && ipdtmpl[ipos + 3] == 106)
  {
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)) */
     /* call frmt(tmpval2, ipdtmpl(ipos + 5), ipdtmpl(ipos + 4)) */
     /* labbrev = trim(tmpval1)//" - "//trim(tmpval2)//" m DBLY" */
  }
  else if (ipdtmpl[ipos] == 107)
  {
      strcpy(labbrev, " Isentropic level");
  }
  /* Press Diff from Ground Layer. */
  else if (ipdtmpl[ipos] == 108 && ipdtmpl[ipos + 3] == 108)
  {
      /* write(tmpval1, *) ipdtmpl(ipos + 2)/100. */
      /* write(tmpval2, *) ipdtmpl(ipos + 5)/100. */
     /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1) + 2) */
     /* call frmt(tmpval2, ipdtmpl(ipos + 5), ipdtmpl(ipos + 4) + 2) */
     /* labbrev = trim(tmpval1)//" - "//trim(tmpval2)//" mb SPDY" */
  }
  else if (ipdtmpl[ipos] == 110)
  {
      strcpy(labbrev, " Layer bet 2-hyb lvl");
  }
  /* Potential Vorticity Sfc. */
  else if (ipdtmpl[ipos] == 109 && ipdtmpl[ipos + 3] == 255)
  {
      /* write(tmpval1, *) ipdtmpl(ipos + 2). */
      /* call frmt(tmpval1, ipdtmpl(ipos + 2), ipdtmpl(ipos + 1)-6) */
      /*     labbrev = trim(tmpval1)//" pv surface" */
  }
  else if (ipdtmpl[ipos] == 111)
      strcpy(labbrev, " Eta level");
  else if (ipdtmpl[ipos] == 114)
      strcpy(labbrev, " Layer bet. 2-isent.");
  else if (ipdtmpl[ipos] == 117)
      strcpy(labbrev, " Mixed layer depth");
  else if (ipdtmpl[ipos] == 120)
      strcpy(labbrev, " Layer bet. 2-Eta lvl");
  else if (ipdtmpl[ipos] == 121)
      strcpy(labbrev, " Layer bet. 2-isob.");
  else if (ipdtmpl[ipos] == 125)
      strcpy(labbrev, " Specified height lvl");
  else if (ipdtmpl[ipos] == 126)
      strcpy(labbrev, " Isobaric level");
  else if (ipdtmpl[ipos] == 160)
      strcpy(labbrev, " Depth below sea lvl");
  else if (ipdtmpl[ipos] == 170)
      strcpy(labbrev, " Ionospheric D-region lvl");
  else if (ipdtmpl[ipos] == 1)
      strcpy(labbrev, " Surface ");
  else if (ipdtmpl[ipos] == 2)
      strcpy(labbrev, " Cloud base lvl");
  else if (ipdtmpl[ipos] == 3)
      strcpy(labbrev, " Cloud top lvl");
  else if (ipdtmpl[ipos] == 4)
      strcpy(labbrev, " 0 Deg Isotherm");
  else if (ipdtmpl[ipos] == 5)       /* from the surface. */
      strcpy(labbrev, " Level of adiabatic"     );
  else if (ipdtmpl[ipos] == 6)
      strcpy(labbrev, " Max wind lvl");
  else if (ipdtmpl[ipos] == 7)
      strcpy(labbrev, " Tropopause");
  else if (ipdtmpl[ipos] == 8)
      strcpy(labbrev, " Nom. top");
  else if (ipdtmpl[ipos] == 9)
      strcpy(labbrev, " Sea Bottom");
  else if (ipdtmpl[ipos] == 10)
      strcpy(labbrev, " Entire Atmosphere");
  else if (ipdtmpl[ipos] == 11)
      strcpy(labbrev, " Cumulonimbus Base");
  else if (ipdtmpl[ipos] == 12)
      strcpy(labbrev, " Cumulonimbus Top");
  else if (ipdtmpl[ipos] == 20)
      strcpy(labbrev, " Isothermal level");
  else if (ipdtmpl[ipos] == 200)
      strcpy(labbrev, " Entire Atmosphere");
  else if (ipdtmpl[ipos] == 201)
      strcpy(labbrev, " Entire ocean");
  else if (ipdtmpl[ipos] == 204)
      strcpy(labbrev, " Highest Frz. lvl");
  else if (ipdtmpl[ipos] == 206)
      strcpy(labbrev, " Grid scale cloud bl");
  else if (ipdtmpl[ipos] == 207)
      strcpy(labbrev, " Grid scale cloud tl");
  else if (ipdtmpl[ipos] == 209)
      strcpy(labbrev, " Boundary layer cbl");
  else if (ipdtmpl[ipos] == 210)
      strcpy(labbrev, " Boundary layer ctl");
  else if (ipdtmpl[ipos] == 211)
      strcpy(labbrev, " Boundary layer cl");
  else if (ipdtmpl[ipos] == 212)
      strcpy(labbrev, " Low cloud bot. lvl");
  else if (ipdtmpl[ipos] == 213)
      strcpy(labbrev, " Low cloud top lvl");
  else if (ipdtmpl[ipos] == 214)
      strcpy(labbrev, " Low cloud layer");
  else if (ipdtmpl[ipos] == 215)
      strcpy(labbrev, " Cloud ceiling");
  else if (ipdtmpl[ipos] == 220)
      strcpy(labbrev, " Planetary boundary");
  else if (ipdtmpl[ipos] == 221)
      strcpy(labbrev, " Layer 2 Hybrid lvl ");
  else if (ipdtmpl[ipos] == 222)
      strcpy(labbrev, " Mid. cloud bot. lvl");
  else if (ipdtmpl[ipos] == 223)
      strcpy(labbrev, " Mid. cloud top lvl");
  else if (ipdtmpl[ipos] == 224)
      strcpy(labbrev, " Middle cloud layer");
  else if (ipdtmpl[ipos] == 232)
      strcpy(labbrev, " High cloud bot. lvl");
  else if (ipdtmpl[ipos] == 233)
      strcpy(labbrev, " High cloud top lvl");
  else if (ipdtmpl[ipos] == 234)
      strcpy(labbrev, " High cloud layer");
  else if (ipdtmpl[ipos] == 235)
      strcpy(labbrev, " Ocean Isotherm lvl");
  else if (ipdtmpl[ipos] == 236)
      strcpy(labbrev, " Layer 2-depth below");
  else if (ipdtmpl[ipos] == 237)
      strcpy(labbrev, " Bot. Ocean mix. lyr");
  else if (ipdtmpl[ipos] == 238)
      strcpy(labbrev, " Bot. Ocean iso. lyr");
  else if (ipdtmpl[ipos] == 239)       /* isothermal level (S26CY). */
      strcpy(labbrev, " layer ocean sfc 26C"    );
  else if (ipdtmpl[ipos] == 240)
      strcpy(labbrev, " Ocean Mixed Layer");
  else if (ipdtmpl[ipos] == 241)
      strcpy(labbrev, " Order Seq. Of Data");
  else if (ipdtmpl[ipos] == 242)
      strcpy(labbrev, " Con. cloud bot. lvl");
  else if (ipdtmpl[ipos] == 243)
      strcpy(labbrev, " Con. cloud top lvl");
  else if (ipdtmpl[ipos] == 244)
      strcpy(labbrev, " Conv. cloud layer");
  else if (ipdtmpl[ipos] == 245)
      strcpy(labbrev, " Lowest lvl wet bulb");
  else if (ipdtmpl[ipos] == 246)
      strcpy(labbrev, " Max. equi. potential");
  else if (ipdtmpl[ipos] == 247)
      strcpy(labbrev, " Equilibrium level");
  else if (ipdtmpl[ipos] == 248)
      strcpy(labbrev, " Shallow con. cld bl");
  else if (ipdtmpl[ipos] == 249)
      strcpy(labbrev, " Shallow con. cld tl");
  else if (ipdtmpl[ipos] == 251)
      strcpy(labbrev, " Deep conv. cld bl");
  else if (ipdtmpl[ipos] == 252)
      strcpy(labbrev, " Deep conv. cld tl");
  else if (ipdtmpl[ipos] == 253)       /* liquid water layer (LBLSW). */
      strcpy(labbrev, " Lowest bot. lvl sup"    );
  else if (ipdtmpl[ipos] == 254)       /* liquid water layer (HBLSW). */
      strcpy(labbrev, " highest top lvl sup"    );
  else
  {
     /* write(labbrev, fmt = '(1x,I4," (Unknown Lvl)")') ipdtmpl[ipos] */
  }

  return G2C_NOERROR;
}

/**
 * Write a summary file like the degrib2 utility.
 *
 * @param g2cid Indentifier for the file, returned by g2c_open() or
 * g2c_create().
 * @param fileout Path of output file. Any existing file of this name
 * will be overwritten.
 *
 * @return
 * - ::G2C_NOERROR No error.
 * - ::G2C_EINVAL Invalid parameters.
 * - ::G2C_EFILE File I/O error.
 *
 * @author Ed Hartnett @date Sep 17, 2022
 */
int
g2c_write_grib2_index(int g2cid, const char *fileout)
{
    FILE *f;
    G2C_MESSAGE_INFO_T *msg;
    int ret;

    /* Check inputs. */
    if (g2cid > G2C_MAX_FILES)
	return G2C_EBADID;
    if (g2c_file[g2cid].g2cid != g2cid)
	return G2C_EBADID;
    if (!fileout)
        return G2C_EINVAL;
    
    /* Open output file. */
    if (!(f = fopen(fileout, "w")))
        return G2C_EFILE;

    /* Print a summary for each message in the file. */
    for (msg = g2c_file[g2cid].msg; msg; msg = msg->next)
    {
        int fld;
        
        fprintf(f, "\n");
        fprintf(f, " GRIB MESSAGE  %-2ld starts at %ld\n", msg->msg_num + 1, msg->bytes_to_msg + 1);
        fprintf(f, "\n");
        fprintf(f, "  SECTION 0:  %d 2 %ld\n", msg->discipline, msg->bytes_in_msg);
        fprintf(f, "  SECTION 1:  %d %d %d %d %d %d %d %d %d %d %d %d %d\n", msg->center, msg->subcenter,
                msg->master_version, msg->local_version, msg->sig_ref_time, msg->year, msg->month, msg->day,
                msg->hour, msg->minute, msg->second, msg->status, msg->type);
        fprintf(f, "  Contains  %d  Local Sections  and  %d  data fields.\n", msg->num_local, msg->num_fields);

        /* For each field, print info. */
        for (fld = 0; fld < msg->num_fields; fld++)
        {
            G2C_SECTION_INFO_T *sec, *sec3;
            G2C_SECTION3_INFO_T *sec3_info;
            G2C_SECTION4_INFO_T *sec4_info;
            char abbrev[G2C_MAX_NOAA_ABBREV_LEN + 1];
            char labbrev[G2C_MAX_TYPE_OF_FIXED_SURFACE_LEN + 1];
            char tabbrev[100 + 1];
            int t;
            
            fprintf(f, "\n");
            fprintf(f, "  FIELD  %d\n", fld + 1);
            fprintf(f, "  SECTION 0:  %d 2\n", msg->discipline);
            fprintf(f, "  SECTION 1:  %d %d %d %d %d %d %d %d %d %d %d %d %d\n", msg->center, msg->subcenter,
                msg->master_version, msg->local_version, msg->sig_ref_time, msg->year, msg->month, msg->day,
                msg->hour, msg->minute, msg->second, msg->status, msg->type);

            /* Find this field (a.k.a. product, a.k.a. section 4). */
            for (sec = msg->sec; sec; sec = sec->next)
                if (sec->sec_num == 4 && ((G2C_SECTION4_INFO_T *)(sec->sec_info))->field_num == fld)
                    break;
            if (!sec)
                return G2C_ENOSECTION;

            /* Find the sec3 that applies to this field. */
            for (sec3 = sec; sec3; sec3 = sec3->prev)
                if (sec3->sec_num == 3)
                    break;
            if (!sec3)
                return G2C_ENOSECTION;

            /* Print the section 3 (grid) info. */
            sec3_info = (G2C_SECTION3_INFO_T *)sec3->sec_info;
            fprintf(f, "  SECTION 3:  %d %d %d %d %d\n", sec3_info->source_grid_def, sec3_info->num_data_points, sec3_info->num_opt,
                    sec3_info->interp_list, sec3_info->grid_def);
            fprintf(f, "  GRID TEMPLATE 3. %d : ", sec3_info->grid_def);
            for (t = 0; t < sec3->template_len; t++)
                fprintf(f, " %d", sec3->template[t]);
            fprintf(f, "\n");
            if (!sec3_info->optional)
                fprintf(f, "  NO Optional List Defining Number of Data Points.\n");

            /* Print the section 4 (product) info. */
            sec4_info = (G2C_SECTION4_INFO_T *)sec->sec_info;
            fprintf(f, "  PRODUCT TEMPLATE 4. %d: ", sec4_info->prod_def);

            /* We can look up the parameter abbreviation with the
             * discipline and the first two elements of the product
             * template, which will be the category and product
             * number. */
            if ((ret = g2c_param_abbrev(msg->discipline, sec->template[0], sec->template[1], abbrev)))
                return ret;
            fprintf(f, "( PARAMETER = %-8s %d %d %d ) ", abbrev, sec4_info->prod_def, sec->template[0], sec->template[1]);
            for (t = 0; t < sec->template_len; t++)
                fprintf(f, " %d", sec->template[t]);
            fprintf(f, "\n");
            if ((ret = get_level_abbrev(sec4_info->prod_def, sec->template, labbrev)))
                return ret;
            if ((ret = prvtime(sec4_info->prod_def, sec->template, msg->year, msg->month, msg->day,
                               msg->hour, msg->minute, msg->second, tabbrev)))
                return ret;
            fprintf(f, "  FIELD: %-8s %s valid  0 hour after 2021113000:00:00\n", abbrev, labbrev);

            if (!sec4_info->num_coord)
                fprintf(f, "  NO Optional Vertical Coordinate List.\n");
        }
    }

    /* Close output file. */
    if (fclose(f))
        return G2C_EFILE;
    
    return G2C_NOERROR;
}
