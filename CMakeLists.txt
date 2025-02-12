cmake_minimum_required(VERSION 3.31)

enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mazes-in-cpp VERSION 0.0.0 LANGUAGES CXX)

add_library(maze cell.cpp maze.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} maze)
