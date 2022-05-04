#include <rendervault/core/Initializer.hpp>
#include <rendervault/core/RenderCore.hpp>

void RenderCore::init() {
    window_.init(window_extent_.width, window_extent_.height);
    instance_ = Initializer::createInstance(window_);

    // TODO move to correct place
    auto pfnVkCreateDebugUtilsMessengerEXT = reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(
        instance_.get().getProcAddr("vkCreateDebugUtilsMessengerEXT"));
    if (!pfnVkCreateDebugUtilsMessengerEXT) {
        throw std::runtime_error("GetInstanceProcAddr: Unable to find pfnVkCreateDebugUtilsMessengerEXT function.");
    }
    auto pfnVkDestroyDebugUtilsMessengerEXT = reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(
        instance_.get().getProcAddr("vkDestroyDebugUtilsMessengerEXT"));
    if (!pfnVkDestroyDebugUtilsMessengerEXT) {
        throw std::runtime_error("GetInstanceProcAddr: Unable to find pfnVkDestroyDebugUtilsMessengerEXT function.");
    }

    initialized_ = true;
}

void RenderCore::cleanup() {
    if (initialized_) {
        window_.destroy();
    }
}

void RenderCore::draw() {}

void RenderCore::run() {
    while (!window_.should_close()) {
        glfwPollEvents();
        draw();
    }
}
