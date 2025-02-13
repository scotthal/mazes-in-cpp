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

add_library(maze cell.cpp coordinate.cpp maze.cpp neighbors.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} maze)

add_executable(cell-test cell-test.cpp)
target_link_libraries(
  cell-test
  maze
  GTest::gtest_main
)

add_executable(coordinate-test coordinate-test.cpp)
target_link_libraries(
  coordinate-test
  maze
  GTest::gtest_main
)

add_executable(maze-test maze-test.cpp)
target_link_libraries(
  maze-test
  maze
  GTest::gtest_main
)

add_executable(neighbors-test neighbors-test.cpp)
target_link_libraries(
  neighbors-test
  maze
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cell-test)
gtest_discover_tests(coordinate-test)
gtest_discover_tests(maze-test)
gtest_discover_tests(neighbors-test)
