# This is the cmake build file for the tests directory of the
# NCEPLIBS-g2c project.
#
# Ed Hartnett, 7/11/21
# Dusan Jovic

function(g2c_test name)
  add_executable(${name} ${name}.c)
  add_dependencies(${name} g2c)
  target_link_libraries(${name} PRIVATE g2c)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

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
g2c_test(tst_png)
g2c_test(tst_jpeg)
g2c_test(tst_addfield_spec)
g2c_test(tst_spec)
g2c_test(tst_com)


