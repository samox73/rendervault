#########################
# Preamble
#########################
cmake_minimum_required(VERSION 3.21)
set(libname rendervault-core)
project(${libname}
        VERSION 0.1.0
        LANGUAGES CXX)

#########################
# Build library
#########################
add_library(${libname})
add_library(rendervault::${libname} ALIAS ${libname})
target_sources(${libname} PRIVATE
        initializers.cpp
        glfw_wrapper.cpp
        render_engine.cpp
        )
target_include_directories(${libname} PUBLIC
        ../../include
)
target_link_libraries(${libname} PUBLIC
        rendervault::rendervault-utils
)