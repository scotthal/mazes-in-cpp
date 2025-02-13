#include "coordinate.h"

namespace maze {

bool Coordinate::operator==(const Coordinate& rhs) const {
  return (x == rhs.x) && (y == rhs.y);
}

} // namespace maze
