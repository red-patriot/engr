#include "pch.h"

#include <units/metric.h>
#include <units/us-customary.h>

using namespace engr::units;

TEST(TestUnitConversions, Identity) {
  engr::Time a = 1234.65 * s;
  double expected = 1234.65;

  auto actual = a.as(s);

  EXPECT_NEAR(expected, actual, 1e-10);
}

TEST(TestUnitConversions, MetersToFeet) { 
  engr::Length a = 0.9144 * m;
  double expected = 3;

  auto actual = a.as(ft);

  EXPECT_NEAR(expected, actual, 1e-10);
}

TEST(TestUnitConversions, PoundsToNewtons) {
  engr::Force a = 1 * lbf;
  double expected = 4.448'221'615'3;

  auto actual = a.as(N);

  EXPECT_NEAR(expected, actual, 1e-10);
}
