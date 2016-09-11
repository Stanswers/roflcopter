cmake_minimum_required(VERSION 2.6)

project (roflcopter)
set(VERSION "0.1.0")
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(man)
