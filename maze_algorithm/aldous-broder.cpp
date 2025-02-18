#include <cstdlib>
#include <ctime>
#include <vector>

#include "aldous-broder.h"
#include "coordinate.h"
#include "maze.h"

namespace maze_algorithm {

void aldous_broder(maze::Maze &maze) {
  std::srand(std::time({}));
  const int maze_size = maze.size();
  auto visited = std::vector<bool>(maze.size(), false);
  auto current_coordinate = maze::Coordinate(0, 0);
  int visited_count = 0;

  visited[maze.linearize(current_coordinate)] = true;
  ++visited_count;

  while (visited_count < maze_size) {
    auto current_neighbors =
        maze.cell_at(current_coordinate).neighbors().to_vector();
    int neighbor_index = std::rand() % current_neighbors.size();
    auto neighbor_coordinate = current_neighbors[neighbor_index];
    if (!visited[maze.linearize(neighbor_coordinate)]) {
      visited[maze.linearize(neighbor_coordinate)] = true;
      ++visited_count;
      maze.link(current_coordinate, neighbor_coordinate);
    }
    current_coordinate = neighbor_coordinate;
  }
}

} // namespace maze_algorithm
