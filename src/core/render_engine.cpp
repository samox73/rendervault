#include "../../include/rendervault/core/render_engine.h"

void render_engine::init() {
    window_.init(window_extent_.width, window_extent_.height);
    initialized_ = true;
}

void render_engine::cleanup() {
    if (initialized_) {
        window_.destroy();
    }
}

void render_engine::draw() {

}

void render_engine::run() {
    while (!window_.should_close()) {
        glfwPollEvents();
        draw();
    }
}
