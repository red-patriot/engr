#include "pch.h"

#include <units/SIDimension.h>
#include <units/UnitTypes.h>

#define UNIT_TYPE_TEST(Literal, equivalentUnit)   \
  TEST(TestUnitTypes, Literal) {                  \
    eng::SIDimension expected = (equivalentUnit); \
    eng::##Literal actual{0};                     \
    EXPECT_EQ(expected, actual.unit);             \
  }

UNIT_TYPE_TEST(Time, eng::TimeT(1))
UNIT_TYPE_TEST(Mass, eng::MassT(1))
UNIT_TYPE_TEST(Length, eng::LengthT(1))
UNIT_TYPE_TEST(Temperature, eng::TemperatureT(1))
UNIT_TYPE_TEST(Current, eng::CurrentT(1))
UNIT_TYPE_TEST(Amount, eng::AmountT(1))
UNIT_TYPE_TEST(Luminosity, eng::LuminosityT(1))

UNIT_TYPE_TEST(Frequency, eng::TimeT(-1))

UNIT_TYPE_TEST(Area, eng::LengthT(2))
UNIT_TYPE_TEST(Volume, eng::LengthT(3))
UNIT_TYPE_TEST(SecondMomentOfArea, eng::LengthT(4))

UNIT_TYPE_TEST(Velocity, eng::LengthT(1) - eng::TimeT(1))
UNIT_TYPE_TEST(Acceleration, eng::LengthT(1) - eng::TimeT(2))
UNIT_TYPE_TEST(Jerk, eng::LengthT(1) - eng::TimeT(3))

UNIT_TYPE_TEST(Momentum, eng::MassT(1) + eng::LengthT(1) - eng::TimeT(1))
UNIT_TYPE_TEST(Force, eng::MassT(1) + eng::LengthT(1) - eng::TimeT(2))
UNIT_TYPE_TEST(Energy, eng::MassT(1) + eng::LengthT(2) - eng::TimeT(2))
UNIT_TYPE_TEST(Power, eng::MassT(1) + eng::LengthT(2) - eng::TimeT(3))

UNIT_TYPE_TEST(Charge, eng::CurrentT(1) + eng::TimeT(1))
UNIT_TYPE_TEST(Voltage, eng::MassT(1) + eng::LengthT(2) - eng::TimeT(3) - eng::CurrentT(1))
UNIT_TYPE_TEST(Resistance, eng::MassT(1) + eng::LengthT(2) - eng::TimeT(3) - eng::CurrentT(2))
UNIT_TYPE_TEST(Capacitance, eng::CurrentT(2) + eng::TimeT(4) - eng::MassT(1) - eng::LengthT(2))
UNIT_TYPE_TEST(Inductance, eng::MassT(1) + eng::LengthT(2) - eng::TimeT(2) - eng::CurrentT(2))

