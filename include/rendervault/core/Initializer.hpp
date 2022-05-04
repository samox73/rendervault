#pragma once

#include <rendervault/core/GlfwWrapper.hpp>
#include <rendervault/utils/Logger.hpp>
#include <vulkan/vulkan.hpp>

class Initializer {
    static Logger log;

    static void printAvailableExtensions();

    static std::vector<char const*> getRequestedLayers();

    static bool requestedLayersAreAvailable(std::vector<char const *> const &layers,
                                        std::vector<vk::LayerProperties> const &properties);

   public:
    static vk::UniqueInstance createInstance(const GlfwWrapper &);
};