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
set(SRC logger.cpp)
add_library(${libname})
add_library(rendervault::${libname} ALIAS ${libname})
target_sources(${libname} PRIVATE ${SRC})

target_include_directories(${libname} PUBLIC
        ${Boost_INCLUDE_DIRS}
        )

target_link_libraries(${libname}
        ${Boost_LIBRARIES}
        )

