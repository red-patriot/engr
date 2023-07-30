#include "pch.h"

#include <units/metric.h>
#include <units/us-customary.h>

using namespace engr::units;

TEST(TestUnitConversions, Identity) {
  engr::Time a = 1234.65 * second;
  double expected = 1234.65;

  auto actual = a.as(second);

  EXPECT_NEAR(expected, actual, 1e-10);
}

TEST(TestUnitConversions, MetersToFeet) { 
  engr::Length a = 0.9144 * meter;
  double expected = 3;

  auto actual = a.as(foot);

  EXPECT_NEAR(expected, actual, 1e-10);
}

TEST(TestUnitConversions, PoundsToNewtons) {
  engr::Force a = 1 * pound_force;
  double expected = 4.448'221'615'3;

  auto actual = a.as(newton);

  EXPECT_NEAR(expected, actual, 1e-10);
}
