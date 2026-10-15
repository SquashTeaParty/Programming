cmake_minimum_required(VERSION 3.10)
project(LearnCPP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(figure_lib 
    src/figure/figure.cpp 
    src/figure/figure.hpp
)

target_include_directories(figure_lib PUBLIC src/figure)

add_executable(main_app src/main.cpp)

target_link_libraries(main_app PRIVATE figure_lib)