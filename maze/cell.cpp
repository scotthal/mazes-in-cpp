#include <optional>
#include <vector>

#include "cell.h"
#include "coordinate.h"
#include "neighbors.h"

namespace maze {

Cell::Cell(Coordinate coordinate)
    : coordinate_{coordinate}, distances_{std::nullopt}, links_{},
      neighbors_{} {}

Cell::Cell(int x, int y)
    : coordinate_{x, y}, distances_{std::nullopt}, links_{}, neighbors_{} {}

Coordinate Cell::coordinate() { return coordinate_; }

Neighbors &Cell::links() { return links_; }
Neighbors &Cell::neighbors() { return neighbors_; }

int Cell::x() { return coordinate_.x; }

int Cell::y() { return coordinate_.y; }

  std::optional<std::vector<int>> Cell::distances() {
    return distances_;
  }

  void Cell::distances(std::vector<int> distances) {
    distances_ = distances;
  }

} // namespace maze
