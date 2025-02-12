#include <vector>

#include "cell.h"
#include "maze.h"

namespace maze {

int Maze::linearize(int x, int y) { return (y * width_) + x; }

Maze::Maze(int width, int height) : width_{width}, height_{height} {
  maze_ = std::vector<Cell>{};
  for (int y = 0; y < height_; ++y) {
    for (int x = 0; x < width_; ++x) {
      maze_.push_back(Cell(x, y));
    }
  }
}

int Maze::width() { return width_; }

int Maze::height() { return height_; }

int Maze::size() { return maze_.size(); }

Cell Maze::cell_at(int x, int y) { return maze_.at(linearize(x, y)); }

} // namespace maze
