cmake_minimum_required(VERSION 3.10)
project(LearnCPP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE MONSTER_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_library(monster_lib ${MONSTER_SOURCES})

target_include_directories(monster_lib PUBLIC src/monster)

add_executable(main_app src/main.cpp)

target_link_libraries(main_app PRIVATE monster_lib)