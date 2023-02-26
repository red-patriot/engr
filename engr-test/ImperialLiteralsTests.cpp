#include "pch.h"

#include <units/us-customary.h>

using namespace eng::units;

TEST(TestLiteralsImperial, Second) {
  eng::Time expected{23.5};

  auto actual = 23.5 * s;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, PoundMass) {
  eng::Mass expected{0.45359237};

  auto actual = 1 * lbm;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Yard) {
  eng::Length expected{0.9144};

  auto actual = 1 * yd;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Rankine) {
  eng::Temperature expected{30};

  auto actual = 54 * R;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Ampere) {
  eng::Current expected{0.567};

  auto actual = 0.567 * A;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Mole) {
  eng::Amount expected{56.123};

  auto actual = 56.123 * mol;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Candela) {
  eng::Luminosity expected{4};

  auto actual = 4 * cd;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Velocity) {
  eng::Velocity expected{3.6576};

  auto actual = 4 * yd / s;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Force) {
  eng::Force expected{4.448'221'615'260'5};

  auto actual = 1 * lbm * ((10.724'682'852'143'48) * yd) * pow<-2>(s);

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}
