/* This is a test for the NCEPLIBS-g2c project. This test is for
 * g2cparams.c.
 *
 * Ed Hartnett 9/19/22
 */
#include "grib2_int.h"

int
main()
{
    printf("Testing params handling.\n");

    printf("Testing g2c_param_abbrev()...");
    {
        char abbrev[G2C_MAX_NOAA_ABBREV_LEN + 1];
        int ret;

        /* /\* This will succeed, but accomplish nothing. *\/ */
        /* if ((ret = g2c_param_abbrev(0, 3, 0, NULL))) */
        /*     return ret; */

        /* /\* This will work. *\/ */
        /* if ((ret = g2c_param_abbrev(0, 3, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PRES")) */
        /*     return G2C_ERROR; */
        
        /* if ((ret = g2c_param_abbrev(0, 3, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PRES")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PRMSL")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PTEND")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 14, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PVORT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ICAHT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "GP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "HGT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 6, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DIST")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 7, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "HSTDV")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 14, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TOZNE")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TMP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VTMP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "POT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "EPOT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TMAX")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TMIN")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 6, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DPT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 7, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DEPR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 8, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "LAPR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 19, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VIS")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 15, 6, abbrev))) */
        /*     return ret; */

























        /* if (strcmp(abbrev, "RDSP1")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 15, 7, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "RDSP2")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 15, 8, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "RDSP3")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 7, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PLI")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 9, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TMPA")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 8, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PRESA")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 9, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "GPA")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WVSP1")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WVSP2")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WVSP3")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WDIR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WIND")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "UGRD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VGRD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "STRM")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VPOT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 6, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "MNTSF")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 7, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SGCVV")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 8, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VVEL")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 9, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DZDT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 10, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ABSV")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 11, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ABSD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 12, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "RELV")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 13, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "RELD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 15, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VUCSH")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 16, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VVCSH")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 1, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DIRC")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 1, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SPC")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 1, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "UOGRD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 1, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VOGRD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SPFH")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "RH")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "MIXR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PWAT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VAPP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SATD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 6, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "EVP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 6, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "CICE")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 7, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PRATE")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 19, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TSTM")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 8, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "APCP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 9, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "NCPCP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 10, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ACPCP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 12, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SRWEQ")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 13, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WEASD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 11, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SNOD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 19, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "MIXHT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 4, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TTHDP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 4, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "MTHD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 4, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "MTHA")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 6, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TCDC")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 6, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "CDCON")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 6, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "LCDC")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 6, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "MCDC")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 6, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "HCDC")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 6, 6, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "CWAT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 7, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "BLI")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 14, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SNOC")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 15, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SNOL")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 3, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WTMP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(2, 0, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "LAND")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 3, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DSLM")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(2, 0, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SFCR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 19, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ALBDO")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(2, 0, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "TSOIL")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(2, 0, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SOILM")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(2, 0, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VEG")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 4, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SALTY")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 3, 10, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DEN")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(2, 0, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WATR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 2, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ICEC")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 2, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ICETK")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 2, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DICED")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 2, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SICED")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 2, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "UICE")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 2, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VICE")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 2, 6, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ICEG")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 2, 7, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "ICED")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 16, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SNOM")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "HTSGW")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WVDIR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WVHGT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 6, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WVPER")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 7, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SWDIR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 8, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SWELL")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 9, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SWPER")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 10, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DIRPW")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 11, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PERPW")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 12, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "DIRSW")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(10, 0, 13, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "PERSW")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 4, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "NSWRS")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 5, 0, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "NLWRS")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 4, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "NSWRT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 5, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "NLWRT")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 5, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "LWAVR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 4, 2, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SWAVR")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 4, 3, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "GRAD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 4, 4, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "BRTMP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 4, 5, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "LWRAD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 4, 6, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SWRAD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 10, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "LHTFL")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 11, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SHTFL")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 20, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "BLYDP")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 17, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "UFLX")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 18, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "VFLX")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 2, 19, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "WMIXE")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(255, 255, 255, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "IMGD")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 0, 192, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "SNOHF")) */
        /*     return G2C_ERROR; */
        /* if ((ret = g2c_param_abbrev(0, 1, 22, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "CLWMR")) */
        /*     return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CRAIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CFRZR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CICEP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CSNOW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CPRAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MCONV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 1, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CPOFP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PEVAP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VWSH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "USTM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VSTM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FRICV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MSLET")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DSWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "USWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DLWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ULWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CDLYR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "4LFTX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CAPE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HLCY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LFTX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TKE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ELON")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BGRUN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSRUN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GFLUX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MSTAV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SFEXC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNWAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BMIXL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "O3MR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "5WAVH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PEVPR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CWORK")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "U-GWD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "V-GWD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HPBL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "5WAVA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RLYRS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WILT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SLTYP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOTYP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VGTYP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SMREF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SMDRY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOWC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "POROS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FRAIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RIME")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CUEFI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCOND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCOLW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCOLI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCOLR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 205, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCOLS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCOLC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MXSALB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNFALB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 24, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RWMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 25, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CCOND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RSMIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RCS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RCT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RCQ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 205, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RCSOL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 1, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "USCT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 1, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VSCT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TSEC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OZCON")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OZCAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 1, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "POP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 1, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CPOZP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 22, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GUST")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WIND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HTSGW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVPER")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIRPW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PERPW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIRSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PERSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 13, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PMTC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 13, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PMTF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MSLMA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 13, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LPMTF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 13, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LIPMF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 23, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 32, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GRMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 206, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TIPD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 17, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LTNG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 206, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RDRIP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 15, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VPTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 207, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NCIP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 208, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOT")) */
       /*      return G2C_ERROR; */
       /*  /\* See https://github.com/NOAA-EMC/NCEPLIBS-g2/issues/314. *\/ */
       /*  /\* if ((ret = g2c_param_abbrev(0, 3, 1, abbrev))) *\/ */
       /*  /\*     return ret; *\/ */
       /*  /\* if (strcmp(abbrev, "MSLSA")) *\/ */
       /*  /\*     return G2C_ERROR; *\/ */
       /*  if ((ret = g2c_param_abbrev(0, 3, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TSLSA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PLPL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DUVB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CDUVB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 207, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICWAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MIXLY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TTRAD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 16, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "REFD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 16, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "REFC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CSDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 209, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCLSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 210, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCOLM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LPSX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LPSY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HGTX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HGTY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "REV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICEC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UOGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VOGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DSLM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SALTY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UOGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VOGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SALTY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DZDT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MIXHT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PRMSL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HGT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ELEV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MINRH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 27, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MAXRH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 29, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ASNOW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 16, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "REFZR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 16, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "REFZI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 16, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "REFZC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAUV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LOUV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LOVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAPP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LOPP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSHG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PRMSL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HGT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WTMPC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SALIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "P2OMLT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OMLU")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OMLV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UBARO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VBARO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 205, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FLGHT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 206, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CICEL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 207, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CIVIS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 208, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CIFLT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 209, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAVNI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 210, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HAVNI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 211, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBSALB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 212, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWSALB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 213, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NBSALB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 214, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NWSALB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WSTP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 211, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EMNP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 205, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAYTH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CEIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PBLREG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 228, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACOND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 212, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBSNO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EVBS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 229, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EVCW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 230, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TRANS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VEDH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LRGHR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNVHR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 20, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICIP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 20, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICIP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 21, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CTP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 21, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CTP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 22, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 22, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 25, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CBHE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(255, 255, 255, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMGD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(255, 255, 255, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMGD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(255, 255, 255, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMGD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(255, 255, 255, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMGD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICAHT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICAHT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(255, 255, 255, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMGD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(255, 255, 255, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMGD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CWAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWELL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWPER")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVHGT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBT122")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBT123")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBT124")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBT126")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBC123")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBC124")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SURGE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ETSRG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 14, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PVORT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVMZ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVTZ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVTM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "THFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DZDT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 17, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 18, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIST")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "POT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SALTY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UOGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VOGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TTDIA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TTPHY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LSPA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWHR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LWHR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CSUSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CSULF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CSDLF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CFNSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CFNLF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VBDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VDDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NBDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NDDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UVI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TSD1D")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 206, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLGSP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SHAHR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VDFHR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 213, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNVMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 214, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SHAMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 215, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VDFMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 208, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VDFUA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 209, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VDFVA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CWDI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DTRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 205, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UTRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MFLUX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CWDI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 232, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VAFTD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOWC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "KX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BKENG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DBSS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AOHFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ASHFL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSTT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSST")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "KENG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "INTFD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SLTFL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OHC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 216, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CONP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MLYNO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 65, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RPRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 66, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SPRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 67, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FPRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 68, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IPRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UPHL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VEG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 1, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CWR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVTW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVZZ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVMM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVQZ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVQM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVTVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVQVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVPSPS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVQQ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVVVVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 192, 14, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "COVTT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "THZ0")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 218, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "QZ0")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 219, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "QMAX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 220, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "QMIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 210, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GWDU")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 211, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GWDV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 212, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNVU")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 213, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 214, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WTEND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 215, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OMGALF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 216, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNGWDU")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 217, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNGWDV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 207, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNVUMF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 208, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNVDMF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 209, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNVDEMF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 217, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LRGMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VDFOZ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "POZ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TOZ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "POZT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "POZO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 208, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AKHS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 209, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AKMS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 218, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EPSR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOHF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCHP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 219, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TPFI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 210, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LMH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 218, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LMV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PRES")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PRMSL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PTEND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 14, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PVORT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICAHT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HGT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIST")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HSTDV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TOZNE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "POT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EPOT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TMAX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TMIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DPT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DEPR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAPR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VIS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RDSP1")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RDSP2")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RDSP3")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PLI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TMPA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PRESA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GPA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVSP1")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVSP2")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVSP3")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WIND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "STRM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VPOT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MNTSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SGCVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VVEL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DZDT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ABSV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ABSD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RELV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RELD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 15, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VUCSH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 16, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VVCSH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIRC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SPC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UOGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 1, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VOGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SPFH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MIXR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PWAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VAPP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SATD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EVP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TSTM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "APCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NCPCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACPCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SRWEQ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WEASD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MIXHT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TTHDP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MTHD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MTHA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCDC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CDCON")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LCDC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MCDC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HCDC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CWAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BLI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 14, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 15, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DSLM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SFCR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ALBDO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TSOIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VEG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SALTY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DEN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WATR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICEC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICETK")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DICED")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SICED")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICEG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICED")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 16, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HTSGW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVHGT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVPER")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWELL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWPER")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIRPW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PERPW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIRSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PERSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NSWRS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLWRS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NSWRT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLWRT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LWAVR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWAVR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GRAD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BRTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LWRAD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWRAD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LHTFL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SHTFL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 20, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BLYDP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 17, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 18, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 19, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WMIXE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(255, 255, 255, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMGD")) */
       /*      return G2C_ERROR; */
       /*  /\\* See https://github.com/NOAA-EMC/NCEPLIBS-g2/issues/314. *\\/ */
       /*  /\\* if ((ret = g2c_param_abbrev(0, 3, 1, abbrev))) *\\/ */
       /*  /\\*     return ret; *\\/ */
       /*  /\\* if (strcmp(abbrev, "MSLSA")) *\\/ */
       /*  /\\*     return G2C_ERROR; *\\/ */
       /*  if ((ret = g2c_param_abbrev(0, 3, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MSLET")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LFTX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "4LFTX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 212, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PRESN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MCONV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VWSH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 219, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PVMWW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CRAIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CFRZR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CICEP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CSNOW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PEVPR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 210, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VEGT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BARET")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AVSFT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RADT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 211, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSTOR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 212, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LSOIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 213, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EWATR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 22, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CLWMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GFLUX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CAPE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TKE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MXSALB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 29, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ASNOW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 221, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ARAIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 214, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GWREC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 215, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "QREC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 222, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOWT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VBDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VDDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 202, abbrev))) */
       /*      return ret; */
       /* if (strcmp(abbrev, "NBDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NDDSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNFALB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RLYRS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 210, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LMH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 218, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LMV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MLYNO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ELON")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 23, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 228, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACOND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 17, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOAG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CCOND")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LAI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 216, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SFCRH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 19, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SALBD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 217, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NDVI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 206, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RDRIP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 218, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LANDN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HLCY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLATN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 191, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ELONN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 1, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CPOFP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "USTM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VSTM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 212, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBSNO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EVBS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 229, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EVCW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 223, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "APCPN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RSMIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DSWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DLWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 224, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACPCPN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MSTAV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SFEXC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 230, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TRANS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "USWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ULWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CDLYR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CPRAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TTRAD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 211, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HGTN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WILT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FLDCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HPBL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SLTYP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CNWAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOTYP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VGTYP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BMIXL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 219, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AMIXL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PEVAP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOHF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 195, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SMREF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SMDRY")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 220, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVINC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 221, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WCINC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BGRUN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 193, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSRUN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 222, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVCONV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOWC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 208, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "POROS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 223, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WCCONV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 224, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVUFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 225, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVVFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 226, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WCUFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 227, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WCVFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RCS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RCT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RCQ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 205, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RCSOL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWHR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LWHR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 196, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FRICV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NCPCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACPCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FLDCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 200, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OZMAX1")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OZMAX8")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 16, 197, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RETOP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 201, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SUNSD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 202, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PDMAX1")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 14, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PDMAX24")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 242, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCSRG20")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 243, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCSRG30")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 244, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCSRG40")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 245, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCSRG50")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 246, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCSRG60")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 247, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCSRG70")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 248, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCSRG80")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 249, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCSRG90")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PRES")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACPCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "APCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ABSV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HTSGW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WVPER")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWELL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIRPW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PERPW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DIRSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PERSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 191, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MOSF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 225, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FRZR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 227, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FROZR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 241, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TSNOW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MTERH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OVHD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OVSD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 4, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "OVMD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SRWEQ")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBT112")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBT113")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBT114")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBT115")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 16, 198, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MAXREF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 199, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MXUPHL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 220, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MAXUVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 221, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MAXDVV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 222, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MAXUW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 223, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MAXVW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 224, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HINDEX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 234, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICSEV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 233, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICPRB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 217, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SIPD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 242, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RHPW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 255, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MISSING")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 102, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AOTK")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 103, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSALBK")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 104, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ASYSFK")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 105, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AECOEF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 106, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AACOEF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 107, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ALBSAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 108, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ALBGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 109, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ALESAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 110, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ALEGRD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WLSMFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WDCPMFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SEDMFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DDMFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TRANHH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 14, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TRSDS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 59, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ANCON")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 21, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "APTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 17, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LTNGSD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 39, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CPOFP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 3, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LCH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 20, 101, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ATMTK")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 37, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CPRAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 2, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICETMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 28, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UCTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 0, 29, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TMPADV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 129, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFRCWAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 130, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFRRAIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 131, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFRCICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 132, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFRSNOW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 133, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFRGRL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 134, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFRHAIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 135, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFRSLC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 136, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFRSICEC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 137, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFARRAIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 138, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFARCICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 139, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFARSNOW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 140, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFARGRL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 141, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFARHAIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 142, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFARSIC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 231, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PPINDX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 232, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PROBCIP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 233, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SNOWLR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 234, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PCPDUR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 1, 235, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CLLMR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 231, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TPWDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 232, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TPWSPD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 2, 36, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AFRWE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 20, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SDSGSO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 21, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "AOSGSO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 22, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSGSO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 23, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GWD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 24, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ASGSO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 25, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLPRES")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 26, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EXPRES")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 27, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UMFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 28, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DMFLX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 29, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UDRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 30, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DDRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 3, 31, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UCLSPRS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 50, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UVIUCS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 52, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DSWRFCS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 4, 53, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "USWRFCS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLWRF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NLWRCS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "BRTEMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 5, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DLWRFCS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 34, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SLWTC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 35, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSWTC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 36, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FSTRPC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 37, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FCONPC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 38, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MASSDCD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 39, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MASSDCI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 40, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MDCCWD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 47, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VFRCWD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 48, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VFRCICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 6, 49, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VFRCIW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 19, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CONAPES")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 203, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DCAPE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 204, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EFHL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 205, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ESP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 206, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CANGLE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 7, 206, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CANGLE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RFCD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RFCI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RFSNOW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RFRAIN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RFGRPL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 14, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RFHAIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 15, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HSR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 15, 16, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HSRHT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 17, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LTPINX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 17, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CDGDLTFD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 17, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CDCDLTFD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 17, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TLGTFD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 18, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACCES")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 18, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACIOD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 18, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACRADP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 28, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MWTURB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 29, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CATEDR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 30, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EDPARM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 31, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MXEDPRM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 32, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "HIFREL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 33, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VISLFOG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 34, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VISIFOG")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 35, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VISBSN")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 36, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PSNOWS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 37, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICESEV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(0, 19, 238, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ELLINX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DISRS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GWUPS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GWLOWS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SFLORC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "RVERSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FLDPSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DEPWSS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 14, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UPAPCP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 15, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "UPASM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 0, 16, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PERRATE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WDPTHIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WTMPIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WFRACT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SEDTK")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SEDTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICTKIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICETIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ICECIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LANDIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SFSAL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SFTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "ACWSR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 12, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SALTIL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(1, 2, 13, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CSAFC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 35, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TCLASS")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 36, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TFRCT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 37, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "TPERCT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 38, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILVIC")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 0, 39, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "EVAPTRAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 1, 192, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CANL")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 18, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 19, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILMOI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 20, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CISOILM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 21, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SOILICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 22, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CISICE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 3, 23, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "LWSNWP")) */
       /*      return G2C_ERROR; */
       /*  /\\* if ((ret = g2c_param_abbrev(2, 3, 23, abbrev))) *\\/ */
       /*  /\\*     return ret; *\\/ */
       /*  /\\* if (strcmp(abbrev, "FRSTINX")) *\\/ */
       /*  /\\*     return G2C_ERROR; *\\/ */
       /*  /\\* if ((ret = g2c_param_abbrev(2, 3, 23, abbrev))) *\\/ */
       /*  /\\*     return ret; *\\/ */
       /*  /\\* if (strcmp(abbrev, "SNWDEB")) *\\/ */
       /*  /\\*     return G2C_ERROR; *\\/ */
       /*  /\\* if ((ret = g2c_param_abbrev(2, 3, 23, abbrev))) *\\/ */
       /*  /\\*     return ret; *\\/ */
       /*  /\\* if (strcmp(abbrev, "SHFLX")) *\\/ */
       /*  /\\*     return G2C_ERROR; *\\/ */
       /*  /\\* if ((ret = g2c_param_abbrev(2, 3, 23, abbrev))) *\\/ */
       /*  /\\*     return ret; *\\/ */
       /*  /\\* if (strcmp(abbrev, "SOILDEP")) *\\/ */
       /*  /\\*     return G2C_ERROR; *\\/ */
       /*  if ((ret = g2c_param_abbrev(2, 4, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FIREOLK")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FIREODT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FBAREA")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FOSINDX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FWINX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FFMCODE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DUFMCODE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "DRTCODE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "INFSINX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 10, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FBUPINX")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 4, 11, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FDSRTE")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(2, 5, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "GLACTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SRAD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 1, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SALBEDO")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 2, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 3, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SPWAT")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 4, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SLFTI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 5, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SCTPRES")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 6, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SSTMP")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 7, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CLOUDM")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 8, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PIXST")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 0, 9, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FIREDI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 1, 194, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SWQI")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 2, 0, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CSKPROB")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 53, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR8")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 54, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR9")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 55, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR10")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 56, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR11")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 57, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR12")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 58, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR13")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 59, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR14")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 60, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR15")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(3, 192, 61, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "SBTAGR16")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 14, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WWSDIR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 15, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MWSPER")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 16, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "CDWW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 17, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "FRICV")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 18, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "WSTR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 19, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "NWSTR")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 20, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MSSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 21, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "USSD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 22, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "VSSD")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 23, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "PMAXWH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 24, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MAXWH")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 25, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMWF")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 26, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMFWW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 27, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "IMFTSW")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 28, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MZWPER")) */
       /*      return G2C_ERROR; */
       /*  if ((ret = g2c_param_abbrev(10, 0, 29, abbrev))) */
       /*      return ret; */
       /*  if (strcmp(abbrev, "MZPWW")) */
       /*      return G2C_ERROR; */
        if ((ret = g2c_param_abbrev(10, 0, 30, abbrev)))
            return ret;
        if (strcmp(abbrev, "MZPTSW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 31, abbrev)))
            return ret;
        if (strcmp(abbrev, "WDIRW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 32, abbrev)))
            return ret;
        if (strcmp(abbrev, "DIRWWW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 33, abbrev)))
            return ret;
        if (strcmp(abbrev, "DIRWTS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 34, abbrev)))
            return ret;
        if (strcmp(abbrev, "PWPER"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 35, abbrev)))
            return ret;
        if (strcmp(abbrev, "PPERWW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 36, abbrev)))
            return ret;
        if (strcmp(abbrev, "PPERTS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 37, abbrev)))
            return ret;
        if (strcmp(abbrev, "ALTWH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 38, abbrev)))
            return ret;
        if (strcmp(abbrev, "ALCWH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 39, abbrev)))
            return ret;
        if (strcmp(abbrev, "ALRRC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 40, abbrev)))
            return ret;
        if (strcmp(abbrev, "MNWSOW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 41, abbrev)))
            return ret;
        if (strcmp(abbrev, "MWDIRW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 42, abbrev)))
            return ret;
        if (strcmp(abbrev, "WESP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 43, abbrev)))
            return ret;
        if (strcmp(abbrev, "KSSEW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 44, abbrev)))
            return ret;
        if (strcmp(abbrev, "BENINX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 45, abbrev)))
            return ret;
        if (strcmp(abbrev, "SPFTR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 46, abbrev)))
            return ret;
        if (strcmp(abbrev, "PWAVEDIR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 47, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWHFSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 48, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWHSSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 49, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWHTSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 50, abbrev)))
            return ret;
        if (strcmp(abbrev, "MWPFSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 51, abbrev)))
            return ret;
        if (strcmp(abbrev, "MWPSSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 52, abbrev)))
            return ret;
        if (strcmp(abbrev, "MWPTSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 53, abbrev)))
            return ret;
        if (strcmp(abbrev, "MWDFSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 54, abbrev)))
            return ret;
        if (strcmp(abbrev, "MWDSSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 55, abbrev)))
            return ret;
        if (strcmp(abbrev, "MWDTSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 56, abbrev)))
            return ret;
        if (strcmp(abbrev, "WDWFSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 57, abbrev)))
            return ret;
        if (strcmp(abbrev, "WDWSSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 58, abbrev)))
            return ret;
        if (strcmp(abbrev, "WDWTSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 59, abbrev)))
            return ret;
        if (strcmp(abbrev, "WFWFSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 60, abbrev)))
            return ret;
        if (strcmp(abbrev, "WFWSSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 61, abbrev)))
            return ret;
        if (strcmp(abbrev, "WFWTSWEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 62, abbrev)))
            return ret;
        if (strcmp(abbrev, "WAVEFREW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 63, abbrev)))
            return ret;
        if (strcmp(abbrev, "FREWWW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 64, abbrev)))
            return ret;
        if (strcmp(abbrev, "FREWTSW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "RIPCOP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 9, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICEPRS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 10, abbrev)))
            return ret;
        if (strcmp(abbrev, "ZVCICEP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 11, abbrev)))
            return ret;
        if (strcmp(abbrev, "MVCICEP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 12, abbrev)))
            return ret;
        if (strcmp(abbrev, "CICES"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "CH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRACTSAL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 204, abbrev)))
            return ret;
        if (strcmp(abbrev, "FRZSPR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 13, abbrev)))
            return ret;
        if (strcmp(abbrev, "ACWSRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 205, abbrev)))
            return ret;
        if (strcmp(abbrev, "TWLWAV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 206, abbrev)))
            return ret;
        if (strcmp(abbrev, "RUNUP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 207, abbrev)))
            return ret;
        if (strcmp(abbrev, "SETUP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 208, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWASH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 209, abbrev)))
            return ret;
        if (strcmp(abbrev, "TWLDT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 210, abbrev)))
            return ret;
        if (strcmp(abbrev, "TWLDC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 250, abbrev)))
            return ret;
        if (strcmp(abbrev, "ETCWL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 251, abbrev)))
            return ret;
        if (strcmp(abbrev, "TIDE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 252, abbrev)))
            return ret;
        if (strcmp(abbrev, "EROSNP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 253, abbrev)))
            return ret;
        if (strcmp(abbrev, "OWASHP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 14, abbrev)))
            return ret;
        if (strcmp(abbrev, "WDEPTH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 15, abbrev)))
            return ret;
        if (strcmp(abbrev, "WTMPSS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 16, abbrev)))
            return ret;
        if (strcmp(abbrev, "WATERDEN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 17, abbrev)))
            return ret;
        if (strcmp(abbrev, "WATDENA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 18, abbrev)))
            return ret;
        if (strcmp(abbrev, "WATPTEMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 19, abbrev)))
            return ret;
        if (strcmp(abbrev, "WATPDEN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 20, abbrev)))
            return ret;
        if (strcmp(abbrev, "WATPDENA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 21, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRTSAL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 16, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "RETOP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(1, 0, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "BGRUN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(1, 0, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "SSRUN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "SOILL"))
            return G2C_ERROR;
        
        
        /* This will fail. */
        if (g2c_param_abbrev(0, 3000, 0, abbrev) != G2C_ENOPARAM)
            return G2C_ERROR;
    }
    printf("ok!\n");
    printf("Testing g2c_param_g1tog2()...");
    {
        int g2disc, g2cat, g2num;
        int ret;
        
        /* This will work. */
        if ((ret = g2c_param_g1tog2(1, 2, &g2disc, &g2cat, &g2num)))
            return ret;
        if (g2disc != 0 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;

        /* This will work but do nothing. */
        if ((ret = g2c_param_g1tog2(1, 2, NULL, NULL, NULL)))
            return ret;

        /* This will fail. */
        if (g2c_param_g1tog2(1, 2000, &g2disc, &g2cat, &g2num) != G2C_ENOPARAM)
            return G2C_ERROR;
        
    }
    printf("ok!\n");
    printf("Testing g2c_param_g2tog1()...");
    {
        int g1num, g1ver;
        int ret;
        
        /* This will work. */
        if ((ret = g2c_param_g2tog1(0, 3, 0, &g1num, &g1ver)))
            return ret;
        if (g1num != 1 || g1ver != 2)
            return G2C_ERROR;

        /* This will work but do nothing. */
        if ((ret = g2c_param_g2tog1(0, 3, 0, NULL, NULL)))
            return ret;

        /* This will fail. */
        if (g2c_param_g2tog1(0, 2000, 0, &g1num, &g1ver) != G2C_ENOPARAM)
            return G2C_ERROR;
        
    }
    printf("ok!\n");
    printf("Testing g2c_param_all()...");
    {
        int g2disc, g2cat, g2num;        
        int g1num, g1ver;
        char abbrev[G2C_MAX_NOAA_ABBREV_LEN + 1];        
        int ret;
        
        g2c_set_log_level(10);

        /* This will work. */
        if ((ret = g2c_param_all(0, &g1num, &g1ver, &g2disc, &g2cat, &g2num, abbrev)))
            return ret;
        if (g1num != 1 || g1ver != 2 || g2disc != 0 || g2cat != 3 || g2num != 0)
            return G2C_ERROR;
        if (strcmp(abbrev, "PRES"))
            return G2C_ERROR;

        /* This will work but do nothing. */
        if ((ret = g2c_param_all(0, NULL, NULL, NULL, NULL, NULL, NULL)))
            return ret;

        /* These will fail. */
        if (g2c_param_all(G2C_MAX_NOAA_PARAMS + 1, &g1num, &g1ver, &g2disc, &g2cat, &g2num, abbrev) != G2C_EINVAL)
            return G2C_ERROR;
        if (g2c_param_all(-1, &g1num, &g1ver, &g2disc, &g2cat, &g2num, abbrev) != G2C_EINVAL)
            return G2C_ERROR;
        
    }
    printf("ok!\n");
    printf("SUCCESS!!!\n");
    return G2C_NOERROR;
}

