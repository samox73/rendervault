add_compile_definitions(LOG_LEVEL=3) # 0 = err, 1 = warn, 2 = info, 3 = debug

################
# Sub projects
################
add_subdirectory(core)
add_subdirectory(utils)

#########################
# Dependencies
#########################
find_package(Vulkan REQUIRED FATAL_ERROR)
find_package(X11 REQUIRED)
find_package(glfw3 REQUIRED)
find_package(tinyobjloader REQUIRED)

add_definitions(-DVK_USE_PLATFORM_XLIB_KHR)

################
# Binary
################
set(BINARY vulkan_run)
add_executable(${BINARY} main.cpp)
set_target_properties(${BINARY} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${BINARY} PUBLIC
        Vulkan::Vulkan
        rendervault::rendervault-core
        rendervault::rendervault-utils
        glfw
        ${X11_LIBRARIES}
        )

target_include_directories(${BINARY} PUBLIC
        ../include)

