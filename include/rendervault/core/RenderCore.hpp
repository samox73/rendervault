#pragma once

#include <vulkan/vulkan.hpp>
//#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
//#define GLFW_EXPOSE_NATIVE_X11
#include <GLFW/glfw3native.h>

#include <rendervault/utils/Logger.hpp>

#include "GlfwWrapper.hpp"

struct RenderCore {
    // Vulkan objects
    vk::UniqueInstance instance_;
    vk::SurfaceKHR surface_;
    vk::UniqueDevice device_;
    vk::PhysicalDevice gpu_;

    // core-internal objects
    Logger log{"render_engine"};
    bool initialized_{};
    size_t frame_number_{};
    vk::Extent2D window_extent_{1700, 900};
    GlfwWrapper window_;

    // initializes everything in the engine
    void init();

    // shuts down the engine
    void cleanup();

    // draw loop
    void draw();

    // run main loop
    void run();
};