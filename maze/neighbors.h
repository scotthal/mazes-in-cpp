#ifndef _NEIGHBORS_H_
#define _NEIGHBORS_H_

#include <optional>
#include <vector>

#include "coordinate.h"

namespace maze {

struct Neighbors {
  std::optional<Coordinate> east;
  std::optional<Coordinate> north;
  std::optional<Coordinate> south;
  std::optional<Coordinate> west;

  Neighbors();
  std::vector<Coordinate> to_vector();
};

} // namespace maze

#endif // _NEIGHBORS_H_
