# This is the cmake build file for the tests directory of the
# NCEPLIBS-g2c_UTILS project.
#
# Ed Hartnett, 7/11/21

if(CMAKE_Fortran_COMPILER_ID MATCHES "^(Intel)$")
  set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -r8 -convert big_endian -assume byterecl")
elseif(CMAKE_Fortran_COMPILER_ID MATCHES "^(GNU)$")
  set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -ffree-line-length-0 -fdefault-real-8 -fconvert=big-endian")
endif()

include_directories(${PROJECT_SOURCE_DIR})

add_executable(tst_g2_create tst_g2_create.c)
add_test(NAME tst_g2_create COMMAND tst_g2_create)
target_link_libraries(tst_g2_create g2c)


