# This is the cmake build file for the tests directory of the
# NCEPLIBS-g2c_UTILS project.
#
# Ed Hartnett, 7/11/21

target_include_directories(test ${PROJECT_SOURCE_DIR})

add_executable(tst_g2_create tst_g2_create.c)
add_test(NAME tst_g2_create COMMAND tst_g2_create)
target_link_libraries(tst_g2_create g2c)


