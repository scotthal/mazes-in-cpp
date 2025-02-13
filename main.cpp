#include "maze.h"
#include "maze-svg.h"

int main() {
  constexpr int width = 6;
  constexpr int height = 9;
  maze::Maze maze = maze::Maze(width, height);
  maze_render::svg(maze);
  return 0;
}
