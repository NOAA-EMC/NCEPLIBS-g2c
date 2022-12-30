# This is the CMake file for the utils directory of NCEPLIBS-g2c.
#
# Ed Hartnett 12/29/22

# Build the utilities.
add_executable(g2c_degrib2 g2c_degrib2.c)
target_link_libraries(g2c_degrib2 PRIVATE g2c ${PNG_LIBRARIES} ${JASPER_LIBRARIES} ${ZLIB_LIBRARY})
add_executable(g2c_compare g2c_compare.c)
target_link_libraries(g2c_compare PRIVATE g2c ${PNG_LIBRARIES} ${JASPER_LIBRARIES} ${ZLIB_LIBRARY})

# Install the utilites.
install(TARGETS g2c_degrib2 RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS g2c_compare RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})


