add_custom_command (OUTPUT ${CMAKE_BINARY_DIR}/man/roflcopter.1.gz
	COMMAND gzip -ck ${CMAKE_SOURCE_DIR}/man/roflcopter.1 > ${CMAKE_BINARY_DIR}/man/roflcopter.1.gz
	VERBATIM
)
add_custom_target(roflcopter.1 ALL DEPENDS ${CMAKE_BINARY_DIR}/man/roflcopter.1.gz)
install (FILES ${CMAKE_BINARY_DIR}/man/roflcopter.1.gz DESTINATION usr/man/man1)

