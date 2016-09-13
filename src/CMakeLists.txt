find_package(Curses REQUIRED)
include_directories (${CURSES_INCLUDE_DIRS})
include_directories (${CMAKE_SOURCE_DIR}/include)

add_executable (roflcopter roflcopter.c)
target_link_libraries (roflcopter ${CURSES_LIBRARIES})

install (TARGETS roflcopter DESTINATION usr/bin)

