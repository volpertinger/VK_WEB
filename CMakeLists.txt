cmake_minimum_required(VERSION 3.14)
project(VK_education_C_Cxx)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES "Sources/*.c")
file(GLOB INCLUDE "Headers/*.h")
file(GLOB EXC "main.c")

add_library(LIB ${INCLUDE} ${SOURCES})
add_executable(main ${EXC})
target_link_libraries(main ${LIB})