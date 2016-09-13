set(ROFL_BUILD_PATH ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${ROFL_BUILD_PATH}/bin)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

set(ROFL_BUILD_PATH ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${ROFL_BUILD_PATH}/bin)

add_executable(roflcopter roflcopter.c)
target_link_libraries(roflcopter ${CURSES_LIBRARIES})

install(TARGETS roflcopter DESTINATION usr/bin)
