#include <iostream>

#include "maze-svg.h"
#include "maze.h"

namespace maze_render {

void svg(maze::Maze &maze) {
  std::cout << "Maze size: " << maze.size() << "\n";
  for (int y = 0; y < maze.height(); ++y) {
    for (int x = 0; x < maze.width(); ++x) {
      maze::Cell cell = maze.cell_at(x, y);
      std::cout << "(" << cell.x() << ", " << cell.y() << ")\n";
    }
  }
}
} // namespace maze_render
