# This is the cmake build file for the tests directory of the
# NCEPLIBS-g2c project.
#
# Ed Hartnett, 7/11/21
# Dusan Jovic
# Eric Engle 1/10/23

message(STATUS "Building test directory...")

# Some test files are large and are kept on the NOAA EMC FTP
# site. This function is used to download such test data. It takes two
# arguments, the URL and the file to be downloaded.
function(PULL_DATA THE_URL THE_FILE)
  # If the TEST_FILE_DIR was specified, look for our test data files
  # there before FTPing them. Developers can keep all test files on
  # their machines, and save the time of downloading them every time.
  if(NOT ${TEST_FILE_DIR} STREQUAL ".")
    message(STATUS "Checking for ${TEST_FILE_DIR}/${THE_FILE}.")
    if (EXISTS ${TEST_FILE_DIR}/${THE_FILE})
      message(STATUS "Copying file ${TEST_FILE_DIR}/${THE_FILE} to test data directory.")
      FILE(COPY ${TEST_FILE_DIR}/${THE_FILE}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)
    endif()
  endif()
  if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/data/${THE_FILE}")
    message(STATUS "Downloading file ${CMAKE_CURRENT_BINARY_DIR}/data/${THE_FILE}.")
    file(DOWNLOAD
      ${THE_URL}/${THE_FILE}
      ${CMAKE_CURRENT_BINARY_DIR}/data/${THE_FILE}
      SHOW_PROGRESS
      STATUS status
      INACTIVITY_TIMEOUT 30
    )
    list(GET status 0 status_num)
    if(NOT status_num EQUAL 0 OR NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/data/${THE_FILE}")
      message(FATAL_ERROR "Could not download ${THE_FILE}")
    endif()
  endif()
endfunction()

# Some very small test files may be committed to the repo. Copies
# tests data files to the build directory.
set(REF_FILES "gdaswave.t00z.wcoast.0p16.f000.grib2.idx"
  "gdaswave.t00z.wcoast.0p16.f000.grib2"
  "ref_blend.t19z.core.f001.co.grib2.degrib2"
  "ref_blend.t19z.core.f001.co.grib2.grb2index"
  "ref_cmc_geavg.t12z.pgrb2a.0p50.f000.degrib2"
  "ref_cmc_geavg.t12z.pgrb2a.0p50.f000.grb2index"
  "ref_flxf2022111712.01.2022111712.grb2.degrib2"
  "ref_flxf2022111712.01.2022111712.grb2.grb2index"
  "ref_gdas.t12z.pgrb2.1p00.anl.degrib2"
  "ref_gdas.t12z.pgrb2.1p00.anl.grib2.degrib2"
  "ref_gdas.t12z.pgrb2.1p00.anl.grib2.grb2index"
  "ref_gdaswave.t00z.wcoast.0p16.f000.grib2.degrib2"
  "ref_gdaswave.t00z.wcoast.0p16.f000.grb2index"
  "ref_GLOBAL.grib2.2022103000.0000.degrib2"
  "ref_GLOBAL.grib2.2022103000.0000.grb2index"
  "ref_hiresw.t00z.arw_5km.f00.hi.grib2.degrib2"
  "ref_hiresw.t00z.arw_5km.f00.hi.grib2.grb2index"
  "ref_naefs_ge10pt.t12z.pgrb2a.0p50_bcf003.degrib2"
  "ref_naefs_ge10pt.t12z.pgrb2a.0p50_bcf003.grb2index"
  "ref_rap.t00z.awp130pgrbf00.grib2.degrib2"
  "ref_rap.t00z.awp130pgrbf00.grib2.grb2index"
  "ref_seaice.t00z.grb.grib2.degrib2"
  "ref_seaice.t00z.grb.grib2.grb2index"
  "ref_sgx_nwps_CG3_20221117_1200.grib2.degrib2"
  "ref_sgx_nwps_CG3_20221117_1200.grib2.grb2index"
  "ref_WW3_Regional_US_West_Coast_20220718_0000.degrib2"
  "ref_WW3_Regional_US_West_Coast_20220718_0000.grb2index"
  "ref_WW3_Regional_US_West_Coast_20220718_0000.txt"
  "testgrib2.grb2"
  "ref_testgrib2.grb2.degrib2"
  "ref_gdaswave_2.grib1.idx"
  "ref_tst_jasper_warning.txt"
  )

# Copy large files if needed.
if(FTP_LARGE_TEST_FILES)
  set(REF_FILES ${REF_FILES} "ref_fv3lam.t00z.prslev.f000.grib2.degrib2")
endif()

foreach(THE_FILE IN LISTS REF_FILES)
  FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/${THE_FILE}
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)
endforeach()

# These are the CSV files from the WMO with GRIB2 code data.
if(BUILD_G2C)
  FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../src/CodeFlag.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
  FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../src/Template.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endif()

# Build a C program test.
function(g2c_build_test name)
  add_executable(${name} ${name}.c g2c_test_util.c)
  target_link_libraries(${name} PUBLIC g2c::g2c)
endfunction()

# Build a C program test.
function(g2c_build_test name)
  add_executable(${name} ${name}.c g2c_test_util.c)
  target_link_libraries(${name} PUBLIC g2c::g2c)
endfunction()

# Run a C program test.
function(g2c_test name)
  g2c_build_test(${name})
  add_test(NAME ${name} COMMAND ${name})
endfunction()

# Run a test with pthreads, if configured.
function(g2c_ptest name)
  g2c_test(${name})
  if(PTHREADS)
    target_compile_definitions(${name} PRIVATE -DPTHREADS)
    target_link_libraries(${name} PRIVATE pthread)
  endif()
endfunction()

# Run each shell test.
function(gu_test name)
  # Copy the test script.
  file(COPY "${CMAKE_SOURCE_DIR}/tests/${name}.sh"
    DESTINATION ${CMAKE_BINARY_DIR}/tests
    FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
  # Add the shell script as a test.
  add_test(NAME ${name}.sh COMMAND bash ${name}.sh)
  # Turn off memory checking in CI for this test.
  set_tests_properties(${name}.sh PROPERTIES LABELS noMemcheck)
endfunction()

# Does the user want to get extra test files from the FTP site, and
# run extra tests on them?
if(FTP_TEST_FILES)
  # Get the files from the FTP site.
  set(G2_FTP_URL "https://ftp.emc.ncep.noaa.gov/static_files/public/NCEPLIBS-g2")
  set(FTP_FILES "WW3_Regional_US_West_Coast_20220718_0000.grib2"
    "WW3_Regional_US_East_Coast_20220717_0600.grib2"
    "gdas.t12z.pgrb2.1p00.anl.grib2" "blend.t19z.core.f001.co.grib2"
    "cmc_geavg.t12z.pgrb2a.0p50.f000"
    "flxf2022111712.01.2022111712.grb2"
    "GLOBAL.grib2.2022103000.0000" "hiresw.t00z.arw_5km.f00.hi.grib2"
    "naefs_ge10pt.t12z.pgrb2a.0p50_bcf003"
    "rap.t00z.awp130pgrbf00.grib2" "seaice.t00z.grb.grib2"
    "sgx_nwps_CG3_20221117_1200.grib2" "aqm.t12z.max_8hr_o3.227.grib2")
  foreach(THE_FILE IN LISTS FTP_FILES)
    PULL_DATA(${G2_FTP_URL} ${THE_FILE})
  endforeach()

  if(FTP_LARGE_TEST_FILES)
    set(LARGE_FTP_FILES "fv3lam.t00z.prslev.f000.grib2")
    foreach(THE_FILE IN LISTS LARGE_FTP_FILES)
      PULL_DATA(${G2_FTP_URL} ${THE_FILE})
    endforeach()
    add_definitions(-DLARGE_FTP_TESTS)
  endif()

  if(FTP_EXTRA_TEST_FILES)
    set(EXTRA_FTP_FILES MRMS_MultiSensor_QPE_24H_Pass2_00.00_20230621-110000.grib2
      GFSPRS.GrbF06 rrfs.t18z.prslev.f000.grib2)
    foreach(THE_FILE IN LISTS EXTRA_FTP_FILES)
      PULL_DATA(${G2_FTP_URL} ${THE_FILE})
    endforeach()
  endif()

  # Add this preprocessor definition so test files can conditionally
  # include testing based on FTP files.
  add_definitions(-DFTP_TEST_FILES)

  # Run this test only if FTP test files are used.
  if(BUILD_G2C)
    g2c_ptest(tst_aqm)
  endif()
endif()

# Always run these tests.
g2c_test(tst_g2_create)
g2c_test(tst_g2_addgrid)
g2c_test(tst_g2_addfield)
g2c_test(tst_decode)
g2c_test(tst_gbits)
g2c_test(tst_gridtemplates)
g2c_test(tst_get_grid_template)
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

# Run these tests if the g2c API has been built.
if(BUILD_G2C)
  g2c_test(tst_index1)
  g2c_test(tst_csv)
  g2c_test(tst_error)
  g2c_test(tst_params)
  g2c_test(tst_params2)
  g2c_test(tst_params3)
  g2c_test(tst_io)
  g2c_test(tst_metacmp)
  g2c_test(tst_inq)
  g2c_test(tst_degrib2_int)
  g2c_test(tst_degrib2_fast)
  g2c_test(tst_degrib2)
  g2c_test(tst_degrib2_ftp_all)
  g2c_test(tst_index)
  g2c_ptest(tst_files)
  g2c_ptest(tst_g2_testfile)
endif()

# Run these tests only if libaec is linked.
if(USE_AEC)
  g2c_test(tst_aec)
endif()

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
  g2c_build_test(tst_jasper_warning)
endif()

# Test for warnings from jasper.
if(USE_Jasper)
  gu_test(run_jasper_warning_test)
endif()

# Run these shell tests, which require Jasper.
if(BUILD_G2C)
  if(USE_Jasper)
    if(UTILS)
      gu_test(run_compare_tests)
      if(FTP_TEST_FILES)
	gu_test(run_ftp_index_tests)
      endif()
      if(FTP_LARGE_TEST_FILES)
	gu_test(run_large_index_tests)
      endif()
      if(FTP_EXTRA_TEST_FILES)
	gu_test(run_extra_index_tests)
      endif()
    endif()
  endif()
endif()

# Run these extra tests if you have the data files to do so.
if (BUILD_G2C)
  if(FTP_EXTRA_TEST_FILES)
    g2c_test(tst_mrms)
  endif()
endif()





