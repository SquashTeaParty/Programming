#pragma once

#include <string_view>
#include <source_location>

void log(std::string_view level,
         std::string_view message,
         const std::source_location& location = std::source_location::current());