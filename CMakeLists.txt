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

find_package(Jasper REQUIRED)
find_package(PNG REQUIRED)
find_package(ZLIB REQUIRED)

if(CMAKE_C_COMPILER_ID MATCHES "^(Intel)$")
  set(CMAKE_C_FLAGS "-g -O3")
  set(CMAKE_C_FLAGS_RELEASE "-O3")
elseif(CMAKE_C_COMPILER_ID MATCHES "^(GNU|Clang|AppleClang)$")
  set(CMAKE_C_FLAGS "-g -O3")
  set(CMAKE_C_FLAGS_DEBUG "-ggdb -Wall")
endif()

add_subdirectory(src)

set(lib_name ${PROJECT_NAME})
set(versioned_lib_name ${PROJECT_NAME}_v${PROJECT_VERSION})

add_library(${lib_name} STATIC ${c_src})

target_compile_definitions(${lib_name} PUBLIC __64BIT__)
if(JASPER_FOUND)
  target_compile_definitions(${lib_name} PRIVATE USE_JPEG2000)
endif()
if(PNG_FOUND)
  target_compile_definitions(${lib_name} PRIVATE USE_PNG)
endif()

set_target_properties(${lib_name} PROPERTIES OUTPUT_NAME ${versioned_lib_name})
set_target_properties(${lib_name} PROPERTIES PUBLIC_HEADER "src/grib2.h")

target_include_directories(
  ${lib_name}
  PRIVATE ${ZLIB_INCLUDE_DIRS} ${PNG_INCLUDE_DIRS} ${JASPER_INCLUDE_DIR}
  PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)

target_link_libraries(${lib_name} INTERFACE m)
if(JASPER_FOUND)
  target_link_libraries(${lib_name} INTERFACE ${JASPER_LIBRARIES})
endif()
if(PNG_FOUND)
  target_link_libraries(${lib_name} INTERFACE ${PNG_LIBRARIES})
endif()

install(
  TARGETS ${lib_name}
  EXPORT ${PROJECT_NAME}-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

install(EXPORT ${PROJECT_NAME}-config
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/${PROJECT_NAME})
