//
// Created by samox on 2/9/22.
//

#ifndef VULKAN_ENGINE_GLFW_WRAPPER_HPP
#define VULKAN_ENGINE_GLFW_WRAPPER_HPP


#include <GLFW/glfw3.h>

class glfw_wrapper {
    GLFWwindow* window_;
public:
    glfw_wrapper() = default;

    void init(size_t width, size_t height);

    void destroy();

    bool should_close();
};


#endif //VULKAN_ENGINE_GLFW_WRAPPER_HPP
