#include <iostream>

#include "maze.h"
#include "maze-svg.h"

int main() {
  constexpr int width = 6;
  constexpr int height = 9;
  constexpr int cell_width = 50;
  constexpr int cell_height = 50;
  maze::Maze maze = maze::Maze(width, height);
  maze_render::svg(maze, cell_width, cell_height, std::cout);
  return 0;
}
