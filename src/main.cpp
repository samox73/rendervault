#include <rendervault/core/RenderCore.hpp>
#include <rendervault/utils/Logger.hpp>

int main() {
    RenderCore engine{};
    engine.init();
    engine.run();
    engine.cleanup();
    return 0;
}
