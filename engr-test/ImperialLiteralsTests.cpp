#include "pch.h"

#include <units/us-customary.h>

using namespace eng::units;

TEST(TestLiteralsImperial, Second) {
  eng::SIUnit<eng::TimeT(1)> expected{23.5};

  auto actual = 23.5 * s;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, PoundMass) {
  eng::SIUnit<eng::MassT(1)> expected{0.45359237};

  auto actual = 1 * lbm;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Yard) {
  eng::SIUnit<eng::LengthT(1)> expected{0.9144};

  auto actual = 1 * yd;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Rankine) {
  eng::SIUnit<eng::TemperatureT(1)> expected{30};

  auto actual = 54 * R;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Ampere) {
  eng::SIUnit<eng::CurrentT(1)> expected{0.567};

  auto actual = 0.567 * A;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Mole) {
  eng::SIUnit<eng::AmountT(1)> expected{56.123};

  auto actual = 56.123 * mol;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Candela) {
  eng::SIUnit<eng::LuminosityT(1)> expected{4};

  auto actual = 4 * cd;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Velocity) {
  eng::SIUnit<eng::LengthT(1) + eng::TimeT(-1)> expected{3.6576};

  auto actual = 4 * yd / s;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsImperial, Force) {
  eng::SIUnit<eng::MassT(1) + eng::LengthT(1) - eng::TimeT(2)> expected{4.448'221'615'260'5};

  auto actual = 1 * lbm * ((10.724'682'852'143'48) * yd) * pow<-2>(s);

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}
