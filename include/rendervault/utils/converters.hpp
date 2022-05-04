#pragma once

#include <type_traits>
#include <vulkan/vulkan.hpp>

namespace converters {

    template<typename T>
    std::string to_string(const T &array) {
        return std::string("");
    }

    template<typename T>
    auto resolve_to_string(const T &value) -> decltype(std::to_string(value)) {
        return std::to_string(value);
    }

    template<typename T>
    auto resolve_to_string(const T &value) -> decltype(converters::to_string(value)) {
        return converters::to_string(value);
    }
}  // namespace converters