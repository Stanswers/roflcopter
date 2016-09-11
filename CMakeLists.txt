cmake_minimum_required(VERSION 2.6)

project (roflcopter)
set(VERSION "0.9.0")
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
set (CMAKE_CXX_FLAGS "-std=c11")

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(man)
