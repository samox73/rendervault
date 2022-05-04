#include <rendervault/core/GlfwWrapper.hpp>

void GlfwWrapper::init(size_t width, size_t height) {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window_ = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), "Vulkan", nullptr, nullptr);
    glfw_extensions_ = glfwGetRequiredInstanceExtensions(&glfw_extension_count_);
}

void GlfwWrapper::destroy() {
    glfwDestroyWindow(window_);
    glfwTerminate();
}

bool GlfwWrapper::should_close() { return glfwWindowShouldClose(window_); }
