#include <vector>

#include "cell.h"
#include "coordinate.h"
#include "maze.h"

namespace maze {

int Maze::linearize(int x, int y) { return (y * width_) + x; }

Maze::Maze(int width, int height) : width_{width}, height_{height} {
  maze_ = std::vector<Cell>{};
  for (int y = 0; y < height_; ++y) {
    for (int x = 0; x < width_; ++x) {
      maze::Cell cell = Cell(x, y);
      if (y < height - 1) {
        maze::Coordinate north{x, y + 1};
        cell.neighbors().north = north;
      }
      if (x < width - 1) {
        maze::Coordinate east{x + 1, y};
        cell.neighbors().east = east;
      }
      if (y > 0) {
        maze::Coordinate south{x, y - 1};
        cell.neighbors().south = south;
      }
      if (x > 0) {
        maze::Coordinate west{x - 1, y};
        cell.neighbors().west = west;
      }
      maze_.push_back(cell);
    }
  }
}

int Maze::width() { return width_; }

int Maze::height() { return height_; }

int Maze::size() { return maze_.size(); }

Cell Maze::cell_at(int x, int y) { return maze_.at(linearize(x, y)); }

} // namespace maze
