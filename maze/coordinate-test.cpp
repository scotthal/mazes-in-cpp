#include "gtest/gtest.h"

#include "coordinate.h"

TEST(CoordinateTest, Equals) {
  maze::Coordinate a{1, 2};
  maze::Coordinate b{3, 4};

  ASSERT_EQ(a, a);
  ASSERT_NE(a, b);
}
