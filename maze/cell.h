#ifndef _CELL_H_
#define _CELL_H_

#include <optional>
#include <vector>

#include "coordinate.h"
#include "neighbors.h"

namespace maze {

class Cell {
private:
  const Coordinate coordinate_;
  Neighbors links_;
  Neighbors neighbors_;
  std::optional<std::vector<int>> distances_;

public:
  Cell(Coordinate coordinate);
  Cell(int x, int y);

  Coordinate coordinate();
  Neighbors &links();
  Neighbors &neighbors();
  int x();
  int y();

  std::optional<std::vector<int>> distances();
  void distances(std::vector<int> distances);
};

} // namespace maze

#endif // _CELL_H_
