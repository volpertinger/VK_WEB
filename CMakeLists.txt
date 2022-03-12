cmake_minimum_required(VERSION 3.21)
project(VK_education_C_Cxx)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

file(GLOB SOURCES_HW_1 "Sources/*.c")
file(GLOB INCLUDE_HW_1 "Headers/*.h")
file(GLOB EXC_HW_1 "main.c")
file(GLOB EXC_HW_1_TEST "Tests/*.cpp")

add_library(HW_1_lib ${INCLUDE_HW_1} ${SOURCES_HW_1})
add_executable(HW_1 ${EXC_HW_1})
target_link_libraries(HW_1 HW_1_lib)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(HW_TESTS ${EXC_HW_1_TEST})
target_link_libraries(HW_TESTS HW_1_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(HW_TESTS)
