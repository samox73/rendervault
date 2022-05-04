#pragma once

#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <utility>

#include "converters.hpp"

class Logger {
    std::ostream &os_{std::cout};
    std::function<std::string()> timestamp_ = default_timestamp;
    std::string prefix_{};

    enum class level : u_int16_t { ERROR = 0, WARN = 1, INFO = 2, DEBUG = 3 };
    const std::array<std::string, 4> level_names{"ERROR", " WARN", " INFO", "DEBUG"};

    static std::string default_timestamp() {
        std::string result;
        auto time{std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};
        result = std::ctime(&time);
        return result.substr(0, result.size() - 1);
    }

    // do not add [[nodiscard]]
    Logger newline(int i = 1) const;

    template<typename... T>
    void log(const level &lvl, std::string_view message, T... args) const {
        std::string formatted_message{};
        if constexpr (sizeof...(args) > 0) {
            formatted_message = format(message, args...);
        } else {
            formatted_message = message;
        }

        os_ << "[" << timestamp_() << "] "
            << "[" << level_names[static_cast<u_int16_t>(lvl)] << "] " << (!prefix_.empty() ? "[" + prefix_ + "] " : "")
            << formatted_message << '\n';
        os_.flush();
    }

public:
    explicit Logger() = default;

    explicit Logger(std::ostream &os) : os_{os} {}

    explicit Logger(std::string prefix) : prefix_{std::move(prefix)} {}

    explicit Logger(std::ostream &os, std::function<std::string()> fn) : os_{os}, timestamp_{std::move(fn)} {}

    template<typename T, typename... S>
    static std::string format(std::string_view message, const T &next, const S &...remaining) {
        auto index = message.find("{}");
        std::string formatted_message{message.substr(0, index)};
        if constexpr (std::is_convertible_v<T, std::string>) {
            formatted_message.append(std::string(next));
        } else {
            formatted_message.append(converters::resolve_to_string(next));
        }
        formatted_message.append(message.substr(index + 2, message.size()));
        if constexpr (sizeof...(remaining) > 0) {
            return format(formatted_message, remaining...);
        } else {
            return formatted_message;
        }
    }

    template<typename... T>
    void debug(std::string_view message, T... args) const {
#if LOG_LEVEL > 2
        log(level::DEBUG, message, args...);
#endif
    }

    template<typename... T>
    void info(std::string_view message, T... args) const {
#if LOG_LEVEL > 1
        log(level::INFO, message, args...);
#endif
    }

    template<typename... T>
    void warn(std::string_view message, T... args) const {
#if LOG_LEVEL > 0
        log(level::WARN, message, args...);
#endif
    }

    template<typename... T>
    void error(std::string message, T... args) const {
        log(level::ERROR, message, args...);
    }
};
