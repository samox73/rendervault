//
// Created by samox on 2/9/22.
//

#ifndef VULKAN_ENGINE_GLFW_WRAPPER_HPP
#define VULKAN_ENGINE_GLFW_WRAPPER_HPP

#include <GLFW/glfw3.h>
#include <vector>

class GlfwWrapper {
    GLFWwindow* window_;
    uint32_t glfw_extension_count_{};
    const char** glfw_extensions_;

   public:
    GlfwWrapper() = default;

    void init(size_t width, size_t height);

    void destroy();

    bool should_close();

    uint32_t getGlfwExtensionCount() const { return glfw_extension_count_; }

    const char** getGlfwExtensions() const { return glfw_extensions_; }

    std::vector<const char*> getGlfwExtensionsVector() const {
        return std::vector<const char*>(glfw_extensions_, glfw_extensions_ + glfw_extension_count_);
    }
};

#endif  // VULKAN_ENGINE_GLFW_WRAPPER_HPP
