#include "gtest/gtest.h"

#include "cell.h"
#include "coordinate.h"
#include "maze.h"

TEST(MazeTest, HappyWidthHeight) {
  constexpr int width = 3;
  constexpr int height = 5;
  auto maze = maze::Maze(width, height);
  EXPECT_EQ(maze.width(), width);
  EXPECT_EQ(maze.height(), height);
  EXPECT_EQ(maze.size(), width * height);

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      maze::Cell cell = maze.cell_at(x, y);
      EXPECT_EQ(cell.x(), x);
      EXPECT_EQ(cell.y(), y);

      if (y < height - 1) {
        maze::Coordinate north{x, y + 1};
        EXPECT_EQ(cell.neighbors().north, north);
      }
      if (x < width - 1) {
        maze::Coordinate east{x + 1, y};
        EXPECT_EQ(cell.neighbors().east, east);
      }
      if (y > 0) {
        maze::Coordinate south{x, y - 1};
        EXPECT_EQ(cell.neighbors().south, south);
      }
      if (x > 0) {
        maze::Coordinate west{x - 1, y};
        EXPECT_EQ(cell.neighbors().west, west);
      }
    }
  }
}

TEST(MazeTest, NeighborsCanLink) {
  constexpr int width = 5;
  constexpr int height = 6;
  constexpr int x1 = 1;
  constexpr int y1 = 1;
  constexpr int x2 = 2;
  constexpr int y2 = 1;
  maze::Coordinate c1{x1, y1};
  maze::Coordinate c2{x2, y2};
  auto maze = maze::Maze(width, height);

  EXPECT_FALSE(maze.cell_at(x1, y1).links().east);
  EXPECT_FALSE(maze.cell_at(x2, y2).links().west);

  maze.link(c1, c2);

  EXPECT_EQ(*(maze.cell_at(x1, y1).links().east), c2);
  EXPECT_EQ(*(maze.cell_at(x2, y2).links().west), c1);
}

TEST(MazeTest, CellAt) {
  constexpr int width = 5;
  constexpr int height = 6;
  constexpr int x = 4;
  constexpr int y = 2;
  maze::Coordinate c{x, y};
  auto maze = maze::Maze(width, height);

  auto cell1 = maze.cell_at(x, y);
  EXPECT_EQ(cell1.x(), x);
  EXPECT_EQ(cell1.y(), y);

  auto cell2 = maze.cell_at(c);
  EXPECT_EQ(cell2.x(), x);
  EXPECT_EQ(cell2.y(), y);
}

TEST(MazeTest, CalculateDistancesGetsBasicDistancesRight) {
  constexpr int width = 3;
  constexpr int height = 3;
  constexpr int root_x = 0;
  constexpr int root_y = 0;
  constexpr maze::Coordinate root{root_x, root_y};
  auto maze = maze::Maze(width, height);

  for (int y = 0; y < width; ++y) {
    for (int x = 0; x < width; ++x) {
      auto neighbors = maze.cell_at(x, y).neighbors().to_vector();
      for (auto neighbor : neighbors) {
        maze.link(maze::Coordinate(x, y), neighbor);
      }
    }
  }

  maze.calculate_distances(root);

  auto distances = maze.cell_at(root).distances().value();

  EXPECT_EQ(distances[0], 0);
  EXPECT_EQ(distances[1], 1);
  EXPECT_EQ(distances[2], 2);
  EXPECT_EQ(distances[3], 1);
  EXPECT_EQ(distances[4], 2);
  EXPECT_EQ(distances[5], 3);
  EXPECT_EQ(distances[6], 2);
  EXPECT_EQ(distances[7], 3);
  EXPECT_EQ(distances[8], 4);
}

TEST(MazeTest, PathCanFindASimplePath) {
  constexpr int width = 2;
  constexpr int height = 2;
  constexpr int origin_x = 0;
  constexpr int origin_y = 0;
  constexpr int destination_x = 0;
  constexpr int destination_y = 0;
  auto maze = maze::Maze(width, height);

  maze.link(maze::Coordinate(0, 0), maze::Coordinate(0, 1));
  maze.link(maze::Coordinate(0, 1), maze::Coordinate(1, 1));
  maze.link(maze::Coordinate(1, 1), maze::Coordinate(1, 0));

  auto path = maze.path(maze::Coordinate(0, 0), maze::Coordinate(1, 0));
  EXPECT_EQ(path.size(), 4);
  EXPECT_EQ(path[0], maze::Coordinate(1, 0));
  EXPECT_EQ(path[1], maze::Coordinate(1, 1));
  EXPECT_EQ(path[2], maze::Coordinate(0, 1));
  EXPECT_EQ(path[3], maze::Coordinate(0, 0));
}
