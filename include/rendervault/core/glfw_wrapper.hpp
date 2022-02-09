//
// Created by samox on 2/9/22.
//

#ifndef VULKAN_ENGINE_GLFW_WRAPPER_HPP
#define VULKAN_ENGINE_GLFW_WRAPPER_HPP

#include <GLFW/glfw3.h>

class glfw_wrapper {
    GLFWwindow* window_;
    uint32_t glfw_extension_count_{};
    const char** glfw_extensions_;

   public:
    glfw_wrapper() = default;

    void init(size_t width, size_t height);

    void destroy();

    bool should_close();

    uint32_t get_glfw_extension_count() const { return glfw_extension_count_; }

    const char** get_glfw_extensions() const { return glfw_extensions_; }
};

#endif  // VULKAN_ENGINE_GLFW_WRAPPER_HPP
