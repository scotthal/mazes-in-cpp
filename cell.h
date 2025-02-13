#ifndef _CELL_H_
#define _CELL_H_

#include "coordinate.h"
#include "neighbors.h"

namespace maze {

class Cell {
private:
  const Coordinate coordinate_;
  Neighbors links_;
  Neighbors neighbors_;

public:
  Cell(Coordinate coordinate);
  Cell(int x, int y);

  Coordinate coordinate();
  Neighbors& links();
  Neighbors& neighbors();
  int x();
  int y();
};

} // namespace maze

#endif // _CELL_H_
