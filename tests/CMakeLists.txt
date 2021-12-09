# This is the cmake build file for the tests directory of the
# NCEPLIBS-g2c project.
#
# Ed Hartnett, 7/11/21
# Dusan Jovic

# Copy test data.
FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/gdaswave.t00z.wcoast.0p16.f000.grib2
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/gdaswave.t00z.wcoast.0p16.f000.grib2.idx
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

# Run each test.
function(g2c_test name)
  add_executable(${name} ${name}.c)
  add_dependencies(${name} g2c)
  target_link_libraries(${name} PRIVATE g2c)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

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
