#include "log.hpp"

#include <iostream>

static std::string_view file_name_only(std::string_view path) {
    const auto pos = path.find_last_of("/\\");
    if (pos == std::string_view::npos) {
        return path;
    }
    return path.substr(pos + 1);
}

void log(std::string_view level,
         std::string_view message,
         const std::source_location& location) {
    std::clog << '[' << level << "] "
              << file_name_only(location.file_name()) << ':' << location.line()
              << " (" << location.function_name() << ") "
              << message << '\n';
}