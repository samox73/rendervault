#include <rendervault/core/Initializer.hpp>
#include <string>

Logger Initializer::log{"initializer"};

vk::UniqueInstance Initializer::createInstance(const GlfwWrapper &window) {
    auto instanceLayerNames{Initializer::getRequestedLayers()};
    auto instanceLayerProperties = vk::enumerateInstanceLayerProperties();
    if (!requestedLayersAreAvailable(instanceLayerNames, instanceLayerProperties)) {
        throw std::runtime_error("Not all requested validation layers are not available.");
    }
    vk::ApplicationInfo appInfo("Project Name", VK_MAKE_VERSION(1, 0, 0), "Rendervault", VK_MAKE_VERSION(1, 0, 0),
                                VK_API_VERSION_1_2);
    auto extensionNames = window.getGlfwExtensionsVector();
    vk::InstanceCreateInfo createInfo(vk::InstanceCreateFlags(), &appInfo, instanceLayerNames, extensionNames);
    try {
        auto instance = vk::createInstanceUnique(createInfo);
        log.info("Created vk::UniqueInstance");
        printAvailableExtensions();
        return instance;
    } catch (vk::SystemError err) {
        throw std::runtime_error(Logger::format("Failed to create instance: {}", std::string(err.what())));
    }
}

void Initializer::printAvailableExtensions() {
    log.info("available extensions:");
    for (const auto &extension : vk::enumerateInstanceExtensionProperties()) {
        log.info("\t{}", extension.extensionName);
    }
}

std::vector<char const *> Initializer::getRequestedLayers() {
    std::vector<char const *> instanceLayerNames;
    instanceLayerNames.push_back("VK_LAYER_KHRONOS_validation");

    return instanceLayerNames;
}

bool Initializer::requestedLayersAreAvailable(std::vector<char const *> const &layers,
                                              std::vector<vk::LayerProperties> const &properties) {
    // return true if all layers are listed in the properties
    return std::all_of(layers.begin(), layers.end(), [&properties](char const *name) {
        return std::find_if(properties.begin(), properties.end(), [&name](vk::LayerProperties const &property) {
                   return strcmp(property.layerName, name) == 0;
               }) != properties.end();
    });
}