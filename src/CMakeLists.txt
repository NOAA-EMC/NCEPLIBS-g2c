# This is the CMake file for the src directory of the NCEPLIBS-g2c
# project.
#
# Mark Potts, Kyle Gerheiser

# Create this header file, which has the contents of the VERSION file
# substituted in.
CONFIGURE_FILE("${CMAKE_SOURCE_DIR}/src/grib2.h.in" "${CMAKE_BINARY_DIR}/src/grib2.h"
  @ONLY)

set(c_src
    ${CMAKE_CURRENT_SOURCE_DIR}/cmplxpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/compack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/comunpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/dec_jpeg2000.c
    ${CMAKE_CURRENT_SOURCE_DIR}/dec_png.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drstemplates.c
    ${CMAKE_CURRENT_SOURCE_DIR}/enc_jpeg2000.c
    ${CMAKE_CURRENT_SOURCE_DIR}/enc_png.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_addfield.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_addgrid.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_addlocal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_create.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_free.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_getfld.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_gribend.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_info.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_miss.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_unpack1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_unpack2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_unpack3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_unpack4.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_unpack5.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_unpack6.c
    ${CMAKE_CURRENT_SOURCE_DIR}/g2_unpack7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/gbits.c
    ${CMAKE_CURRENT_SOURCE_DIR}/getdim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/getpoly.c
    ${CMAKE_CURRENT_SOURCE_DIR}/gridtemplates.c
    ${CMAKE_CURRENT_SOURCE_DIR}/int_power.c
    ${CMAKE_CURRENT_SOURCE_DIR}/jpcpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/jpcunpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/misspack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mkieee.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pack_gp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pdstemplates.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pngpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pngunpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/rdieee.c
    ${CMAKE_CURRENT_SOURCE_DIR}/reduce.c
    ${CMAKE_CURRENT_SOURCE_DIR}/seekgb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/simpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/simunpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/specpack.c
    ${CMAKE_CURRENT_SOURCE_DIR}/specunpack.c
    ${CMAKE_CURRENT_BINARY_DIR}/grib2.h
    PARENT_SCOPE)

# If OpenJPEG is in use, add this file.  
if(USE_OpenJPEG)
  set(c_src ${c_src} ${CMAKE_CURRENT_SOURCE_DIR}/decenc_openjpeg.c PARENT_SCOPE)
endif()
  
