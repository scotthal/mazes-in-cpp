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

Cell Maze::cell_at(Coordinate c) { return maze_.at(linearize(c.x, c.y)); }
Cell Maze::cell_at(int x, int y) { return maze_.at(linearize(x, y)); }

void Maze::link(Coordinate c1, Coordinate c2) {
  int c1_index = linearize(c1.x, c1.y);
  int c2_index = linearize(c2.x, c2.y);

  if (*(maze_[c1_index].neighbors().east) == c2) {
    maze_[c1_index].links().east = c2;
    maze_[c2_index].links().west = c1;
  } else if (*(maze_[c1_index].neighbors().north) == c2) {
    maze_[c1_index].links().north = c2;
    maze_[c2_index].links().south = c1;
  } else if (*(maze_[c1_index].neighbors().south) == c2) {
    maze_[c1_index].links().south = c2;
    maze_[c2_index].links().north = c1;
  } else if (*(maze_[c1_index].neighbors().west) == c2) {
    maze_[c1_index].links().west = c2;
    maze_[c2_index].links().east = c1;
  }
}

} // namespace maze
