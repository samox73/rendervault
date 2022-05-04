#########################
# Preamble
#########################
set(libname rendervault-core)
cmake_minimum_required(VERSION 3.21)
project(${libname}
        VERSION 0.1.0
        LANGUAGES CXX)

#########################
# Build library
#########################
add_library(${libname})
add_library(rendervault::${libname} ALIAS ${libname})
target_sources(${libname} PRIVATE
        Initializer.cpp
        GlfwWrapper.cpp
        RenderCore.cpp
        )
target_include_directories(${libname} PUBLIC
        ../../include
)
target_link_libraries(${libname} PUBLIC
        rendervault::rendervault-utils
)