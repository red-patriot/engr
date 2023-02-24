#include "pch.h"

#include <units/SIDimension.h>
#include <units/UnitTypes.h>

TEST(TestUnitTypes, Time) {
  eng::SIDimension expected = eng::TimeT(1);

  eng::Time actual{0};

  EXPECT_EQ(expected, actual.unit);
}

TEST(TestUnitTypes, Mass) {
  eng::SIDimension expected = eng::MassT(1);

  eng::Mass actual{0};

  EXPECT_EQ(expected, actual.unit);
}

TEST(TestUnitTypes, Length) {
  eng::SIDimension expected = eng::LengthT(1);

  eng::Length actual{0};

  EXPECT_EQ(expected, actual.unit);
}

TEST(TestUnitTypes, Temperature) {
  eng::SIDimension expected = eng::TemperatureT(1);

  eng::Temperature actual{0};

  EXPECT_EQ(expected, actual.unit);
}

TEST(TestUnitTypes, Current) {
  eng::SIDimension expected = eng::CurrentT(1);

  eng::Current actual{0};

  EXPECT_EQ(expected, actual.unit);
}

TEST(TestUnitTypes, Amount) {
  eng::SIDimension expected = eng::AmountT(1);

  eng::Amount actual{0};

  EXPECT_EQ(expected, actual.unit);
}

TEST(TestUnitTypes, Luminosity) {
  eng::SIDimension expected = eng::LuminosityT(1);

  eng::Luminosity actual{0};

  EXPECT_EQ(expected, actual.unit);
}
