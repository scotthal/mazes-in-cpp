#include <iostream>

#include "binary-tree.h"
#include "maze.h"
#include "maze-svg.h"

int main() {
  constexpr int width = 30;
  constexpr int height = 30;
  constexpr int cell_width = 20;
  constexpr int cell_height = 20;
  maze::Maze maze = maze::Maze(width, height);
  maze_algorithm::binary_tree(maze);
  maze_render::svg(maze, cell_width, cell_height, std::cout);
  return 0;
}
