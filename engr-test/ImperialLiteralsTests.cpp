#include "pch.h"

#include <units/us-customary.h>

using namespace eng::units;

#define IMPERIAL_LITERALS_TEST(name, expectedType, expectedValue, actualValue) \
  TEST(TestLiteralsImperial, name) {                                         \
    expectedType expected{expectedValue};                                      \
    auto actual = actualValue;                                                 \
    EXPECT_EQ(expected.unit, actual.unit);                                     \
    EXPECT_NEAR(expected.base(), actual.base(), 1e-10);                        \
  }

// Base unit literals tests
IMPERIAL_LITERALS_TEST(Second, eng::Time, 23.5, 23.5 * s)
IMPERIAL_LITERALS_TEST(PoundMass, eng::Mass, 0.45359237, 1 * lbm)
IMPERIAL_LITERALS_TEST(Yard, eng::Length, 0.9144, 1 * yd)
IMPERIAL_LITERALS_TEST(Rankine, eng::Temperature, 30, 54 * R)
IMPERIAL_LITERALS_TEST(Ampere, eng::Current, 0.567, 0.567 * A)
IMPERIAL_LITERALS_TEST(Mole, eng::Amount, 56.123, 56.123 * mol)
IMPERIAL_LITERALS_TEST(Candela, eng::Luminosity, 4, 4 * cd)

// Arithmetic combinations tests
IMPERIAL_LITERALS_TEST(Velocity, eng::Velocity, 3.6576, 4 * yd / s)
IMPERIAL_LITERALS_TEST(Powers, eng::Force, 4.448'221'615'260'5,
                       1 * lbm * ((10.724'682'852'143'48) * yd) * pow<-2>(s))

// Secondary units tests
IMPERIAL_LITERALS_TEST(Inches, eng::Length, 0.0254, 1 * in)
IMPERIAL_LITERALS_TEST(Feet, eng::Length, 0.3048, 1 * ft)

IMPERIAL_LITERALS_TEST(PoundForce, eng::Force, 4.448'221'615'3, 1 * lbf)
