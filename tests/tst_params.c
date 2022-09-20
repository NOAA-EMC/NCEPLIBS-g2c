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

        /* This will succeed, but accomplish nothing. */
        if ((ret = g2c_param_abbrev(0, 3, 0, NULL)))
            return ret;

        /* This will work. */
        if ((ret = g2c_param_abbrev(0, 3, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRES"))
            return G2C_ERROR;
        
        if ((ret = g2c_param_abbrev(0, 3, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRES"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRMSL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "PTEND"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 14, abbrev)))
            return ret;
        if (strcmp(abbrev, "PVORT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICAHT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "GP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "HGT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "DIST"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 7, abbrev)))
            return ret;
        if (strcmp(abbrev, "HSTDV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 14, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "TOZNE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "TMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "VTMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "POT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "EPOT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "TMAX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "TMIN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "DPT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 7, abbrev)))
            return ret;
        if (strcmp(abbrev, "DEPR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 8, abbrev)))
            return ret;
        if (strcmp(abbrev, "LAPR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "VIS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 15, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "RDSP1"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 15, 7, abbrev)))
            return ret;
        if (strcmp(abbrev, "RDSP2"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 15, 8, abbrev)))
            return ret;
        if (strcmp(abbrev, "RDSP3"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 7, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "PLI"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 9, abbrev)))
            return ret;
        if (strcmp(abbrev, "TMPA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 8, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRESA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 9, abbrev)))
            return ret;
        if (strcmp(abbrev, "GPA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "WVSP1"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "WVSP2"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "WVSP3"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "WDIR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "WIND"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "UGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "VGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "STRM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "VPOT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "MNTSF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 7, abbrev)))
            return ret;
        if (strcmp(abbrev, "SGCVV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 8, abbrev)))
            return ret;
        if (strcmp(abbrev, "VVEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 9, abbrev)))
            return ret;
        if (strcmp(abbrev, "DZDT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 10, abbrev)))
            return ret;
        if (strcmp(abbrev, "ABSV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 11, abbrev)))
            return ret;
        if (strcmp(abbrev, "ABSD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 12, abbrev)))
            return ret;
        if (strcmp(abbrev, "RELV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 13, abbrev)))
            return ret;
        if (strcmp(abbrev, "RELD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 15, abbrev)))
            return ret;
        if (strcmp(abbrev, "VUCSH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 16, abbrev)))
            return ret;
        if (strcmp(abbrev, "VVCSH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "DIRC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "SPC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "UOGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "VOGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "SPFH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "RH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "MIXR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "PWAT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "VAPP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "SATD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "EVP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "CICE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 7, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRATE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "TSTM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 8, abbrev)))
            return ret;
        if (strcmp(abbrev, "APCP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 9, abbrev)))
            return ret;
        if (strcmp(abbrev, "NCPCP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 10, abbrev)))
            return ret;
        if (strcmp(abbrev, "ACPCP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 12, abbrev)))
            return ret;
        if (strcmp(abbrev, "SRWEQ"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 13, abbrev)))
            return ret;
        if (strcmp(abbrev, "WEASD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 11, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNOD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "MIXHT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "TTHDP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "MTHD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "MTHA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCDC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "CDCON"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "LCDC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "MCDC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "HCDC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "CWAT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 7, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "BLI"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 14, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNOC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 15, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNOL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "WTMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "LAND"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "DSLM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "SFCR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "ALBDO"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "TSOIL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "SOILM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "VEG"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "SALTY"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 10, abbrev)))
            return ret;
        if (strcmp(abbrev, "DEN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "WATR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICEC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICETK"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "DICED"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "SICED"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "UICE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "VICE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICEG"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 7, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICED"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 16, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNOM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "HTSGW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "WVDIR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "WVHGT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "WVPER"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 7, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWDIR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 8, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWELL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 9, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWPER"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 10, abbrev)))
            return ret;
        if (strcmp(abbrev, "DIRPW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 11, abbrev)))
            return ret;
        if (strcmp(abbrev, "PERPW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 12, abbrev)))
            return ret;
        if (strcmp(abbrev, "DIRSW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 13, abbrev)))
            return ret;
        if (strcmp(abbrev, "PERSW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "NSWRS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 5, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "NLWRS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "NSWRT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 5, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "NLWRT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 5, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "LWAVR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWAVR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "GRAD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "BRTMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "LWRAD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWRAD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 10, abbrev)))
            return ret;
        if (strcmp(abbrev, "LHTFL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 11, abbrev)))
            return ret;
        if (strcmp(abbrev, "SHTFL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 20, abbrev)))
            return ret;
        if (strcmp(abbrev, "BLYDP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 17, abbrev)))
            return ret;
        if (strcmp(abbrev, "UFLX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 18, abbrev)))
            return ret;
        if (strcmp(abbrev, "VFLX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 19, abbrev)))
            return ret;
        if (strcmp(abbrev, "WMIXE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(255, 255, 255, abbrev)))
            return ret;
        if (strcmp(abbrev, "IMGD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNOHF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 22, abbrev)))
            return ret;
        if (strcmp(abbrev, "CLWMR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "CRAIN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "CFRZR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "CICEP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "CSNOW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "CPRAT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 197, abbrev)))
            return ret;
        if (strcmp(abbrev, "MCONV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(1, 1, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "CPOFP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 199, abbrev)))
            return ret;
        if (strcmp(abbrev, "PEVAP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "VWSH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "MFLX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "USTM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "VSTM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "CD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 197, abbrev)))
            return ret;
        if (strcmp(abbrev, "FRICV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "MSLET"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "DSWRF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "USWRF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 5, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "DLWRF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 5, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "ULWRF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "CDLYR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 7, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "4LFTX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 7, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "CAPE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 7, 7, abbrev)))
            return ret;
        if (strcmp(abbrev, "CIN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 7, 8, abbrev)))
            return ret;
        if (strcmp(abbrev, "HLCY"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 7, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "LFTX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 11, abbrev)))
            return ret;
        if (strcmp(abbrev, "TKE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 191, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "NLAT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 191, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "ELON"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(1, 0, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "BGRUN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(1, 0, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "SSRUN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "SOILW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "GFLUX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "MSTAV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "SFEXC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "CNWAT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 197, abbrev)))
            return ret;
        if (strcmp(abbrev, "BMIXL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 14, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "O3MR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "5WAVH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 200, abbrev)))
            return ret;
        if (strcmp(abbrev, "PEVPR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "CWORK"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "U-GWD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "V-GWD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "HPBL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 197, abbrev)))
            return ret;
        if (strcmp(abbrev, "5WAVA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "SOILL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "RLYRS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 201, abbrev)))
            return ret;
        if (strcmp(abbrev, "WILT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "SLTYP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "SOTYP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 198, abbrev)))
            return ret;
        if (strcmp(abbrev, "VGTYP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "SMREF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "SMDRY"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 201, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNOWC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 197, abbrev)))
            return ret;
        if (strcmp(abbrev, "POROS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 202, abbrev)))
            return ret;
        if (strcmp(abbrev, "FRAIN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 199, abbrev)))
            return ret;
        if (strcmp(abbrev, "FICE"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 203, abbrev)))
            return ret;
        if (strcmp(abbrev, "RIME"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "CUEFI"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCOND"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCOLW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 197, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCOLI"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 204, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCOLR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 205, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCOLS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 198, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCOLC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "MXSALB"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNFALB"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 24, abbrev)))
            return ret;
        if (strcmp(abbrev, "RWMR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 25, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNMR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 199, abbrev)))
            return ret;
        if (strcmp(abbrev, "CCOND"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 200, abbrev)))
            return ret;
        if (strcmp(abbrev, "RSMIN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 202, abbrev)))
            return ret;
        if (strcmp(abbrev, "RCS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 203, abbrev)))
            return ret;
        if (strcmp(abbrev, "RCT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 204, abbrev)))
            return ret;
        if (strcmp(abbrev, "RCQ"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 205, abbrev)))
            return ret;
        if (strcmp(abbrev, "RCSOL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 7, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "RI"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(3, 1, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "USCT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(3, 1, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "VSCT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 191, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "TSEC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 14, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "OZCON"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 14, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "OZCAT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(1, 1, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "POP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(1, 1, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "CPOZP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 22, abbrev)))
            return ret;
        if (strcmp(abbrev, "GUST"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "WDIR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "WIND"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "UGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "VGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "HTSGW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 4, abbrev)))
            return ret;
        if (strcmp(abbrev, "WVDIR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 6, abbrev)))
            return ret;
        if (strcmp(abbrev, "WVPER"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 10, abbrev)))
            return ret;
        if (strcmp(abbrev, "DIRPW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 11, abbrev)))
            return ret;
        if (strcmp(abbrev, "PERPW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 12, abbrev)))
            return ret;
        if (strcmp(abbrev, "DIRSW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 13, abbrev)))
            return ret;
        if (strcmp(abbrev, "PERSW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 13, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "PMTC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 13, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "PMTF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "TMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 198, abbrev)))
            return ret;
        if (strcmp(abbrev, "MSLMA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 13, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "LPMTF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 13, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "LIPMF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 23, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICMR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 32, abbrev)))
            return ret;
        if (strcmp(abbrev, "GRMR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 206, abbrev)))
            return ret;
        if (strcmp(abbrev, "TIPD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 17, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "LTNG"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 206, abbrev)))
            return ret;
        if (strcmp(abbrev, "RDRIP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 15, abbrev)))
            return ret;
        if (strcmp(abbrev, "VPTMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 207, abbrev)))
            return ret;
        if (strcmp(abbrev, "NCIP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 208, abbrev)))
            return ret;
        if (strcmp(abbrev, "SNOT"))
            return G2C_ERROR;
        /* See https://github.com/NOAA-EMC/NCEPLIBS-g2/issues/314. */
        /* if ((ret = g2c_param_abbrev(0, 3, 1, abbrev))) */
        /*     return ret; */
        /* if (strcmp(abbrev, "MSLSA")) */
        /*     return G2C_ERROR; */
        if ((ret = g2c_param_abbrev(0, 3, 199, abbrev)))
            return ret;
        if (strcmp(abbrev, "TSLSA"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 200, abbrev)))
            return ret;
        if (strcmp(abbrev, "PLPL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "DUVB"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "CDUVB"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 207, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICWAT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 204, abbrev)))
            return ret;
        if (strcmp(abbrev, "MIXLY"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "TTRAD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 16, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "REFD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 16, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "REFC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 4, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "CSDSF"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 209, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCLSW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 210, abbrev)))
            return ret;
        if (strcmp(abbrev, "TCOLM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 201, abbrev)))
            return ret;
        if (strcmp(abbrev, "LPSX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 202, abbrev)))
            return ret;
        if (strcmp(abbrev, "LPSY"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 203, abbrev)))
            return ret;
        if (strcmp(abbrev, "HGTX"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 204, abbrev)))
            return ret;
        if (strcmp(abbrev, "HGTY"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "REV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 2, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICEC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "UOGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "VOGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "WTMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "DSLM"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "SALTY"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "UOGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "VOGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 0, abbrev)))
            return ret;
        if (strcmp(abbrev, "WTMP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "SALTY"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 9, abbrev)))
            return ret;
        if (strcmp(abbrev, "DZDT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "MIXHT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRMSL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "HGT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "ELEV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 198, abbrev)))
            return ret;
        if (strcmp(abbrev, "MINRH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 27, abbrev)))
            return ret;
        if (strcmp(abbrev, "MAXRH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 29, abbrev)))
            return ret;
        if (strcmp(abbrev, "ASNOW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 16, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "REFZR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 16, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "REFZI"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 16, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "REFZC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 198, abbrev)))
            return ret;
        if (strcmp(abbrev, "LAUV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 199, abbrev)))
            return ret;
        if (strcmp(abbrev, "LOUV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 200, abbrev)))
            return ret;
        if (strcmp(abbrev, "LAVV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 201, abbrev)))
            return ret;
        if (strcmp(abbrev, "LOVV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 202, abbrev)))
            return ret;
        if (strcmp(abbrev, "LAPP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 203, abbrev)))
            return ret;
        if (strcmp(abbrev, "LOPP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "SSHG"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 2, abbrev)))
            return ret;
        if (strcmp(abbrev, "UGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 3, abbrev)))
            return ret;
        if (strcmp(abbrev, "VGRD"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 1, abbrev)))
            return ret;
        if (strcmp(abbrev, "PRMSL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 5, abbrev)))
            return ret;
        if (strcmp(abbrev, "HGT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "WTMPC"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 4, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "SALIN"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 3, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "P2OMLT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "OMLU"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 193, abbrev)))
            return ret;
        if (strcmp(abbrev, "OMLV"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 194, abbrev)))
            return ret;
        if (strcmp(abbrev, "UBARO"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 1, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "VBARO"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 205, abbrev)))
            return ret;
        if (strcmp(abbrev, "FLGHT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 206, abbrev)))
            return ret;
        if (strcmp(abbrev, "CICEL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 207, abbrev)))
            return ret;
        if (strcmp(abbrev, "CIVIS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 208, abbrev)))
            return ret;
        if (strcmp(abbrev, "CIFLT"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 209, abbrev)))
            return ret;
        if (strcmp(abbrev, "LAVNI"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 210, abbrev)))
            return ret;
        if (strcmp(abbrev, "HAVNI"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 211, abbrev)))
            return ret;
        if (strcmp(abbrev, "SBSALB"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 212, abbrev)))
            return ret;
        if (strcmp(abbrev, "SWSALB"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 213, abbrev)))
            return ret;
        if (strcmp(abbrev, "NBSALB"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 214, abbrev)))
            return ret;
        if (strcmp(abbrev, "NWSALB"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(10, 0, 192, abbrev)))
            return ret;
        if (strcmp(abbrev, "WSTP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 211, abbrev)))
            return ret;
        if (strcmp(abbrev, "EMNP"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 3, 205, abbrev)))
            return ret;
        if (strcmp(abbrev, "LAYTH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 6, 13, abbrev)))
            return ret;
        if (strcmp(abbrev, "CEIL"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 12, abbrev)))
            return ret;
        if (strcmp(abbrev, "PBLREG"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 228, abbrev)))
            return ret;
        if (strcmp(abbrev, "ACOND"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 1, 212, abbrev)))
            return ret;
        if (strcmp(abbrev, "SBSNO"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 3, 198, abbrev)))
            return ret;
        if (strcmp(abbrev, "EVBS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 229, abbrev)))
            return ret;
        if (strcmp(abbrev, "EVCW"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(2, 0, 230, abbrev)))
            return ret;
        if (strcmp(abbrev, "TRANS"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 2, 204, abbrev)))
            return ret;
        if (strcmp(abbrev, "VEDH"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 195, abbrev)))
            return ret;
        if (strcmp(abbrev, "LRGHR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 0, 196, abbrev)))
            return ret;
        if (strcmp(abbrev, "CNVHR"))
            return G2C_ERROR;
        if ((ret = g2c_param_abbrev(0, 19, 20, abbrev)))
            return ret;
        if (strcmp(abbrev, "ICIP"))
            return G2C_ERROR;
/*  323,   169,   140,     0,    19,    20, ICIP     */
/*  324,   170,   140,     0,    19,    21, CTP      */
/*  325,   171,   140,     0,    19,    21, CTP      */
/*  326,   172,   140,     0,    19,    22, CAT      */
/*  327,   173,   140,     0,    19,    22, CAT      */
/*  328,   174,   140,     0,     6,    25, CBHE     */
/*  329,   175,   140,   255,   255,   255, IMGD     */
/*  330,   176,   140,   255,   255,   255, IMGD     */
/*  331,   177,   140,   255,   255,   255, IMGD     */
/*  332,   178,   140,   255,   255,   255, IMGD     */
/*  333,   179,   140,     0,     3,     3, ICAHT    */
/*  334,   180,   140,     0,     3,     3, ICAHT    */
/*  335,   181,   140,   255,   255,   255, IMGD     */
/*  336,   182,   140,   255,   255,   255, IMGD     */
/*  337,    76,   129,     0,     6,     6, CWAT     */
/*  338,   104,     0,    10,     0,     7, SWDIR    */
/*  339,   105,     0,    10,     0,     8, SWELL    */
/*  340,   106,     0,    10,     0,     9, SWPER    */
/*  341,   102,     0,    10,     0,     5, WVHGT    */
/*  342,   213,   129,     3,   192,     0, SBT122   */
/*  343,   214,   129,     3,   192,     1, SBT123   */
/*  344,   215,   129,     3,   192,     2, SBT124   */
/*  345,   216,   129,     3,   192,     3, SBT126   */
/*  346,   221,   129,     3,   192,     4, SBC123   */
/*  347,   222,   129,     3,   192,     5, SBC124   */
/*  348,   228,   129,    10,     3,   192, SURGE    */
/*  349,   229,   129,    10,     3,   193, ETSRG    */
/*  350,   149,     2,     0,     2,    14, PVORT    */
/*  351,   150,     2,     0,   192,     1, COVMZ    */
/*  352,   151,     2,     0,   192,     2, COVTZ    */
/*  353,   152,     2,     0,   192,     3, COVTM    */
/*  354,   202,   129,     0,     0,   197, THFLX    */
/*  355,    33,     3,     0,     2,     2, UGRD     */
/*  356,    34,     3,     0,     2,     3, VGRD     */
/*  357,    40,     3,     0,     2,     9, DZDT     */
/*  358,   124,     3,     0,     2,    17, UFLX     */
/*  359,   125,     3,     0,     2,    18, VFLX     */
/*  360,     8,     3,     0,     3,     6, DIST     */
/*  361,    13,     3,     0,     0,     2, POT      */
/*  362,    88,     3,    10,     4,     3, SALTY    */
/*  363,    49,     3,    10,     1,     2, UOGRD    */
/*  364,    50,     3,    10,     1,     3, VOGRD    */
/*  365,   215,     2,     0,     0,   198, TTDIA    */
/*  366,   217,     2,     0,     0,   199, TTPHY    */
/*  367,   154,   130,     2,     3,   199, LSPA     */
/*  368,   250,     2,     0,     4,   197, SWHR     */
/*  369,   251,     2,     0,     5,   194, LWHR     */
/*  370,   160,     2,     0,     4,   198, CSUSF    */
/*  371,   162,     2,     0,     5,   195, CSULF    */
/*  372,   163,     2,     0,     5,   196, CSDLF    */
/*  373,   164,     2,     0,     4,   199, CFNSF    */
/*  374,   165,     2,     0,     5,   197, CFNLF    */
/*  375,   166,     2,     0,     4,   200, VBDSF    */
/*  376,   167,     2,     0,     4,   201, VDDSF    */
/*  377,   168,     2,     0,     4,   202, NBDSF    */
/*  378,   169,     2,     0,     4,   203, NDDSF    */
/*  379,   206,     2,     0,     7,   196, UVI      */
/*  380,   219,     2,     0,     0,   200, TSD1D    */
/*  381,   220,     2,     0,     3,   206, NLGSP    */
/*  382,   244,     2,     0,     0,   201, SHAHR    */
/*  383,   246,     2,     0,     0,   202, VDFHR    */
/*  384,   243,     2,     0,     1,   213, CNVMR    */
/*  385,   245,     2,     0,     1,   214, SHAMR    */
/*  386,   249,     2,     0,     1,   215, VDFMR    */
/*  387,   247,     2,     0,     2,   208, VDFUA    */
/*  388,   248,     2,     0,     2,   209, VDFVA    */
/*  389,   202,     3,     0,     7,   195, CWDI     */
/*  390,   232,     2,     0,     4,   204, DTRF     */
/*  391,   233,     2,     0,     4,   205, UTRF     */
/*  392,   231,     2,     0,     6,   200, MFLUX    */
/*  393,   202,     2,     0,     7,   195, CWDI     */
/*  394,   203,     2,     0,    19,   232, VAFTD    */
/*  395,   238,     3,     0,     1,   201, SNOWC    */
/*  396,    66,     3,     0,     1,    11, SNOD     */
/*  397,   133,     2,     0,     7,     2, KX       */
/*  398,   134,     2,     0,     7,     5, SX       */
/*  399,   191,   128,    10,     4,   194, BKENG    */
/*  400,   195,   129,    10,     4,   195, DBSS     */
/*  401,   171,   128,    10,     3,   197, AOHFLX   */
/*  402,   180,   128,    10,     3,   198, ASHFL    */
/*  403,   193,   128,    10,     3,   199, SSTT     */
/*  404,   194,   128,    10,     3,   200, SSST     */
/*  405,   190,   128,    10,     3,   201, KENG     */
/*  406,   185,   128,    10,     4,   196, INTFD    */
/*  407,   199,   129,    10,     3,   202, SLTFL    */
/*  408,   197,   129,    10,     4,   197, OHC      */
/*  409,   159,     2,     0,     1,   216, CONP     */
/*  410,   175,     2,     0,   191,   195, MLYNO    */
/*  411,   223,   129,     0,     1,    65, RPRATE   */
/*  412,   224,   129,     0,     1,    66, SPRATE   */
/*  413,   225,   129,     0,     1,    67, FPRATE   */
/*  414,   226,   129,     0,     1,    68, IPRATE   */
/*  415,   227,   129,     0,     7,   197, UPHL     */
/*  416,    87,     3,     2,     0,     4, VEG      */
/*  417,   130,   129,     1,     1,   195, CWR      */
/*  418,   240,     2,     0,   192,     4, COVTW    */
/*  419,   164,   133,     0,   192,     5, COVZZ    */
/*  420,   165,   133,     0,   192,     6, COVMM    */
/*  421,   166,   133,     0,   192,     7, COVQZ    */
/*  422,   167,   133,     0,   192,     8, COVQM    */
/*  423,   168,   133,     0,   192,     9, COVTVV   */
/*  424,   169,   133,     0,   192,    10, COVQVV   */
/*  425,   203,   133,     0,   192,    11, COVPSPS  */
/*  426,   206,   133,     0,   192,    12, COVQQ    */
/*  427,   220,   133,     0,   192,    13, COVVVVV  */
/*  428,   234,   133,     0,   192,    14, COVTT    */
/*  429,   201,   133,     0,     0,   203, THZ0     */
/*  430,   195,   133,     0,     1,   218, QZ0      */
/*  431,   204,   133,     0,     1,   219, QMAX     */
/*  432,   205,   133,     0,     1,   220, QMIN     */
/*  433,   181,   133,     0,     2,   210, GWDU     */
/*  434,   182,   133,     0,     2,   211, GWDV     */
/*  435,   183,   133,     0,     2,   212, CNVU     */
/*  436,   184,   133,     0,     2,   213, CNVV     */
/*  437,   236,   133,     0,     2,   214, WTEND    */
/*  438,   154,   133,     0,     2,   215, OMGALF   */
/*  439,   196,   133,     0,     2,   216, CNGWDU   */
/*  440,   197,   133,     0,     2,   217, CNGWDV   */
/*  441,   202,   133,     0,     3,   207, CNVUMF   */
/*  442,   209,   133,     0,     3,   208, CNVDMF   */
/*  443,   219,   133,     0,     3,   209, CNVDEMF  */
/*  444,   173,   133,     0,     1,   217, LRGMR    */
/*  445,   174,   133,     0,    14,   195, VDFOZ    */
/*  446,   175,   133,     0,    14,   196, POZ      */
/*  447,   188,   133,     0,    14,   197, TOZ      */
/*  448,   139,   133,     0,    14,   198, POZT     */
/*  449,   239,   133,     0,    14,   199, POZO     */
/*  450,   185,   133,     2,     0,   208, AKHS     */
/*  451,   186,   133,     2,     0,   209, AKMS     */
/*  452,   193,   133,     0,    19,   218, EPSR     */
/*  453,   229,   130,     0,     0,   192, SNOHF    */
/*  454,   194,   129,     0,     0,   204, TCHP     */
/*  455,   185,     2,     0,    19,   219, TPFI     */
/*  456,   182,   130,     0,     7,   198, LAI      */
/*  457,   173,     2,     0,     3,   210, LMH      */
/*  458,   174,     2,     0,     2,   218, LMV      */
/*  459,     1,   131,     0,     3,     0, PRES     */
/*  460,     2,   131,     0,     3,     1, PRMSL    */
/*  461,     3,   131,     0,     3,     2, PTEND    */
/*  462,     4,   131,     0,     2,    14, PVORT    */
/*  463,     5,   131,     0,     3,     3, ICAHT    */
/*  464,     6,   131,     0,     3,     4, GP       */
/*  465,     7,   131,     0,     3,     5, HGT      */
/*  466,     8,   131,     0,     3,     6, DIST     */
/*  467,     9,   131,     0,     3,     7, HSTDV    */
/*  468,    10,   131,     0,    14,     0, TOZNE    */
/*  469,    11,   131,     0,     0,     0, TMP      */
/*  470,    12,   131,     0,     0,     1, VTMP     */
/*  471,    13,   131,     0,     0,     2, POT      */
/*  472,    14,   131,     0,     0,     3, EPOT     */
/*  473,    15,   131,     0,     0,     4, TMAX     */
/*  474,    16,   131,     0,     0,     5, TMIN     */
/*  475,    17,   131,     0,     0,     6, DPT      */
/*  476,    18,   131,     0,     0,     7, DEPR     */
/*  477,    19,   131,     0,     0,     8, LAPR     */
/*  478,    20,   131,     0,    19,     0, VIS      */
/*  479,    21,   131,     0,    15,     6, RDSP1    */
/*  480,    22,   131,     0,    15,     7, RDSP2    */
/*  481,    23,   131,     0,    15,     8, RDSP3    */
/*  482,    24,   131,     0,     7,     0, PLI      */
/*  483,    25,   131,     0,     0,     9, TMPA     */
/*  484,    26,   131,     0,     3,     8, PRESA    */
/*  485,    27,   131,     0,     3,     9, GPA      */
/*  486,    28,   131,    10,     0,     0, WVSP1    */
/*  487,    29,   131,    10,     0,     1, WVSP2    */
/*  488,    30,   131,    10,     0,     2, WVSP3    */
/*  489,    31,   131,     0,     2,     0, WDIR     */
/*  490,    32,   131,     0,     2,     1, WIND     */
/*  491,    33,   131,     0,     2,     2, UGRD     */
/*  492,    34,   131,     0,     2,     3, VGRD     */
/*  493,    35,   131,     0,     2,     4, STRM     */
/*  494,    36,   131,     0,     2,     5, VPOT     */
/*  495,    37,   131,     0,     2,     6, MNTSF    */
/*  496,    38,   131,     0,     2,     7, SGCVV    */
/*  497,    39,   131,     0,     2,     8, VVEL     */
/*  498,    40,   131,     0,     2,     9, DZDT     */
/*  499,    41,   131,     0,     2,    10, ABSV     */
/*  500,    42,   131,     0,     2,    11, ABSD     */
/*  501,    43,   131,     0,     2,    12, RELV     */
/*  502,    44,   131,     0,     2,    13, RELD     */
/*  503,    45,   131,     0,     2,    15, VUCSH    */
/*  504,    46,   131,     0,     2,    16, VVCSH    */
/*  505,    47,   131,    10,     1,     0, DIRC     */
/*  506,    48,   131,    10,     1,     1, SPC      */
/*  507,    49,   131,    10,     1,     2, UOGRD    */
/*  508,    50,   131,    10,     1,     3, VOGRD    */
/*  509,    51,   131,     0,     1,     0, SPFH     */
/*  510,    52,   131,     0,     1,     1, RH       */
/*  511,    53,   131,     0,     1,     2, MIXR     */
/*  512,    54,   131,     0,     1,     3, PWAT     */
/*  513,    55,   131,     0,     1,     4, VAPP     */
/*  514,    56,   131,     0,     1,     5, SATD     */
/*  515,    57,   131,     0,     1,     6, EVP      */
/*  516,    58,   131,     0,     6,     0, CICE     */
/*  517,    59,   131,     0,     1,     7, PRATE    */
/*  518,    60,   131,     0,    19,     2, TSTM     */
/*  519,    61,   131,     0,     1,     8, APCP     */
/*  520,    62,   131,     0,     1,     9, NCPCP    */
/*  521,    63,   131,     0,     1,    10, ACPCP    */
/*  522,    64,   131,     0,     1,    12, SRWEQ    */
/*  523,    65,   131,     0,     1,    13, WEASD    */
/*  524,    66,   131,     0,     1,    11, SNOD     */
/*  525,    67,   131,     0,    19,     3, MIXHT    */
/*  526,    68,   131,    10,     4,     2, TTHDP    */
/*  527,    69,   131,    10,     4,     0, MTHD     */
/*  528,    70,   131,    10,     4,     1, MTHA     */
/*  529,    71,   131,     0,     6,     1, TCDC     */
/*  530,    72,   131,     0,     6,     2, CDCON    */
/*  531,    73,   131,     0,     6,     3, LCDC     */
/*  532,    74,   131,     0,     6,     4, MCDC     */
/*  533,    75,   131,     0,     6,     5, HCDC     */
/*  534,    76,   131,     0,     6,     6, CWAT     */
/*  535,    77,   131,     0,     7,     1, BLI      */
/*  536,    78,   131,     0,     1,    14, SNOC     */
/*  537,    79,   131,     0,     1,    15, SNOL     */
/*  538,    80,   131,    10,     3,     0, WTMP     */
/*  539,    81,   131,     2,     0,     0, LAND     */
/*  540,    82,   131,    10,     3,     1, DSLM     */
/*  541,    83,   131,     2,     0,     1, SFCR     */
/*  542,    84,   131,     0,    19,     1, ALBDO    */
/*  543,    85,   131,     2,     0,     2, TSOIL    */
/*  544,    86,   131,     2,     0,     3, SOILM    */
/*  545,    87,   131,     2,     0,     4, VEG      */
/*  546,    88,   131,    10,     4,     3, SALTY    */
/*  547,    89,   131,     0,     3,    10, DEN      */
/*  548,    90,   131,     2,     0,     5, WATR     */
/*  549,    91,   131,    10,     2,     0, ICEC     */
/*  550,    92,   131,    10,     2,     1, ICETK    */
/*  551,    93,   131,    10,     2,     2, DICED    */
/*  552,    94,   131,    10,     2,     3, SICED    */
/*  553,    95,   131,    10,     2,     4, UICE     */
/*  554,    96,   131,    10,     2,     5, VICE     */
/*  555,    97,   131,    10,     2,     6, ICEG     */
/*  556,    98,   131,    10,     2,     7, ICED     */
/*  557,    99,   131,     0,     1,    16, SNOM     */
/*  558,   100,   131,    10,     0,     3, HTSGW    */
/*  559,   101,   131,    10,     0,     4, WVDIR    */
/*  560,   102,   131,    10,     0,     5, WVHGT    */
/*  561,   103,   131,    10,     0,     6, WVPER    */
/*  562,   104,   131,    10,     0,     7, SWDIR    */
/*  563,   105,   131,    10,     0,     8, SWELL    */
/*  564,   106,   131,    10,     0,     9, SWPER    */
/*  565,   107,   131,    10,     0,    10, DIRPW    */
/*  566,   108,   131,    10,     0,    11, PERPW    */
/*  567,   109,   131,    10,     0,    12, DIRSW    */
/*  568,   110,   131,    10,     0,    13, PERSW    */
/*  569,   111,   131,     0,     4,     0, NSWRS    */
/*  570,   112,   131,     0,     5,     0, NLWRS    */
/*  571,   113,   131,     0,     4,     1, NSWRT    */
/*  572,   114,   131,     0,     5,     1, NLWRT    */
/*  573,   115,   131,     0,     5,     2, LWAVR    */
/*  574,   116,   131,     0,     4,     2, SWAVR    */
/*  575,   117,   131,     0,     4,     3, GRAD     */
/*  576,   118,   131,     0,     4,     4, BRTMP    */
/*  577,   119,   131,     0,     4,     5, LWRAD    */
/*  578,   120,   131,     0,     4,     6, SWRAD    */
/*  579,   121,   131,     0,     0,    10, LHTFL    */
/*  580,   122,   131,     0,     0,    11, SHTFL    */
/*  581,   123,   131,     0,     2,    20, BLYDP    */
/*  582,   124,   131,     0,     2,    17, UFLX     */
/*  583,   125,   131,     0,     2,    18, VFLX     */
/*  584,   126,   131,     0,     2,    19, WMIXE    */
/*  585,   127,   131,   255,   255,   255, IMGD     */
/*  586,   128,   131,     0,     3,     1, MSLSA    */
/*  587,   130,   131,     0,     3,   192, MSLET    */
/*  588,   131,   131,     0,     7,   192, LFTX     */
/*  589,   132,   131,     0,     7,   193, 4LFTX    */
/*  590,   134,   131,     0,     3,   212, PRESN    */
/*  591,   135,   131,     0,     1,   197, MCONV    */
/*  592,   136,   131,     0,     2,   192, VWSH     */
/*  593,   137,   131,     0,     2,   219, PVMWW    */
/*  594,   140,   131,     0,     1,   192, CRAIN    */
/*  595,   141,   131,     0,     1,   193, CFRZR    */
/*  596,   142,   131,     0,     1,   194, CICEP    */
/*  597,   143,   131,     0,     1,   195, CSNOW    */
/*  598,   144,   131,     2,     0,   192, SOILW    */
/*  599,   145,   131,     0,     1,   200, PEVPR    */
/*  600,   146,   131,     2,     0,   210, VEGT     */
/*  601,   147,   131,     2,     3,   200, BARET    */
/*  602,   148,   131,     2,     3,   201, AVSFT    */
/*  603,   149,   131,     2,     3,   202, RADT     */
/*  604,   150,   131,     2,     0,   211, SSTOR    */
/*  605,   151,   131,     2,     0,   212, LSOIL    */
/*  606,   152,   131,     2,     0,   213, EWATR    */
/*  607,   153,   131,     0,     1,    22, CLWMR    */
/*  608,   155,   131,     2,     0,   193, GFLUX    */
/*  609,   156,   131,     0,     7,     7, CIN      */
/*  610,   157,   131,     0,     7,     6, CAPE     */
/*  611,   158,   131,     0,    19,    11, TKE      */
/*  612,   159,   131,     0,    19,   192, MXSALB   */
/*  613,   160,   131,     2,     3,   192, SOILL    */
/*  614,   161,   131,     0,     1,    29, ASNOW    */
/*  615,   162,   131,     0,     1,   221, ARAIN    */
/*  616,   163,   131,     2,     0,   214, GWREC    */
/*  617,   164,   131,     2,     0,   215, QREC     */
/*  618,   165,   131,     0,     1,   222, SNOWT    */
/*  619,   166,   131,     0,     4,   200, VBDSF    */
/*  620,   167,   131,     0,     4,   201, VDDSF    */
/*  621,   168,   131,     0,     4,   202, NBDSF    */
/*  622,   169,   131,     0,     4,   203, NDDSF    */
/*  623,   170,   131,     0,    19,   193, SNFALB   */
/*  624,   171,   131,     2,     3,   193, RLYRS    */
/*  625,   172,   131,     0,     2,   193, MFLX     */
/*  626,   173,   131,     0,     3,   210, LMH      */
/*  627,   174,   131,     0,     2,   218, LMV      */
/*  628,   175,   131,     0,   191,   195, MLYNO    */
/*  629,   176,   131,     0,   191,   192, NLAT     */
/*  630,   177,   131,     0,   191,   193, ELON     */
/*  631,   178,   131,     0,     1,    23, ICMR     */
/*  632,   179,   131,     2,     0,   228, ACOND    */
/*  633,   180,   131,     0,     1,    17, SNOAG    */
/*  634,   181,   131,     2,     0,   199, CCOND    */
/*  635,   182,   131,     0,     7,   198, LAI      */
/*  636,   183,   131,     2,     0,   216, SFCRH    */
/*  637,   184,   131,     0,    19,    19, SALBD    */
/*  638,   187,   131,     2,     0,   217, NDVI     */
/*  639,   188,   131,     2,     0,   206, RDRIP    */
/*  640,   189,   131,     2,     0,   218, LANDN    */
/*  641,   190,   131,     0,     7,     8, HLCY     */
/*  642,   191,   131,     0,   191,   196, NLATN    */
/*  643,   192,   131,     0,   191,   197, ELONN    */
/*  644,   194,   131,     1,     1,   193, CPOFP    */
/*  645,   196,   131,     0,     2,   194, USTM     */
/*  646,   197,   131,     0,     2,   195, VSTM     */
/*  647,   198,   131,     0,     1,   212, SBSNO    */
/*  648,   199,   131,     2,     3,   198, EVBS     */
/*  649,   200,   131,     2,     0,   229, EVCW     */
/*  650,   202,   131,     0,     1,   223, APCPN    */
/*  651,   203,   131,     2,     0,   200, RSMIN    */
/*  652,   204,   131,     0,     4,   192, DSWRF    */
/*  653,   205,   131,     0,     5,   192, DLWRF    */
/*  654,   206,   131,     0,     1,   224, ACPCPN   */
/*  655,   207,   131,     2,     0,   194, MSTAV    */
/*  656,   208,   131,     2,     0,   195, SFEXC    */
/*  657,   210,   131,     2,     0,   230, TRANS    */
/*  658,   211,   131,     0,     4,   193, USWRF    */
/*  659,   212,   131,     0,     5,   193, ULWRF    */
/*  660,   213,   131,     0,     6,   192, CDLYR    */
/*  661,   214,   131,     0,     1,   196, CPRAT    */
/*  662,   216,   131,     0,     0,   193, TTRAD    */
/*  663,   218,   131,     0,     3,   211, HGTN     */
/*  664,   219,   131,     2,     0,   201, WILT     */
/*  665,   220,   130,     2,     3,   203, FLDCP    */
/*  666,   221,   131,     0,     3,   196, HPBL     */
/*  667,   222,   131,     2,     3,   194, SLTYP    */
/*  668,   223,   131,     2,     0,   196, CNWAT    */
/*  669,   224,   131,     2,     3,     0, SOTYP    */
/*  670,   225,   131,     2,     0,   198, VGTYP    */
/*  671,   226,   131,     2,     0,   197, BMIXL    */
/*  672,   227,   131,     2,     0,   219, AMIXL    */
/*  673,   228,   131,     0,     1,   199, PEVAP    */
/*  674,   229,   131,     0,     0,   192, SNOHF    */
/*  675,   230,   131,     2,     3,   195, SMREF    */
/*  676,   231,   131,     2,     3,   196, SMDRY    */
/*  677,   232,   131,     2,     0,   220, WVINC    */
/*  678,   233,   131,     2,     0,   221, WCINC    */
/*  679,   234,   131,     1,     0,   192, BGRUN    */
/*  680,   235,   131,     1,     0,   193, SSRUN    */
/*  681,   237,   131,     2,     0,   222, WVCONV   */
/*  682,   238,   131,     0,     1,   201, SNOWC    */
/*  683,   239,   131,     0,     1,   208, SNOT     */
/*  684,   240,   131,     2,     3,   197, POROS    */
/*  685,   241,   131,     2,     0,   223, WCCONV   */
/*  686,   242,   131,     2,     0,   224, WVUFLX   */
/*  687,   243,   131,     2,     0,   225, WVVFLX   */
/*  688,   244,   131,     2,     0,   226, WCUFLX   */
/*  689,   245,   131,     2,     0,   227, WCVFLX   */
/*  690,   246,   131,     2,     0,   202, RCS      */
/*  691,   247,   131,     2,     0,   203, RCT      */
/*  692,   248,   131,     2,     0,   204, RCQ      */
/*  693,   249,   131,     2,     0,   205, RCSOL    */
/*  694,   250,   131,     0,     4,   197, SWHR     */
/*  695,   251,   131,     0,     5,   194, LWHR     */
/*  696,   252,   131,     0,     2,   196, CD       */
/*  697,   253,   131,     0,     2,   197, FRICV    */
/*  698,   254,   131,     0,     7,   194, RI       */
/*  699,    62,   129,     0,     1,     9, NCPCP    */
/*  700,    63,   129,     0,     1,    10, ACPCP    */
/*  701,   220,   131,     2,     3,   203, FLDCP    */
/*  702,   231,   129,     0,    14,   200, OZMAX1   */
/*  703,   232,   129,     0,    14,   201, OZMAX8   */
/*  704,   240,   129,     0,    16,   197, RETOP    */
/*  705,   191,   133,     0,     6,   201, SUNSD    */
/*  706,   233,   129,     0,    14,   202, PDMAX1   */
/*  707,   234,   129,     0,    14,   203, PDMAX24  */
/*  708,   242,   129,    10,     3,   242, TCSRG20  */
/*  709,   243,   129,    10,     3,   243, TCSRG30  */
/*  710,   244,   129,    10,     3,   244, TCSRG40  */
/*  711,   245,   129,    10,     3,   245, TCSRG50  */
/*  712,   246,   129,    10,     3,   246, TCSRG60  */
/*  713,   247,   129,    10,     3,   247, TCSRG70  */
/*  714,   248,   129,    10,     3,   248, TCSRG80  */
/*  715,   249,   129,    10,     3,   249, TCSRG90  */
/*  716,     1,     3,     0,     3,     0, PRES     */
/*  717,    52,     3,     0,     1,     1, RH       */
/*  718,    63,     3,     0,     1,    10, ACPCP    */
/*  719,    61,     3,     0,     1,     8, APCP     */
/*  720,    41,     3,     0,     2,    10, ABSV     */
/*  721,   100,     3,    10,     0,     3, HTSGW    */
/*  722,   101,     3,    10,     0,     4, WVDIR    */
/*  723,   103,     3,    10,     0,     6, WVPER    */
/*  724,   104,     3,    10,     0,     7, SWDIR    */
/*  725,   105,     3,    10,     0,     8, SWELL    */
/*  726,   107,     3,    10,     0,    10, DIRPW    */
/*  727,   108,     3,    10,     0,    11, PERPW    */
/*  728,   109,     3,    10,     0,    12, DIRSW    */
/*  729,   110,     3,    10,     0,    13, PERSW    */
/*  730,   192,   133,    10,   191,     1, MOSF     */
/*  731,   193,   130,     0,     1,   225, FRZR     */
/*  732,   194,   130,     0,     1,   227, FROZR    */
/*  733,   195,   130,     0,     1,   241, TSNOW    */
/*  734,   196,   130,     2,     0,     7, MTERH    */
/*  735,   195,   128,    10,     4,     4, OVHD     */
/*  736,   196,   128,    10,     4,     5, OVSD     */
/*  737,   197,   128,    10,     4,     6, OVMD     */
/*  738,    64,   130,     0,     1,    12, SRWEQ    */
/*  739,   241,   130,     3,   192,     6, SBT112   */
/*  740,   242,   130,     3,   192,     7, SBT113   */
/*  741,   243,   130,     3,   192,     8, SBT114   */
/*  742,   244,   130,     3,   192,     9, SBT115   */
/*  743,   235,   129,     0,    16,   198, MAXREF   */
/*  744,   236,   129,     0,     7,   199, MXUPHL   */
/*  745,   237,   129,     0,     2,   220, MAXUVV   */
/*  746,   238,   129,     0,     2,   221, MAXDVV   */
/*  747,   253,   129,     0,     2,   222, MAXUW    */
/*  748,   254,   129,     0,     2,   223, MAXVW    */
/*  749,   241,   129,     0,     2,   224, VRATE    */
/*  750,   250,   129,     2,     4,     2, HINDEX   */
/*  751,   175,   129,     0,    19,   234, ICSEV    */
/*  752,   176,   129,     0,    19,   233, ICPRB    */
/*  753,   236,     2,     0,    19,   217, SIPD     */
/*  754,   230,   129,     0,     1,   242, RHPW     */
/*  755,   206,   130,     0,    15,     3, VIL      */
/*  756,   255,   255,     0,     0,   255, MISSING  */
/*  757,   255,   255,     0,    20,   102, AOTK     */
/*  758,   255,   255,     0,    20,   103, SSALBK   */
/*  759,   255,   255,     0,    20,   104, ASYSFK   */
/*  760,   255,   255,     0,    20,   105, AECOEF   */
/*  761,   255,   255,     0,    20,   106, AACOEF   */
/*  762,   255,   255,     0,    20,   107, ALBSAT   */
/*  763,   255,   255,     0,    20,   108, ALBGRD   */
/*  764,   255,   255,     0,    20,   109, ALESAT   */
/*  765,   255,   255,     0,    20,   110, ALEGRD   */
/*  766,   255,   255,     0,    20,     9, WLSMFLX  */
/*  767,   255,   255,     0,    20,    10, WDCPMFLX */
/*  768,   255,   255,     0,    20,    11, SEDMFLX  */
/*  769,   255,   255,     0,    20,    12, DDMFLX   */
/*  770,   255,   255,     0,    20,    13, TRANHH   */
/*  771,   255,   255,     0,    20,    14, TRSDS    */
/*  772,   255,   255,     0,    20,    59, ANCON    */
/*  773,   193,   131,     0,     0,    21, APTMP    */
/*  774,   137,   131,     0,    17,     0, LTNGSD   */
/*  775,   194,   131,     0,     1,    39, CPOFP    */
/*  776,   144,   128,    10,     3,   203, LCH      */
/*  777,   255,   255,     0,    20,   101, ATMTK    */
/*  778,   214,   131,     0,     1,    37, CPRAT    */
/*  779,   255,   255,    10,     2,     8, ICETMP   */
/*  780,   255,   255,     0,     0,    28, UCTMP    */
/*  781,   255,   255,     0,     0,    29, TMPADV   */
/*  782,   255,   255,     0,     1,   129, EFRCWAT  */
/*  783,   255,   255,     0,     1,   130, EFRRAIN  */
/*  784,   255,   255,     0,     1,   131, EFRCICE  */
/*  785,   255,   255,     0,     1,   132, EFRSNOW  */
/*  786,   255,   255,     0,     1,   133, EFRGRL   */
/*  787,   255,   255,     0,     1,   134, EFRHAIL  */
/*  788,   255,   255,     0,     1,   135, EFRSLC   */
/*  789,   255,   255,     0,     1,   136, EFRSICEC */
/*  790,   255,   255,     0,     1,   137, EFARRAIN */
/*  791,   255,   255,     0,     1,   138, EFARCICE */
/*  792,   255,   255,     0,     1,   139, EFARSNOW */
/*  793,   255,   255,     0,     1,   140, EFARGRL  */
/*  794,   255,   255,     0,     1,   141, EFARHAIL */
/*  795,   255,   255,     0,     1,   142, EFARSIC  */
/*  796,   255,   255,     0,     1,   231, PPINDX   */
/*  797,   255,   255,     0,     1,   232, PROBCIP  */
/*  798,   255,   255,     0,     1,   233, SNOWLR   */
/*  799,   255,   255,     0,     1,   234, PCPDUR   */
/*  800,   255,   255,     0,     1,   235, CLLMR    */
/*  801,   255,   255,     0,     2,   231, TPWDIR   */
/*  802,   255,   255,     0,     2,   232, TPWSPD   */
/*  803,   255,   255,     0,     2,    36, AFRWE    */
/*  804,   255,   255,     0,     3,    20, SDSGSO   */
/*  805,   255,   255,     0,     3,    21, AOSGSO   */
/*  806,   255,   255,     0,     3,    22, SSGSO    */
/*  807,   255,   255,     0,     3,    23, GWD      */
/*  808,   255,   255,     0,     3,    24, ASGSO    */
/*  809,   255,   255,     0,     3,    25, NLPRES   */
/*  810,   255,   255,     0,     3,    26, EXPRES   */
/*  811,   255,   255,     0,     3,    27, UMFLX    */
/*  812,   255,   255,     0,     3,    28, DMFLX    */
/*  813,   255,   255,     0,     3,    29, UDRATE   */
/*  814,   255,   255,     0,     3,    30, DDRATE   */
/*  815,   255,   255,     0,     3,    31, UCLSPRS  */
/*  816,   255,   255,     0,     4,    50, UVIUCS   */
/*  817,   255,   255,     0,     4,    52, DSWRFCS  */
/*  818,   255,   255,     0,     4,    53, USWRFCS  */
/*  819,   255,   255,     0,     5,     5, NLWRF    */
/*  820,   255,   255,     0,     5,     6, NLWRCS   */
/*  821,   255,   255,     0,     5,     7, BRTEMP   */
/*  822,   255,   255,     0,     5,     8, DLWRFCS  */
/*  823,   255,   255,     0,     6,    34, SLWTC    */
/*  824,   255,   255,     0,     6,    35, SSWTC    */
/*  825,   255,   255,     0,     6,    36, FSTRPC   */
/*  826,   255,   255,     0,     6,    37, FCONPC   */
/*  827,   255,   255,     0,     6,    38, MASSDCD  */
/*  828,   255,   255,     0,     6,    39, MASSDCI  */
/*  829,   255,   255,     0,     6,    40, MDCCWD   */
/*  830,   255,   255,     0,     6,    47, VFRCWD   */
/*  831,   255,   255,     0,     6,    48, VFRCICE  */
/*  832,   255,   255,     0,     6,    49, VFRCIW   */
/*  833,   255,   255,     0,     7,    19, CONAPES  */
/*  834,   255,   255,     0,     7,   203, DCAPE    */
/*  835,   255,   255,     0,     7,   204, EFHL     */
/*  836,   255,   255,     0,     7,   205, ESP      */
/*  837,   255,   255,     0,     7,   206, CANGLE   */
/*  838,   255,   255,     0,     7,   206, CANGLE   */
/*  839,   255,   255,     0,    15,     9, RFCD     */
/*  840,   255,   255,     0,    15,    10, RFCI     */
/*  841,   255,   255,     0,    15,    11, RFSNOW   */
/*  842,   255,   255,     0,    15,    12, RFRAIN   */
/*  843,   255,   255,     0,    15,    13, RFGRPL   */
/*  844,   255,   255,     0,    15,    14, RFHAIL   */
/*  845,   255,   255,     0,    15,    15, HSR      */
/*  846,   255,   255,     0,    15,    16, HSRHT    */
/*  847,   255,   255,     0,    17,     1, LTPINX   */
/*  848,   255,   255,     0,    17,     2, CDGDLTFD */
/*  849,   255,   255,     0,    17,     3, CDCDLTFD */
/*  850,   255,   255,     0,    17,     4, TLGTFD   */
/*  851,   255,   255,     0,    18,     0, ACCES    */
/*  852,   255,   255,     0,    18,     1, ACIOD    */
/*  853,   255,   255,     0,    18,     2, ACRADP   */
/*  854,   255,   255,     0,    19,    28, MWTURB   */
/*  855,   255,   255,     0,    19,    29, CATEDR   */
/*  856,   255,   255,     0,    19,    30, EDPARM   */
/*  857,   255,   255,     0,    19,    31, MXEDPRM  */
/*  858,   255,   255,     0,    19,    32, HIFREL   */
/*  859,   255,   255,     0,    19,    33, VISLFOG  */
/*  860,   255,   255,     0,    19,    34, VISIFOG  */
/*  861,   255,   255,     0,    19,    35, VISBSN   */
/*  862,   255,   255,     0,    19,    36, PSNOWS   */
/*  863,   255,   255,     0,    19,    37, ICESEV   */
/*  864,   255,   255,     0,    19,   238, ELLINX   */
/*  865,   255,   255,     1,     0,     7, DISRS    */
/*  866,   255,   255,     1,     0,     8, GWUPS    */
/*  867,   255,   255,     1,     0,     9, GWLOWS   */
/*  868,   255,   255,     1,     0,    10, SFLORC   */
/*  869,   255,   255,     1,     0,    11, RVERSW   */
/*  870,   255,   255,     1,     0,    12, FLDPSW   */
/*  871,   255,   255,     1,     0,    13, DEPWSS   */
/*  872,   255,   255,     1,     0,    14, UPAPCP   */
/*  873,   255,   255,     1,     0,    15, UPASM    */
/*  874,   255,   255,     1,     0,    16, PERRATE  */
/*  875,   255,   255,     1,     2,     0, WDPTHIL  */
/*  876,   255,   255,     1,     2,     1, WTMPIL   */
/*  877,   255,   255,     1,     2,     2, WFRACT   */
/*  878,   255,   255,     1,     2,     3, SEDTK    */
/*  879,   255,   255,     1,     2,     4, SEDTMP   */
/*  880,   255,   255,     1,     2,     5, ICTKIL   */
/*  881,   255,   255,     1,     2,     6, ICETIL   */
/*  882,   255,   255,     1,     2,     7, ICECIL   */
/*  883,   255,   255,     1,     2,     8, LANDIL   */
/*  884,   255,   255,     1,     2,     9, SFSAL    */
/*  885,   255,   255,     1,     2,    10, SFTMP    */
/*  886,   255,   255,     1,     2,    11, ACWSR    */
/*  887,   255,   255,     1,     2,    12, SALTIL   */
/*  888,   255,   255,     1,     2,    13, CSAFC    */
/*  889,   255,   255,     2,     0,    35, TCLASS   */
/*  890,   255,   255,     2,     0,    36, TFRCT    */
/*  891,   255,   255,     2,     0,    37, TPERCT   */
/*  892,   255,   255,     2,     0,    38, SOILVIC  */
/*  893,   255,   255,     2,     0,    39, EVAPTRAT */
/*  894,   255,   255,     2,     1,   192, CANL     */
/*  895,   255,   255,     2,     3,    18, SOILTMP  */
/*  896,   255,   255,     2,     3,    19, SOILMOI  */
/*  897,   255,   255,     2,     3,    20, CISOILM  */
/*  898,   255,   255,     2,     3,    21, SOILICE  */
/*  899,   255,   255,     2,     3,    22, CISICE   */
/*  900,   255,   255,     2,     3,    23, LWSNWP   */
/*  901,   255,   255,     2,     3,    23, FRSTINX  */
/*  902,   255,   255,     2,     3,    23, SNWDEB   */
/*  903,   255,   255,     2,     3,    23, SHFLX    */
/*  904,   255,   255,     2,     3,    23, SOILDEP  */
/*  905,   255,   255,     2,     4,     0, FIREOLK  */
/*  906,   255,   255,     2,     4,     1, FIREODT  */
/*  907,   255,   255,     2,     4,     3, FBAREA   */
/*  908,   255,   255,     2,     4,     4, FOSINDX  */
/*  909,   255,   255,     2,     4,     5, FWINX    */
/*  910,   255,   255,     2,     4,     6, FFMCODE  */
/*  911,   255,   255,     2,     4,     7, DUFMCODE */
/*  912,   255,   255,     2,     4,     8, DRTCODE  */
/*  913,   255,   255,     2,     4,     9, INFSINX  */
/*  914,   255,   255,     2,     4,    10, FBUPINX  */
/*  915,   255,   255,     2,     4,    11, FDSRTE   */
/*  916,   255,   255,     2,     5,     1, GLACTMP  */
/*  917,   255,   255,     3,     0,     0, SRAD     */
/*  918,   255,   255,     3,     0,     1, SALBEDO  */
/*  919,   255,   255,     3,     0,     2, SBTMP    */
/*  920,   255,   255,     3,     0,     3, SPWAT    */
/*  921,   255,   255,     3,     0,     4, SLFTI    */
/*  922,   255,   255,     3,     0,     5, SCTPRES  */
/*  923,   255,   255,     3,     0,     6, SSTMP    */
/*  924,   255,   255,     3,     0,     7, CLOUDM   */
/*  925,   255,   255,     3,     0,     8, PIXST    */
/*  926,   255,   255,     3,     0,     9, FIREDI   */
/*  927,   255,   255,     3,     1,   194, SWQI     */
/*  928,   255,   255,     3,     2,     0, CSKPROB  */
/*  929,   255,   255,     3,   192,    53, SBTAGR8  */
/*  930,   255,   255,     3,   192,    54, SBTAGR9  */
/*  931,   255,   255,     3,   192,    55, SBTAGR10 */
/*  932,   255,   255,     3,   192,    56, SBTAGR11 */
/*  933,   255,   255,     3,   192,    57, SBTAGR12 */
/*  934,   255,   255,     3,   192,    58, SBTAGR13 */
/*  935,   255,   255,     3,   192,    59, SBTAGR14 */
/*  936,   255,   255,     3,   192,    60, SBTAGR15 */
/*  937,   255,   255,     3,   192,    61, SBTAGR16 */
/*  938,   255,   255,    10,     0,    14, WWSDIR   */
/*  939,   255,   255,    10,     0,    15, MWSPER   */
/*  940,   255,   255,    10,     0,    16, CDWW     */
/*  941,   255,   255,    10,     0,    17, FRICV    */
/*  942,   255,   255,    10,     0,    18, WSTR     */
/*  943,   255,   255,    10,     0,    19, NWSTR    */
/*  944,   255,   255,    10,     0,    20, MSSW     */
/*  945,   255,   255,    10,     0,    21, USSD     */
/*  946,   255,   255,    10,     0,    22, VSSD     */
/*  947,   255,   255,    10,     0,    23, PMAXWH   */
/*  948,   255,   255,    10,     0,    24, MAXWH    */
/*  949,   255,   255,    10,     0,    25, IMWF     */
/*  950,   255,   255,    10,     0,    26, IMFWW    */
/*  951,   255,   255,    10,     0,    27, IMFTSW   */
/*  952,   255,   255,    10,     0,    28, MZWPER   */
/*  953,   255,   255,    10,     0,    29, MZPWW    */
/*  954,   255,   255,    10,     0,    30, MZPTSW   */
/*  955,   255,   255,    10,     0,    31, WDIRW    */
/*  956,   255,   255,    10,     0,    32, DIRWWW   */
/*  957,   255,   255,    10,     0,    33, DIRWTS   */
/*  958,   255,   255,    10,     0,    34, PWPER    */
/*  959,   255,   255,    10,     0,    35, PPERWW   */
/*  960,   255,   255,    10,     0,    36, PPERTS   */
/*  961,   255,   255,    10,     0,    37, ALTWH    */
/*  962,   255,   255,    10,     0,    38, ALCWH    */
/*  963,   255,   255,    10,     0,    39, ALRRC    */
/*  964,   255,   255,    10,     0,    40, MNWSOW   */
/*  965,   255,   255,    10,     0,    41, MWDIRW   */
/*  966,   255,   255,    10,     0,    42, WESP     */
/*  967,   255,   255,    10,     0,    43, KSSEW    */
/*  968,   255,   255,    10,     0,    44, BENINX   */
/*  969,   255,   255,    10,     0,    45, SPFTR    */
/*  970,   255,   255,    10,     0,    46, PWAVEDIR */
/*  971,   255,   255,    10,     0,    47, SWHFSWEL */
/*  972,   255,   255,    10,     0,    48, SWHSSWEL */
/*  973,   255,   255,    10,     0,    49, SWHTSWEL */
/*  974,   255,   255,    10,     0,    50, MWPFSWEL */
/*  975,   255,   255,    10,     0,    51, MWPSSWEL */
/*  976,   255,   255,    10,     0,    52, MWPTSWEL */
/*  977,   255,   255,    10,     0,    53, MWDFSWEL */
/*  978,   255,   255,    10,     0,    54, MWDSSWEL */
/*  979,   255,   255,    10,     0,    55, MWDTSWEL */
/*  980,   255,   255,    10,     0,    56, WDWFSWEL */
/*  981,   255,   255,    10,     0,    57, WDWSSWEL */
/*  982,   255,   255,    10,     0,    58, WDWTSWEL */
/*  983,   255,   255,    10,     0,    59, WFWFSWEL */
/*  984,   255,   255,    10,     0,    60, WFWSSWEL */
/*  985,   255,   255,    10,     0,    61, WFWTSWEL */
/*  986,   255,   255,    10,     0,    62, WAVEFREW */
/*  987,   255,   255,    10,     0,    63, FREWWW   */
/*  988,   255,   255,    10,     0,    64, FREWTSW  */
/*  989,   255,   255,    10,     1,     4, RIPCOP   */
/*  990,   255,   255,    10,     2,     9, ICEPRS   */
/*  991,   255,   255,    10,     2,    10, ZVCICEP  */
/*  992,   255,   255,    10,     2,    11, MVCICEP  */
/*  993,   255,   255,    10,     2,    12, CICES    */
/*  994,   255,   255,    10,     3,     2, CH       */
/*  995,   255,   255,    10,     3,     3, PRACTSAL */
/*  996,   255,   255,    10,     3,   204, FRZSPR   */
/*  997,   255,   255,    10,     4,    13, ACWSRD   */
/*  998,   255,   255,    10,     3,   205, TWLWAV   */
/*  999,   255,   255,    10,     3,   206, RUNUP    */
/* 1000,   255,   255,    10,     3,   207, SETUP    */
/* 1001,   255,   255,    10,     3,   208, SWASH    */
/* 1002,   255,   255,    10,     3,   209, TWLDT    */
/* 1003,   255,   255,    10,     3,   210, TWLDC    */
/* 1004,   255,   255,    10,     3,   250, ETCWL    */
/* 1005,   255,   255,    10,     3,   251, TIDE     */
/* 1006,   255,   255,    10,     3,   252, EROSNP   */
/* 1007,   255,   255,    10,     3,   253, OWASHP   */
/* 1008,   255,   255,    10,     4,    14, WDEPTH   */
/* 1009,   255,   255,    10,     4,    15, WTMPSS   */
/* 1010,   255,   255,    10,     4,    16, WATERDEN */
/* 1011,   255,   255,    10,     4,    17, WATDENA  */
/* 1012,   255,   255,    10,     4,    18, WATPTEMP */
/* 1013,   255,   255,    10,     4,    19, WATPDEN  */
/* 1014,   255,   255,    10,     4,    20, WATPDENA */
/* 1015,   255,   255,    10,     4,    21, PRTSAL   */
/* 1016,   240,   129,     0,    16,     3, RETOP    */
/* 1017,   234,     2,     1,     0,     5, BGRUN    */
/* 1018,   235,     2,     1,     0,     6, SSRUN    */
/* 1019,   160,   130,     2,     3,     5, SOILL    */
        
        
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

