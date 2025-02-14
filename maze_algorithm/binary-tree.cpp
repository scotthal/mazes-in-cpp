#include <cstdlib>
#include <ctime>

#include "binary-tree.h"
#include "cell.h"
#include "maze.h"

namespace maze_algorithm {

void binary_tree(maze::Maze &maze) {
  std::srand(std::time({}));
  const int width = maze.width();
  const int height = maze.height();

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      auto cell = maze.cell_at(x, y);
      if (cell.neighbors().north && cell.neighbors().east) {
        int flip = std::rand();
        if (flip > (RAND_MAX >> 1)) {
          maze.link(cell.coordinate(), *(cell.neighbors().north));
        } else {
          maze.link(cell.coordinate(), *(cell.neighbors().east));
        }
      } else if (cell.neighbors().north) {
        maze.link(cell.coordinate(), *(cell.neighbors().north));
      } else if (cell.neighbors().east) {
        maze.link(cell.coordinate(), *(cell.neighbors().east));
      }
    }
  }
}

} // namespace maze_algorithm
