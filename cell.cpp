#include "cell.h"
#include "coordinate.h"
#include "neighbors.h"

namespace maze {

Cell::Cell(Coordinate coordinate) : coordinate_{coordinate} {}
Cell::Cell(int x, int y) : coordinate_{x, y} {}

Coordinate Cell::coordinate() { return coordinate_; }

Neighbors &Cell::links() { return links_; }
Neighbors &Cell::neighbors() { return neighbors_; }

int Cell::x() { return coordinate_.x; }

int Cell::y() { return coordinate_.y; }

} // namespace maze
