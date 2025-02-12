#include <iostream>

#include "cell.h"
#include "maze.h"

int main() {
  constexpr int width = 6;
  constexpr int height = 9;
  Maze maze = Maze(width, height);
  std::cout << "Maze size: " << maze.size() << "\n";
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      Cell cell = maze.cell_at(x, y);
      std::cout << "(" << cell.x() << ", " << cell.y() << ")\n";
    }
  }
  return 0;
}
