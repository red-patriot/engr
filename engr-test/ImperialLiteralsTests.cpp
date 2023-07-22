#include "pch.h"

#include <units/us-customary.h>

using namespace engr::units;

#define IMPERIAL_LITERALS_TEST(name, expectedType, expectedValue, actualValue) \
  TEST(TestLiteralsImperial, name) {                                         \
    expectedType expected{expectedValue};                                      \
    auto actual = actualValue;                                                 \
    EXPECT_EQ(expected.unit, actual.unit);                                     \
    EXPECT_NEAR(expected.base(), actual.base(), 1e-10);                        \
  }

// Base unit literals tests
IMPERIAL_LITERALS_TEST(Second, engr::Time, 23.5, 23.5 * second)
IMPERIAL_LITERALS_TEST(PoundMass, engr::Mass, 0.45359237, 1 * pound_mass)
IMPERIAL_LITERALS_TEST(Yard, engr::Length, 0.9144, 1 * yard)
IMPERIAL_LITERALS_TEST(Rankine, engr::Temperature, 30, 54 * rankine)
IMPERIAL_LITERALS_TEST(Ampere, engr::Current, 0.567, 0.567 * ampere)
IMPERIAL_LITERALS_TEST(Mole, engr::Amount, 56.123, 56.123 * mole)
IMPERIAL_LITERALS_TEST(Candela, engr::Luminosity, 4, 4 * candela)

// Arithmetic combinations tests
IMPERIAL_LITERALS_TEST(Velocity, engr::Velocity, 3.6576, 4 * yard / second)
IMPERIAL_LITERALS_TEST(Powers, engr::Force, 4.448'221'615'260'5,
                       1 * pound_mass * ((10.724'682'852'143'48) * yard) * pow<-2>(second))

// Secondary units tests
IMPERIAL_LITERALS_TEST(Inches, engr::Length, 0.0254, 1 * inch)
IMPERIAL_LITERALS_TEST(Feet, engr::Length, 0.3048, 1 * foot)

IMPERIAL_LITERALS_TEST(PoundForce, engr::Force, 4.448'221'615'3, 1 * pound_force)
