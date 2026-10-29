cmake_minimum_required(VERSION 3.10)
project(LearnCPP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(monster_lib 
    src/scene/scene.cpp 
    src/scene/scene.hpp 
    src/monster/monster.cpp 
    src/monster/monster.hpp
    src/monster/alien/alien.cpp 
    src/monster/alien/alien.hpp
    src/monster/energy/energy.cpp 
    src/monster/energy/energy.hpp
)

target_include_directories(monster_lib PUBLIC src/monster)

add_executable(main_app src/main.cpp)

target_link_libraries(main_app PRIVATE monster_lib)