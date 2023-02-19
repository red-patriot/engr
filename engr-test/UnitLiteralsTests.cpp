#include "pch.h"

#include <units/metric.h>

using namespace eng::units::metric;

TEST(TestLiteralsMetric, Second) {
  eng::SIUnit<eng::TimeT(1)> expected{23.5};

  auto actual = 23.5 * s;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsMetric, Kilogram) {
  eng::SIUnit<eng::MassT(1)> expected{-4};

  auto actual = -4 * kg;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsMetric, Meter) {
  eng::SIUnit<eng::LengthT(1)> expected{2};

  auto actual = 2 * m;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsMetric, Kelvin) {
  eng::SIUnit<eng::TemperatureT(1)> expected{810.7};

  auto actual = 810.7 * K;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsMetric, Ampere) {
  eng::SIUnit<eng::CurrentT(1)> expected{0.567};

  auto actual = 0.567 * A;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsMetric, Mole) {
  eng::SIUnit<eng::AmountT(1)> expected{56.123};

  auto actual = 56.123 * mol;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsMetric, Candela) {
  eng::SIUnit<eng::LuminosityT(1)> expected{4};

  auto actual = 4 * cd;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsMetric, Frequency) {
  eng::SIUnit<eng::TimeT(-1)> expected{7.7};

  auto actual = 7.7 / s;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestLiteralsMetric, Velocity) {
  eng::SIUnit<eng::LengthT(1) + eng::TimeT(-1)> expected{4};

  auto actual = 4 * m / s;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

