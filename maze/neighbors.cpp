#include <vector>

#include "coordinate.h"
#include "neighbors.h"

namespace maze {

Neighbors::Neighbors()
    : east{std::nullopt}, north{std::nullopt}, south{std::nullopt},
      west{std::nullopt} {}

std::vector<Coordinate> Neighbors::to_vector() {
  std::vector<Coordinate> neighbors = {};
  if (east) {
    neighbors.push_back(*east);
  }
  if (north) {
    neighbors.push_back(*north);
  }
  if (south) {
    neighbors.push_back(*south);
  }
  if (west) {
    neighbors.push_back(*west);
  }
  return neighbors;
}

} // namespace maze
