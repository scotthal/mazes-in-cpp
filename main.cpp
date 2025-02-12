#include <iostream>
#include <vector>

struct Coordinate {
  int x;
  int y;
};

class Cell {
  private:
    const Coordinate coordinate_;
  public:
    Cell(Coordinate coordinate) : coordinate_{coordinate} {}
    Cell(int x, int y) : coordinate_{x, y} {}

    Coordinate coordinate() { return coordinate_; }
    int x() { return coordinate_.x; }
    int y() { return coordinate_.y; }
};

class Maze {
  private:
    const int width_;
    const int height_;
    std::vector<Cell> maze_;

    int linearize(int x, int y) { return (y * width_) + x; }

  public:
    Maze(int width, int height) : width_{width}, height_{height} {
      maze_ = std::vector<Cell>{};
      for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
          maze_.push_back(Cell(x, y));
        }
      }
    }

    int width() { return width_; }
    int height() { return height_; }
    int size() { return maze_.size(); }

    Cell cell_at(int x, int y) { return maze_.at(linearize(x, y)); }
};

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
