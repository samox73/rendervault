#include "../../include/rendervault/utils/logger.hpp"

logger logger::newline(int i) const {
    for (int j = 0; j < i; ++j) {
        os_ << "\n";
    }
    return *this;
}
