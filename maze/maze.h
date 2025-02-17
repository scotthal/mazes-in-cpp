#ifndef _MAZE_H_
#define _MAZE_H_

#include <vector>

#include "cell.h"
#include "coordinate.h"

namespace maze {

class Maze {
private:
  const int width_;
  const int height_;
  std::vector<Cell> maze_;

  int linearize(Coordinate c);
  int linearize(int x, int y);

public:
  Maze(int width, int height);

  int width();
  int height();
  int size();

  Cell cell_at(Coordinate c);
  Cell cell_at(int x, int y);

  void link(Coordinate c1, Coordinate c2);

  void calculate_distances(Coordinate root);
  void calculate_distances(int root_x, int root_y);
};

} // namespace maze

#endif // _MAZE_H_
