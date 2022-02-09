#include <rendervault/core/render_engine.hpp>
#include <rendervault/utils/logger.hpp>

int main() {
    render_engine engine{};
    engine.init();
    engine.run();
    engine.cleanup();
    return 0;
}
