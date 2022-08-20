cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Game main.cpp Block.cpp Block.h Hero.cpp Hero.h)
target_link_libraries(Game sfml-graphics sfml-window sfml-system)
