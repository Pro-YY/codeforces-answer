cmake_minimum_required(VERSION 3.4)
set (PROJECT main)

file (GLOB PROJECT_SRCS *.c)
project (${PROJECT} C)
add_executable (${PROJECT} ${PROJECT_SRCS})
target_link_libraries(${PROJECT} m)
