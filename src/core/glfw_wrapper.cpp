//
// Created by samox on 2/9/22.
//

#include "../../include/rendervault/core/glfw_wrapper.hpp"

void glfw_wrapper::init(size_t width, size_t height) {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window_ = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), "Vulkan", nullptr, nullptr);
}

void glfw_wrapper::destroy() {
    glfwDestroyWindow(window_);
    glfwTerminate();
}

bool glfw_wrapper::should_close() {
    return glfwWindowShouldClose(window_);
}
