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
  Cell cell_at(int linear_index);

  void link(Coordinate c1, Coordinate c2);

  void calculate_distances(Coordinate root);
  void calculate_distances(int root_x, int root_y);

  std::vector<Coordinate> path(Coordinate c1, Coordinate c2);
  std::vector<Coordinate> path(int x1, int y1, int x2, int y2);
};

} // namespace maze

#endif // _MAZE_H_
