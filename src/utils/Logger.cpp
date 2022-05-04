#include "rendervault/utils/Logger.hpp"

Logger Logger::newline(int i) const {
    for (int j = 0; j < i; ++j) {
        os_ << "\n";
    }
    return *this;
}
