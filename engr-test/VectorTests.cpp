#include "pch.h"

#include <units/metric.h>
#include <units/Vector.h>

using namespace engr::units;

TEST(TestSIUnit, Simple2DVector) {
  engr::Vector<engr::Length::unit, 2> expected = {3.4 * m, 5.6 * m};

  EXPECT_DOUBLE_EQ(3.4, expected.x().as(m));
  EXPECT_DOUBLE_EQ(5.6, expected.y().as(m));
}

TEST(TestSIUnit, Simple3DVector) {
  engr::Vector<engr::Force::unit, 3> expected = {12 * engr::kilo(N), 500 * N, -4.67 * engr::kilo(N)};

  EXPECT_DOUBLE_EQ(12'000, expected.x().as(N));
  EXPECT_DOUBLE_EQ(500, expected.y().as(N));
  EXPECT_DOUBLE_EQ(-4'670, expected.z().as(N));
}

TEST(TestSIUnit, Simple6DVector) {
  Eigen::Vector<double, 6> expected = Eigen::Vector<double, 6>(5,
                                                               6,
                                                               7,
                                                               -8,
                                                               1.23,
                                                               0.57);
  engr::Vector<engr::Energy::unit, 6> actual = {5 * J,
                                                6 * J,
                                                7 * J,
                                                -8 * J,
                                                1.23 * J,
                                                0.57 * J};
  for (int i = 0; i < expected.size(); ++i) {
    EXPECT_DOUBLE_EQ(expected[i], actual[i].as(J)) << i;
  }
}
