#include "pch.h"

#include <units/SIDimension.h>
#include <units/UnitTypes.h>

#define UNIT_TYPE_TEST(Literal, equivalentUnit) \
  TEST(TestUnitTypes, Literal) {                   \
    eng::SIDimension expected = (equivalentUnit);  \
    eng::##Literal  actual{0};                        \
    EXPECT_EQ(expected, actual.unit);           \
  }

UNIT_TYPE_TEST(Time, eng::TimeT(1))
UNIT_TYPE_TEST(Mass, eng::MassT(1))
UNIT_TYPE_TEST(Length, eng::LengthT(1))
UNIT_TYPE_TEST(Temperature, eng::TemperatureT(1))
UNIT_TYPE_TEST(Current, eng::CurrentT(1))
UNIT_TYPE_TEST(Amount, eng::AmountT(1))
UNIT_TYPE_TEST(Luminosity, eng::LuminosityT(1))
