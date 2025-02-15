#include <algorithm>
#include <vector>

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

TEST(CellTest, Neighbors) {
  constexpr int x = 2;
  constexpr int y = 3;
  maze::Cell cell = maze::Cell(x, y);

  EXPECT_EQ(cell.neighbors().to_vector().size(), 0);

  maze::Coordinate north{x, y + 1};

  cell.neighbors().north = north;
  auto coordinates = cell.neighbors().to_vector();
  EXPECT_EQ(coordinates.size(), 1);
  auto found = std::find(coordinates.begin(), coordinates.end(), north);
  EXPECT_NE(found, coordinates.end());
}

TEST(CellTest, Links) {
  constexpr int x = 2;
  constexpr int y = 3;
  maze::Cell cell = maze::Cell(x, y);

  EXPECT_EQ(cell.links().to_vector().size(), 0);

  maze::Coordinate north{x, y + 1};

  cell.links().north = north;
  auto coordinates = cell.links().to_vector();
  EXPECT_EQ(coordinates.size(), 1);
  auto found = std::find(coordinates.begin(), coordinates.end(), north);
  EXPECT_NE(found, coordinates.end());
}

TEST(CellTest, Distances) {
  constexpr int x = 42;
  constexpr int y = 24;
  maze::Cell cell = maze::Cell(x, y);

  EXPECT_FALSE(cell.distances());

  cell.distances({1, 2, 3, 4});
  EXPECT_EQ(cell.distances().value().size(), 4);
  EXPECT_EQ(cell.distances().value().at(0), 1);
  EXPECT_EQ(cell.distances().value().at(1), 2);
  EXPECT_EQ(cell.distances().value().at(2), 3);
  EXPECT_EQ(cell.distances().value().at(3), 4);
}
