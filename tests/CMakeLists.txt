# This is the cmake build file for the tests directory of the
# NCEPLIBS-g2c project.
#
# Ed Hartnett, 7/11/21
# Dusan Jovic

# Some test files are large and are kept on the NOAA EMC FTP
# site. This function is used to download such test data. It takes two
# arguments, the URL and the file to be downloaded.
function(PULL_DATA THE_URL THE_FILE)
  if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/${THE_FILE}")
    file(DOWNLOAD
      ${THE_URL}/${THE_FILE}
      ${CMAKE_CURRENT_BINARY_DIR}/${THE_FILE}
      SHOW_PROGRESS
      STATUS status
      INACTIVITY_TIMEOUT 30
      )
    list(GET status 0 status_num)
    if(NOT status_num EQUAL 0 OR NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/${THE_FILE}")
      message(FATAL_ERROR "Could not download ${THE_FILE}")
    endif()
  endif()
endfunction()

# Some very small test files may be committed to the repo. This
# function copies such a data file to the build directory.
FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/gdaswave.t00z.wcoast.0p16.f000.grib2
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/gdaswave.t00z.wcoast.0p16.f000.grib2.idx
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ref_gdaswave.degrib2.txt
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ref_WW3_Regional_US_West_Coast_20220718_0000.txt
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

# These are the XML files from the WMO with GRIB2 code data.
FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../src/CodeFlag.xml
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../src/Template.xml
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

# Run each test.
function(g2c_test name)
  add_executable(${name} ${name}.c)
  add_dependencies(${name} g2c)
  target_link_libraries(${name} PRIVATE g2c)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

# Does the user want to get extra test files from the FTP site, and
# run extra tests on them?
if(FTP_TEST_FILES)
  # Get the files from the FTP site.
  set(G2_FTP_URL "https://ftp.emc.ncep.noaa.gov/static_files/public/NCEPLIBS-g2")
  set(WW3_WEST_FILE "WW3_Regional_US_West_Coast_20220718_0000.grib2")
  set(WW3_EAST_FILE "WW3_Regional_US_East_Coast_20220717_0600.grib2")
  # Not using the East Coast file yet.
  # foreach(THE_FILE IN LISTS WW3_WEST_FILE WW3_EAST_FILE) 
  foreach(THE_FILE IN LISTS WW3_WEST_FILE) 
    PULL_DATA(${G2_FTP_URL} ${THE_FILE})
  endforeach()

  # Add tests that use the data downloaded from FTP.
  g2c_test(tst_ftp_degrib2)  
endif()

# Always run these tests.
g2c_test(tst_g2_create)
g2c_test(tst_g2_addgrid)
g2c_test(tst_g2_addfield)
g2c_test(tst_decode)
g2c_test(tst_gbits)
g2c_test(tst_gridtemplates)
g2c_test(tst_pdstemplates)
g2c_test(tst_drstemplates)
g2c_test(tst_unpack)
g2c_test(tst_getdim)
g2c_test(tst_simpack)
g2c_test(tst_addfield_spec)
g2c_test(tst_spec)
g2c_test(tst_com)
g2c_test(tst_g2_addlocal)
g2c_test(tst_seekgb)
g2c_test(tst_files)
g2c_test(tst_xml)
g2c_test(tst_error)
g2c_test(tst_params)
g2c_test(tst_params2)
g2c_test(tst_params3)
g2c_test(tst_degrib2)
g2c_test(tst_index)

# Run these tests only if libpng is linked.
if(USE_PNG)
  g2c_test(tst_png)
  g2c_test(tst_addfield2)
endif()

# Run these tests only if Jasper or OpenJPEG are linked.
if(USE_Jasper OR USE_OpenJPEG)
  g2c_test(tst_jpeg)
  g2c_test(tst_addfield3)
  g2c_test(tst_addfield4)
endif()
