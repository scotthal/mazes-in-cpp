#include "cell.h"
#include "coordinate.h"

Cell::Cell(Coordinate coordinate) : coordinate_{coordinate} {}
Cell::Cell(int x, int y) : coordinate_{x, y} {}

Coordinate Cell::coordinate() {
  return coordinate_;
}

int Cell::x() {
  return coordinate_.x;
}

int Cell::y() {
  return coordinate_.y;
}

