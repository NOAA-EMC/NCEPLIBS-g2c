# This is the cmake build file for the tests directory of the
# NCEPLIBS-g2c_UTILS project.
#
# Ed Hartnett, 7/11/21

add_executable(tst_g2_create tst_g2_create.c)
target_link_libraries(tst_g2_create PRIVATE g2c::g2c)
add_test(NAME tst_g2_create COMMAND tst_g2_create)

include_directories(${PROJECT_SOURCE_DIR})


