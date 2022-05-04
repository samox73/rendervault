#########################
# Preamble
#########################
set(libname rendervault-utils)
cmake_minimum_required(VERSION 3.13)
project(${libname}
        VERSION 0.1.0
        LANGUAGES CXX)

#########################
# Build library
#########################
add_library(${libname})
add_library(rendervault::${libname} ALIAS ${libname})
target_sources(${libname} PRIVATE Logger.cpp)
target_include_directories(${libname} PUBLIC
        ../../include
)