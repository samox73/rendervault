#include <rendervault/utils/logger.hpp>
#include <rendervault/core/render_engine.h>

int main() {
    logger log{};
    render_engine engine{};
    engine.init();
    engine.run();
    engine.cleanup();
    log.info("Please {}", "let this be fun");
    return 0;
}
