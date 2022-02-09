#include <rendervault/core/render_engine.hpp>

void render_engine::init() {
    window_.init(window_extent_.width, window_extent_.height);

    auto appInfo{
        vk::ApplicationInfo("Project Name", VK_MAKE_VERSION(1, 0, 0), "Rendervault", VK_MAKE_VERSION(1, 0, 0),
                            VK_API_VERSION_1_2),
    };
    auto createInfo{vk::InstanceCreateInfo(vk::InstanceCreateFlags(), &appInfo, 0, nullptr,
                                           window_.get_glfw_extension_count(), window_.get_glfw_extensions())};
    try {
        instance_ = vk::createInstanceUnique(createInfo, nullptr);
        log.info("Created vk::UniqueInstance");
    } catch (vk::SystemError err) {
        throw std::runtime_error(logger::format("Failed to create instance: {}", err.what()));
    }

    initialized_ = true;
}

void render_engine::cleanup() {
    if (initialized_) {
        window_.destroy();
    }
}

void render_engine::draw() {}

void render_engine::run() {
    while (!window_.should_close()) {
        glfwPollEvents();
        draw();
    }
}
