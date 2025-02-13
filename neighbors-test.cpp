#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

#include "coordinate.h"
#include "neighbors.h"

TEST(NeighborsTest, BasicFunctionality) {
  maze::Neighbors neighbors = maze::Neighbors();
  EXPECT_EQ(neighbors.to_vector().size(), 0);

  maze::Coordinate east{0, 2};
  maze::Coordinate north{1, 2};
  maze::Coordinate south{1, 0};
  maze::Coordinate west{0, 1};

  neighbors.east = east;
  std::vector<maze::Coordinate> coordinates = neighbors.to_vector();
  EXPECT_EQ(coordinates.size(), 1);
  auto found = std::find(coordinates.begin(), coordinates.end(), east);
  EXPECT_NE(found, coordinates.end());

  neighbors.north = north;
  coordinates = neighbors.to_vector();
  EXPECT_EQ(coordinates.size(), 2);
  found = std::find(coordinates.begin(), coordinates.end(), north);
  EXPECT_NE(found, coordinates.end());

  neighbors.south = south;
  coordinates = neighbors.to_vector();
  EXPECT_EQ(coordinates.size(), 3);
  found = std::find(coordinates.begin(), coordinates.end(), south);
  EXPECT_NE(found, coordinates.end());

  neighbors.west = west;
  coordinates = neighbors.to_vector();
  EXPECT_EQ(coordinates.size(), 4);
  found = std::find(coordinates.begin(), coordinates.end(), west);
  EXPECT_NE(found, coordinates.end());
}
