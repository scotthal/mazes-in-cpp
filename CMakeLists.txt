cmake_minimum_required(VERSION 3.31)

enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.16.0
  GIT_SHALLOW ON
)
FetchContent_MakeAvailable(googletest)

project(mazes-in-cpp VERSION 0.0.0 LANGUAGES CXX)

add_library(maze cell.cpp maze.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} maze)

add_executable(cell-test cell-test.cpp)
target_link_libraries(
  cell-test
  maze
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cell-test)
