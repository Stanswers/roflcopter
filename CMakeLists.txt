cmake_minimum_required (VERSION 2.6)
project (roflcopter)
find_package (Curses REQUIRED)
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
include_directories (${CURSES_INCLUDE_DIRS})
add_executable (roflcopter roflcopter.c)
target_link_libraries (roflcopter ${CURSES_LIBRARIES})
add_custom_command (OUTPUT ${CMAKE_BINARY_DIR}/roflcopter.1.gz
	COMMAND gzip -ck ${CMAKE_SOURCE_DIR}/roflcopter.1 > ${CMAKE_BINARY_DIR}/roflcopter.1.gz
	VERBATIM
)
add_custom_target(roflcopter.1 ALL DEPENDS ${CMAKE_BINARY_DIR}/roflcopter.1.gz)
install (TARGETS roflcopter DESTINATION usr/bin)
install (FILES ${CMAKE_BINARY_DIR}/roflcopter.1.gz DESTINATION usr/man/man1)
