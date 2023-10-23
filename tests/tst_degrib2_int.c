/* This is a test for the NCEPLIBS-g2c project.
 *
 * This test is for the internal functions used by g2c_degrib2()
 * function.
 *
 * Ed Hartnett 11/16/22
 */
#include "grib2_int.h"

#define NUM_PROD_TEST 11

int
main()
{
    printf("Testing g2c degrib2 internal functions.\n");
    printf("Testing g2c_get_level_desc()...\n");
    {
#define DATE_TIME_LEN 100
        int prod_template_num[NUM_PROD_TEST] = {0, 0, 0, 0, 8, 2, 0, 2, 15, 9, 0};
        long long int prod_template_value[NUM_PROD_TEST][G2C_MAX_PDS_TEMPLATE_MAPLEN] = {
            {2, 1, 2, 0, 11, 0, 0, 1, 0, 1, 0, 1, 255, 0, 0},
            {2, 10, 0, 0, 81, 0, 0, 1, 0, 100, 0, 80000, 255, 0, 0},
            {0, 21, 2, 255, 104, 65535, 255, 1, 1, 103, 0, 2, 255, 0, 0},
            {19, 238, 2, 255, 104, 65535, 255, 1, 1, 100, 0, 40000, 100, 0, 30000},
            {1, 228, 2, 255, 104, 65535, 255, 1, 0, 1, 0, 0, 255, 0, 0, 2022, 11, 17, 20, 0, 0, 1, 0, 1, 2, 1, 1, 1, 0},
	    {0, 192, 4, 70, 70, 0, 0, 1, 0, 106, 0, 0, 106, 1, 1, 0, 20},
	    {0, 192, 2, 0, 98, 0, 0, 1, 0, 106, 2, 0, 106, 2, 10},
	    {3, 1, 4, 70, 70, 0, 0, 1, 0, 101, 0, 0, 255, 0, 0, 0, 20},
	    {0, 27, 2, 255, 104, 65535, 255, 1, 1, 103, 0, 610, 100, 0, 40000, 241, 241, 241},
	    {1, 8, 2, 255, 104, 65535, 255, 1, 0, 1, 0, 0, 255, 0, 0, 255, 255, 1, -127, 255, 3, 254, 2022, 11, 17, 20, 0, 0, 1, 0, 1, 2, 1, 1, 1, 0},
	    {19, 236, 2, 255, 104, 65535, 255, 1, 1, 102, 0, 0, 255, 0, 0}
        };
        char expected_level_desc[NUM_PROD_TEST][G2C_MAX_GRIB_LEVEL_DESC_LEN + 1] = {
            " Surface", " 800 mb", "2 m above ground", " 400 -  300 mb",
            " Surface", "0 - .1 m DBLY", " 0 - .10 m DBLY", " Mean Sea Level", "  103 (Unknown Lvl)",
	    " Surface", "0 m above MSL"};
        char level_desc[G2C_MAX_GRIB_LEVEL_DESC_LEN + 1];
        short year[NUM_PROD_TEST] = {2021, 2022, 2022, 2022, 2022, 2022, 2022, 2022, 2022, 2022, 2022};
        unsigned char month[NUM_PROD_TEST] = {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11};
        unsigned char day[NUM_PROD_TEST] = {30, 6, 6, 6, 17, 17, 17, 17, 17, 17, 17};
        unsigned char hour[NUM_PROD_TEST] = {0, 12, 12, 12, 19, 12, 12, 12, 19, 19, 19};
        unsigned char minute[NUM_PROD_TEST] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        unsigned char second[NUM_PROD_TEST] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        char expected_date_time[NUM_PROD_TEST][DATE_TIME_LEN + 1] = {
            "valid  0 hour after 2021113000:00:00",
            "valid  0 hour after 2022110612:00:00",
            "valid  1 hour after 2022110612:00:00",
            "valid  1 hour after 2022110612:00:00",
            "(0 -1 hr) valid  0 hour after 2022111719:00:00 to 2022111720:00:00",
	    "valid  0 hour after 2022111712:00:00",
	    "valid  0 hour after 2022111712:00:00",
	    "valid  0 hour after 2022111712:00:00",
	    "valid  1 hour after 2022111719:00:00",
	    "(0 -1 hr) valid  0 hour after 2022111719:00:00 to 2022111720:00:00",
	    "valid  1 hour after 2022111719:00:00"
        };
        int t;
        int ret;

        for (t = 0; t < NUM_PROD_TEST; t++)
        {
            char date_time[DATE_TIME_LEN + 1];
            
            /* First test the level description. */
            if ((ret = g2c_get_level_desc(prod_template_num[t], prod_template_value[t], level_desc)))
                return ret;
            if (strcmp(level_desc, expected_level_desc[t]))
            {
                printf("level_desc |%s| \nexpected |%s|\n", level_desc, expected_level_desc[t]);
                return G2C_ERROR;
            }

            /* Now test the date/time. */
            if ((ret = g2c_get_datetime(prod_template_num[t], prod_template_value[t], year[t], month[t],
                                        day[t], hour[t], minute[t], second[t], date_time)))
                return ret;
            if (strcmp(date_time, expected_date_time[t]))
            {
                printf("date_time %s \nexpected %s\n", date_time, expected_date_time[t]);
                return G2C_ERROR;
            }
        }
    }
    printf("ok!\n");
    printf("SUCCESS!\n");
    return 0;
}
