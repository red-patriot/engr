#include "pch.h"

#include <units/Literals.h>

using namespace eng::units;

TEST(TestUnitLiterals, SecondLiteral) {
  eng::SIUnit<eng::TimeT(1)> expected{23.5};

  auto actual = 23.5 * s;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnitLiterals, KilogramLiteral) {
  eng::SIUnit<eng::MassT(1)> expected{-4};

  auto actual = -4 * kg;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnitLiterals, MeterLiteral) {
  eng::SIUnit<eng::LengthT(1)> expected{2};
  
  auto actual = 2 * m;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}
