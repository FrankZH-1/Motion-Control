cmake_minimum_required(VERSION 3.16)
project(motion_control LANGUAGES CXX)

add_executable(motion_control src/main.cpp)
set_target_properties(motion_control PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(motion_control PRIVATE -Wall -Wextra -Wpedantic)
endif()
