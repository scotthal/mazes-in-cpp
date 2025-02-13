add_library(maze cell.cpp coordinate.cpp maze.cpp neighbors.cpp)

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
