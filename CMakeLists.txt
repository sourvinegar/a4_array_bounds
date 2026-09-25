cmake_minimum_required(VERSION 3.10)
# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# used internally by CMake to identify your project
project(a4_array_bounds)
# Include the directory headers are located
include_directories(${CMAKE_SOURCE_DIR}/include/src)
# Add the main executable
add_executable(main src/main.cpp src/array_bouns.cpp)
# add_executable(my_test src/prime.cpp tests/test.cpp)