#include <iostream>

#include "aldous-broder.h"
#include "maze.h"
#include "maze-svg.h"

int main() {
  constexpr int width = 30;
  constexpr int height = 30;
  constexpr int cell_width = 20;
  constexpr int cell_height = 20;
  maze::Maze maze = maze::Maze(width, height);
  maze_algorithm::aldous_broder(maze);
  maze_render::svg_distance(maze, cell_width, cell_height, std::cout);
  return 0;
}
