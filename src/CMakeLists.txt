# This is the main CMake file for the src directory of NCEPLIBS-g2c.
#
# Ed Hartnett 12/29/22

# Set this to better handle files > 2 GB.
add_compile_definitions(_LARGEFILE64_SOURCE)

# Find required packages to use PNG.
if(USE_PNG)
  find_package(ZLIB REQUIRED)
  find_package(PkgConfig REQUIRED)
  find_package(PNG REQUIRED)
else()
  message(STATUS "Will not build PNG support")
endif()

# Find Jasper if it is desired.
if(USE_Jasper)
  find_package(Jasper 2.0.25 REQUIRED)
else()
  message(STATUS "Will not build Jasper support")
endif()

# Find OpenJpeg if it is desired.
if(USE_OpenJPEG)
  find_package(OpenJPEG REQUIRED)
else()
  message(STATUS "Will not build OpenJPEG support")
endif()

set(lib_name ${PROJECT_NAME})

# Specify the source code files for the library.
add_library(${lib_name} grib2_int.h cmplxpack.c compack.c
comunpack.c drstemplates.c g2_addfield.c g2_addgrid.c
g2_addlocal.c g2_create.c g2_free.c g2_getfld.c
g2_gribend.c g2_info.c g2_miss.c g2_unpack1.c
g2_unpack2.c g2_unpack3.c g2_unpack4.c g2_unpack5.c
g2_unpack6.c g2_unpack7.c gbits.c getdim.c
getpoly.c gridtemplates.c int_power.c misspack.c
mkieee.c pack_gp.c pdstemplates.c rdieee.c
reduce.c seekgb.c simpack.c simunpack.c specpack.c
specunpack.c util.c g2cxml.c g2cparams.c g2cfile.c
g2cdegrib2.c g2cprod.c g2cinq.c g2cindex.c g2cio.c g2ccompare.c)

set_property(TARGET ${lib_name} PROPERTY C_STANDARD 11)

# Find libxml2.
find_package(LibXml2 2.9.0 REQUIRED)
target_link_libraries(${lib_name} PRIVATE ${LIBXML2_LIBRARIES})
target_include_directories(${lib_name} PRIVATE "${LIBXML2_INCLUDE_DIR}")

# Set the compiler flags.
if(CMAKE_C_COMPILER_ID MATCHES "^(Intel)$")
  set(CMAKE_C_FLAGS "-g -traceback ${CMAKE_C_FLAGS}")
  set(CMAKE_C_FLAGS_RELEASE "-O3")
  set(CMAKE_C_FLAGS_DEBUG "-O0")
elseif(CMAKE_C_COMPILER_ID MATCHES "^(GNU|Clang|AppleClang)$")
  set(CMAKE_C_FLAGS "-g ${CMAKE_C_FLAGS}")
  set(CMAKE_C_FLAGS_RELEASE "-O3")
  set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb -Wall")
endif()

# Build with PNG.
if(PNG_FOUND)
  message(STATUS "Found PNG:")
  message(STATUS "      PNG include directories ${PNG_INCLUDE_DIR}")
  message(STATUS "      PNG libraries ${PNG_LIBRARIES}")
  target_sources(${lib_name} PRIVATE dec_png.c
                                     enc_png.c
                                     pngpack.c
                                     pngunpack.c)
  target_compile_definitions(${lib_name} PRIVATE USE_PNG)
  target_link_libraries(${lib_name} PRIVATE ${PNG_LIBRARIES})
  target_include_directories(${lib_name} PRIVATE "${PNG_INCLUDE_DIRS}")
  set(G2_PNG_ENABLED ON)
endif()

# Build with Jasper.
if(JASPER_FOUND)
  message(STATUS "Found JASPER:")
  message(STATUS "      JASPER include directories ${JASPER_INCLUDE_DIR}")
  message(STATUS "      JASPER libraries ${JASPER_LIBRARIES} version ${JASPER_VERSION}")
  target_sources(${lib_name} PRIVATE dec_jpeg2000.c
                                     enc_jpeg2000.c
                                     jpcpack.c
                                     jpcunpack.c)
  target_compile_definitions(${lib_name} PRIVATE USE_JPEG2000)
  target_link_libraries(${lib_name} PRIVATE ${JASPER_LIBRARIES})
  target_include_directories(${lib_name} PRIVATE "${JASPER_INCLUDE_DIR}")
  set(G2_JPEG2000_ENABLED ON)
  if(JASPER_VERSION_STRING VERSION_GREATER_EQUAL "3")
    message(STATUS "      JASPER is version 3.0 or greater")
    add_definitions(-DJASPER3)
  endif()
  add_definitions(-DJPEG)
endif()

# Build with OpenJPEG.
if(OPENJPEG_FOUND)
  message(STATUS "Found OpenJPEG:")
  message(STATUS "      OpenJPEG include directories ${OpenJPEG_INCLUDE_DIRS}")
  message(STATUS "      OpenJPEG libraries ${OpenJPEG_LIBRARIES}")
  target_sources(${lib_name} PRIVATE decenc_openjpeg.c
                                     jpcpack.c
                                     jpcunpack.c)
  target_compile_definitions(${lib_name} PRIVATE USE_OPENJPEG)
  target_link_libraries(${lib_name} PRIVATE ${OpenJPEG_LIBRARIES})
  target_include_directories(${lib_name} PRIVATE "${OpenJPEG_INCLUDE_DIRS}")
  set(G2_JPEG2000_ENABLED ON)
  add_definitions(-DJPEG)
endif()

# Build with pthreads.
if(PTHREADS)
  target_link_libraries(${lib_name} PRIVATE pthread)
endif()

# Create this header file, which has the contents of the VERSION file
# substituted in.
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/grib2.h.in" "${CMAKE_CURRENT_BINARY_DIR}/grib2.h"
  @ONLY)

set_target_properties(${lib_name} PROPERTIES PUBLIC_HEADER "${CMAKE_CURRENT_BINARY_DIR}/grib2.h")

target_include_directories(
  ${lib_name}
  PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR};${CMAKE_CURRENT_SOURCE_DIR}>"
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)

target_link_libraries(${lib_name} INTERFACE m)
if (WIN32)
  target_link_libraries(${lib_name} INTERFACE ws2_32)
endif()

# Install g2c library
install(
  TARGETS ${lib_name}
  EXPORT ${PROJECT_NAME}Exports
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Package config
include(CMakePackageConfigHelpers)
set(CONFIG_INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

export(EXPORT ${PROJECT_NAME}Exports
  NAMESPACE ${PROJECT_NAME}::
  FILE ${PROJECT_NAME}-targets.cmake)

# g2c-config.cmake
configure_package_config_file(
  ${CMAKE_SOURCE_DIR}/cmake/PackageConfig.cmake.in ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION ${CONFIG_INSTALL_DESTINATION})
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  DESTINATION ${CONFIG_INSTALL_DESTINATION})

# g2c-config-version.cmake
write_basic_package_version_file(
  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  DESTINATION ${CONFIG_INSTALL_DESTINATION})

# g2c-targets.cmake and g2c-targets-<build-type>.cmake
install(EXPORT ${PROJECT_NAME}Exports
  NAMESPACE ${PROJECT_NAME}::
  FILE ${PROJECT_NAME}-targets.cmake
  DESTINATION ${CONFIG_INSTALL_DESTINATION})

# XML data files.
set(XML_FILES Template.xml CodeFlag.xml)
install(FILES ${XML_FILES}
  DESTINATION ${CMAKE_INSTALL_LIBDIR})

