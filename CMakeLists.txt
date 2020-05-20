cmake_minimum_required(VERSION 3.15)

file(STRINGS "VERSION" pVersion)

project(
  g2c
  VERSION ${pVersion}
  LANGUAGES C)

if(NOT CMAKE_BUILD_TYPE MATCHES "^(Debug|Release|RelWithDebInfo|MinSizeRel)$")
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                               "MinSizeRel" "RelWithDebInfo")
endif()

if(NOT CMAKE_C_COMPILER_ID MATCHES "^(Intel|GNU|Clang|AppleClang)$")
  message(WARNING "Compiler not officially supported: ${CMAKE_C_COMPILER_ID}")
endif()

option(USE_PNG      "Use PNG library"      ON)
option(USE_Jasper   "Use Jasper library"   ON)

if(USE_PNG)
  find_package(ZLIB REQUIRED)
  find_package(PNG REQUIRED)
else()
  message(STATUS "Will not build PNG support")
endif()

if(USE_Jasper)
  find_package(Jasper REQUIRED)
else()
  message(STATUS "Will not build Jasper support")
endif()

if(CMAKE_C_COMPILER_ID MATCHES "^(Intel)$")
  set(CMAKE_C_FLAGS "-g -traceback")
  set(CMAKE_C_FLAGS_RELEASE "-O3")
  set(CMAKE_C_FLAGS_DEBUG "-O0")
elseif(CMAKE_C_COMPILER_ID MATCHES "^(GNU|Clang|AppleClang)$")
  set(CMAKE_C_FLAGS "-g")
  set(CMAKE_C_FLAGS_RELEASE "-O3")
  set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb -Wall")
endif()

add_subdirectory(src)

set(lib_name ${PROJECT_NAME})
set(versioned_lib_name ${PROJECT_NAME}_v${PROJECT_VERSION})

add_library(${lib_name} STATIC ${c_src})

target_compile_definitions(${lib_name} PUBLIC __64BIT__)

set(private_includes "")

if(PNG_FOUND)
  message(STATUS "Found PNG:")
  message(STATUS "      PNG include directories ${PNG_INCLUDE_DIR}")
  message(STATUS "      PNG libraries ${PNG_LIBRARIES}")
  target_compile_definitions(${lib_name} PRIVATE USE_PNG)
  target_link_libraries(${lib_name} INTERFACE ${PNG_LIBRARIES})
  list(APPEND private_includes "${PNG_INCLUDE_DIRS}")
endif()

if(JASPER_FOUND)
  message(STATUS "Found JASPER:")
  message(STATUS "      JASPER include directories ${JASPER_INCLUDE_DIR}")
  message(STATUS "      JASPER libraries ${JASPER_LIBRARIES}")
  target_compile_definitions(${lib_name} PRIVATE USE_JPEG2000)
  target_link_libraries(${lib_name} INTERFACE ${JASPER_LIBRARIES})
  list(APPEND private_includes "${JASPER_INCLUDE_DIR}")
endif()

target_link_libraries(${lib_name} INTERFACE m)

set_target_properties(${lib_name} PROPERTIES OUTPUT_NAME ${versioned_lib_name})
set_target_properties(${lib_name} PROPERTIES PUBLIC_HEADER "src/grib2.h")

target_include_directories(
  ${lib_name}
  PRIVATE ${private_includes}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)

install(
  TARGETS ${lib_name}
  EXPORT ${PROJECT_NAME}-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

install(EXPORT ${PROJECT_NAME}-config
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/${PROJECT_NAME})
