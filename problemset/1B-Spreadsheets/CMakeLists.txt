cmake_minimum_required(VERSION 2.8)

set (PROJECT main)

set (CMAKE_C_COMPILER "/usr/bin/clang")
set (CMAKE_C_FLAGS  "-Wall -std=c11")
set (CMAKE_C_FLAGS_DEBUG  "-g") # cmake -DCMAKE_BUILD_TYPE=Debug
set (CMAKE_C_FLAGS_RELEASE "-O4 -DNDEBUG")

project (${PROJECT} C)
file (GLOB PROJECT_SRCS *.c)
add_executable (${PROJECT} ${PROJECT_SRCS})
target_link_libraries(${PROJECT} m)
