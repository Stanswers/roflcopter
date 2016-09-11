add_custom_command (OUTPUT ${CMAKE_SOURCE_DIR}/build/man/roflcopter.1.gz
	COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/build/man
	COMMAND gzip < ${CMAKE_SOURCE_DIR}/man/roflcopter.1 > ${CMAKE_SOURCE_DIR}/build/man/roflcopter.1.gz
	VERBATIM
)
add_custom_target(roflcopter.1 ALL DEPENDS ${CMAKE_SOURCE_DIR}/build/man/roflcopter.1.gz)
install (FILES ${CMAKE_SOURCE_DIR}/build/man/roflcopter.1.gz DESTINATION usr/man/man1)

