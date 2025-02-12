#ifndef _CELL_H_
#define _CELL_H_

#include "coordinate.h"

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

#endif // _CELL_H_
