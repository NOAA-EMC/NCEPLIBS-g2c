# This is the CMake file for the utils directory of NCEPLIBS-g2c.
#
# Ed Hartnett 12/29/22
# Eric Engle 1/10/23

# Build the utilities.
add_executable(g2c_degrib2 g2c_degrib2.c)
target_include_directories(g2c_degrib2 PRIVATE ${CMAKE_BINARY_DIR}/src)
target_link_libraries(g2c_degrib2 PUBLIC g2c::g2c)
target_link_libraries(g2c_degrib2 PRIVATE ${PNG_LIBRARIES} ${JASPER_LIBRARIES} ${ZLIB_LIBRARY})
add_executable(g2c_compare g2c_compare.c)
target_include_directories(g2c_compare PRIVATE ${CMAKE_BINARY_DIR}/src)
target_link_libraries(g2c_compare PUBLIC g2c::g2c)
target_link_libraries(g2c_compare PRIVATE ${PNG_LIBRARIES} ${JASPER_LIBRARIES} ${ZLIB_LIBRARY})
add_executable(g2c_index g2c_index.c)
target_include_directories(g2c_index PRIVATE ${CMAKE_BINARY_DIR}/src)
target_link_libraries(g2c_index PUBLIC g2c::g2c)
target_link_libraries(g2c_index PRIVATE ${PNG_LIBRARIES} ${JASPER_LIBRARIES} ${ZLIB_LIBRARY})

# Install the utilites.
install(TARGETS g2c_degrib2 RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS g2c_compare RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS g2c_index RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})


