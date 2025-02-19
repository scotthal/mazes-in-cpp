#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <optional>
#include <vector>

#include "coordinate.h"
#include "maze.h"
#include "recursive-backtracker.h"

namespace maze_algorithm {

std::optional<maze::Coordinate> unvisited_neighbor(maze::Maze &maze,
                                                   maze::Coordinate c,
                                                   std::vector<bool> &visited) {
  auto neighbors = maze.cell_at(c).neighbors().to_vector();
  std::vector<maze::Coordinate> unvisited_neighbors{};
  std::copy_if(neighbors.begin(), neighbors.end(),
               std::back_inserter(unvisited_neighbors),
               [&maze, &visited](maze::Coordinate neighbor) {
                 return !visited[maze.linearize(neighbor)];
               });
  if (unvisited_neighbors.size() == 0) {
    return std::nullopt;
  } else {
    auto result = unvisited_neighbors[std::rand() % unvisited_neighbors.size()];
    return result;
  }
}

std::optional<maze::Coordinate> backtrack(maze::Maze &maze,
                                          std::vector<maze::Coordinate> &path,
                                          std::vector<bool> &visited) {
  while (!path.empty()) {
    auto next_coordinate = path.back();
    path.pop_back();
    if (unvisited_neighbor(maze, next_coordinate, visited)) {
      return next_coordinate;
    }
  }
  return std::nullopt;
}

void recursive_backtracker(maze::Maze &maze) {
  std::srand(std::time({}));
  auto visited = std::vector<bool>(maze.size(), false);
  std::vector<maze::Coordinate> path{};
  auto current_coordinate = maze::Coordinate(0, 0);
  visited[maze.linearize(current_coordinate)] = true;
  path.push_back(current_coordinate);

  while (!path.empty()) {
    auto next_coordinate =
        unvisited_neighbor(maze, current_coordinate, visited);
    if (next_coordinate) {
      maze.link(current_coordinate, *next_coordinate);
      current_coordinate = *next_coordinate;
      visited[maze.linearize(current_coordinate)] = true;
      path.push_back(current_coordinate);
    } else {
      auto next_coordinate = backtrack(maze, path, visited);
      if (next_coordinate) {
        auto unvisited_neighbor_coordinate =
            unvisited_neighbor(maze, *next_coordinate, visited);
        maze.link(*next_coordinate, *unvisited_neighbor_coordinate);
        current_coordinate = *unvisited_neighbor_coordinate;
        visited[maze.linearize(current_coordinate)] = true;
        path.push_back(current_coordinate);
      } else {
        break;
      };
    }
  }
}

} // namespace maze_algorithm
