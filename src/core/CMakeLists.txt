#########################
# Preamble
#########################
cmake_minimum_required(VERSION 3.21)
set(libname rendervault)
project(${libname}
        VERSION 0.1.0
        LANGUAGES CXX)

#########################
# Build library
#########################
set(SRC render_engine.cpp)
add_library(${libname}
        initializers.cpp
        glfw_wrapper.cpp)
add_library(rendervault::${libname} ALIAS ${libname})
target_sources(${libname} PUBLIC ${SRC})