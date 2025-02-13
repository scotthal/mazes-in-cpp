#include "gtest/gtest.h"

#include "cell.h"
#include "coordinate.h"
#include "maze.h"

TEST(MazeTest, HappyWidthHeight) {
  constexpr int width = 3;
  constexpr int height = 5;
  maze::Maze maze = maze::Maze(width, height);
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
