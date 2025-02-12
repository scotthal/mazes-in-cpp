#ifndef _CELL_H_
#define _CELL_H_

#include "coordinate.h"

namespace maze {

class Cell {
private:
  const Coordinate coordinate_;

public:
  Cell(Coordinate coordinate);
  Cell(int x, int y);

  Coordinate coordinate();
  int x();
  int y();
};

} // namespace maze

#endif // _CELL_H_
