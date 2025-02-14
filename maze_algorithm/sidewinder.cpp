#include <cstdlib>
#include <ctime>
#include <vector>

#include "cell.h"
#include "coordinate.h"
#include "maze.h"
#include "sidewinder.h"

namespace maze_algorithm {

static void close_run(maze::Maze &maze, std::vector<maze::Coordinate> &run) {
  if (!run.empty()) {
    int chosen_coordinate = std::rand() % run.size();
    int x = run[chosen_coordinate].x;
    int y = run[chosen_coordinate].y;
    maze::Cell cell = maze.cell_at(x, y);
    if (cell.neighbors().north) {
      maze.link(cell.coordinate(), *(cell.neighbors().north));
    }
    run.clear();
  }
}

void sidewinder(maze::Maze &maze) {
  std::srand(std::time({}));
  const int width = maze.width();
  const int height = maze.height();
  std::vector<maze::Coordinate> run{};

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      auto cell = maze.cell_at(x, y);
      run.push_back(cell.coordinate());
      if (cell.neighbors().north && cell.neighbors().east) {
        int flip = std::rand();
        if (flip > (RAND_MAX >> 1)) {
          maze.link(cell.coordinate(), *(cell.neighbors().east));
        } else {
          close_run(maze, run);
        }
      } else if (cell.neighbors().north) {
        close_run(maze, run);
      } else if (cell.neighbors().east) {
        maze.link(cell.coordinate(), *(cell.neighbors().east));
      }
    }
  }
}

} // namespace maze_algorithm
