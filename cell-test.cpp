#include "gtest/gtest.h"

#include "cell.h"
#include "coordinate.h"

TEST(CellTest, Coordinate) {
  maze::Coordinate coordinate{3, 5};
  maze::Cell coordinate_cell = maze::Cell(coordinate);
  EXPECT_EQ(coordinate_cell.coordinate().x, coordinate.x);
  EXPECT_EQ(coordinate_cell.coordinate().y, coordinate.y);
  EXPECT_EQ(coordinate_cell.x(), coordinate.x);
  EXPECT_EQ(coordinate_cell.y(), coordinate.y);

  constexpr int x = 7;
  constexpr int y = 9;
  maze::Cell xy_cell = maze::Cell(x, y);
  EXPECT_EQ(xy_cell.coordinate().x, x);
  EXPECT_EQ(xy_cell.coordinate().y, y);
  EXPECT_EQ(xy_cell.x(), x);
  EXPECT_EQ(xy_cell.y(), y);
}
