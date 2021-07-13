# This is the cmake build file for the tests directory of the
# NCEPLIBS-g2c_UTILS project.
#
# Ed Hartnett, 7/11/21

add_executable(tst_g2_create tst_g2_create.c)
add_dependencies(tst_g2_create g2c)
target_link_libraries(tst_g2_create PRIVATE g2c)
add_test(NAME tst_g2_create COMMAND tst_g2_create)

