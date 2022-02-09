#########################
# Preamble
#########################
cmake_minimum_required(VERSION 3.21)
project(vulkan-engine)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(tests)
add_subdirectory(src)

