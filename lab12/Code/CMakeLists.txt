cmake_minimum_required(VERSION 3.10)
project(LearnCPP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE COMPLEX_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_library(complex_lib ${COMPLEX_SOURCES})

target_include_directories(complex_lib PUBLIC src/complex)

add_executable(main_app src/main.cpp)

target_link_libraries(main_app PRIVATE complex_lib)