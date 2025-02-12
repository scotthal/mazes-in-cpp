#ifndef _MAZE_H_
#define _MAZE_H_

#include <vector>

#include "cell.h"

class Maze {
  private:
    const int width_;
    const int height_;
    std::vector<Cell> maze_;

    int linearize(int x, int y);

  public:
    Maze(int width, int height);
      
    int width();
    int height(); 
    int size(); 

    Cell cell_at(int x, int y);
};

#endif // _MAZE_H_
