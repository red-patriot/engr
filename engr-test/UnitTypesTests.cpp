#include "pch.h"

#include <units/SIDimension.h>
#include <units/UnitTypes.h>

#define UNIT_TYPE_TEST(Literal, equivalentUnit)   \
  TEST(TestUnitTypes, Literal) {                  \
    engr::SIDimension expected = (equivalentUnit); \
    engr::##Literal actual{0};                     \
    EXPECT_EQ(expected, actual.unit);             \
  }

UNIT_TYPE_TEST(Time, engr::TimeT(1))
UNIT_TYPE_TEST(Mass, engr::MassT(1))
UNIT_TYPE_TEST(Length, engr::LengthT(1))
UNIT_TYPE_TEST(Temperature, engr::TemperatureT(1))
UNIT_TYPE_TEST(Current, engr::CurrentT(1))
UNIT_TYPE_TEST(Amount, engr::AmountT(1))
UNIT_TYPE_TEST(Luminosity, engr::LuminosityT(1))

UNIT_TYPE_TEST(Frequency, engr::TimeT(-1))

UNIT_TYPE_TEST(Area, engr::LengthT(2))
UNIT_TYPE_TEST(Volume, engr::LengthT(3))
UNIT_TYPE_TEST(SecondMomentOfArea, engr::LengthT(4))

UNIT_TYPE_TEST(Velocity, engr::LengthT(1) - engr::TimeT(1))
UNIT_TYPE_TEST(Acceleration, engr::LengthT(1) - engr::TimeT(2))
UNIT_TYPE_TEST(Jerk, engr::LengthT(1) - engr::TimeT(3))

UNIT_TYPE_TEST(Momentum, engr::MassT(1) + engr::LengthT(1) - engr::TimeT(1))
UNIT_TYPE_TEST(Force, engr::MassT(1) + engr::LengthT(1) - engr::TimeT(2))
UNIT_TYPE_TEST(Energy, engr::MassT(1) + engr::LengthT(2) - engr::TimeT(2))
UNIT_TYPE_TEST(Power, engr::MassT(1) + engr::LengthT(2) - engr::TimeT(3))

UNIT_TYPE_TEST(Charge, engr::CurrentT(1) + engr::TimeT(1))
UNIT_TYPE_TEST(Voltage, engr::MassT(1) + engr::LengthT(2) - engr::TimeT(3) - engr::CurrentT(1))
UNIT_TYPE_TEST(Resistance, engr::MassT(1) + engr::LengthT(2) - engr::TimeT(3) - engr::CurrentT(2))
UNIT_TYPE_TEST(Capacitance, engr::CurrentT(2) + engr::TimeT(4) - engr::MassT(1) - engr::LengthT(2))
UNIT_TYPE_TEST(Inductance, engr::MassT(1) + engr::LengthT(2) - engr::TimeT(2) - engr::CurrentT(2))

UNIT_TYPE_TEST(Density, engr::MassT(1) - engr::LengthT(3))
UNIT_TYPE_TEST(Pressure, engr::MassT(1) - engr::LengthT(1) - engr::TimeT(2))
UNIT_TYPE_TEST(MolarMass, engr::MassT(1) - engr::AmountT(1))
UNIT_TYPE_TEST(DynamicViscosity, engr::MassT(1) - engr::LengthT(1) - engr::TimeT(1))
UNIT_TYPE_TEST(KinematicViscosity, engr::LengthT(2) - engr::TimeT(1))
