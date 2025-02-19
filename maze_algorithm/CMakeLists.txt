add_library(maze_algorithm) 
target_sources(maze_algorithm
  PUBLIC
  aldous-broder.cpp
  binary-tree.cpp
  sidewinder.cpp
)
target_include_directories(maze_algorithm PUBLIC "${PROJECT_SOURCE_DIR}/maze")

