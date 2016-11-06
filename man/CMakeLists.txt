set(ROFL_BUILD_PATH ${CMAKE_SOURCE_DIR}/build)
set(MAN_OUTPUT_PATH ${ROFL_BUILD_PATH}/man)
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX /)
endif()

add_custom_command(OUTPUT ${MAN_OUTPUT_PATH}/roflcopter.1.gz
	COMMAND mkdir -p ${MAN_OUTPUT_PATH}
	COMMAND gzip < ${CMAKE_SOURCE_DIR}/man/roflcopter.1 > ${MAN_OUTPUT_PATH}/roflcopter.1.gz
	VERBATIM
)
add_custom_target(roflcopter.1 ALL DEPENDS ${MAN_OUTPUT_PATH}/roflcopter.1.gz SOURCES ${CMAKE_SOURCE_DIR}/man/roflcopter.1)
install(FILES ${ROFL_BUILD_PATH}/man/roflcopter.1.gz DESTINATION usr/man/man1)
