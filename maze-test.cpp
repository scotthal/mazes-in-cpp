#include "gtest/gtest.h"

#include "cell.h"
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
    }
  }
}
