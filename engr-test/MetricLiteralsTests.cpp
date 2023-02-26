#include "pch.h"

#include <units/metric.h>

using namespace eng::units;
using eng::invert;
using eng::pow;

#define METRIC_LITERALS_TEST(name, expectedType, expectedValue, actualValue) \
  TEST(TestLiteralsMetric, name) {                                           \
    expectedType expected{expectedValue};                                    \
    auto actual = actualValue;                                               \
    EXPECT_EQ(expected.unit, actual.unit);                                   \
    EXPECT_NEAR(expected.base(), actual.base(), 1e-10);                      \
  }

// Base unit literals tests
METRIC_LITERALS_TEST(Second, eng::SIUnit<eng::TimeT(1)>, 23.5, 23.5 * s)
METRIC_LITERALS_TEST(Kilogram, eng::SIUnit<eng::MassT(1)>, -4, -4 * kg)
METRIC_LITERALS_TEST(Meter, eng::SIUnit<eng::LengthT(1)>, 2, 2 * m)
METRIC_LITERALS_TEST(Kelvin, eng::SIUnit<eng::TemperatureT(1)>, 810.7, 810.7 * K)
METRIC_LITERALS_TEST(Ampere, eng::SIUnit<eng::CurrentT(1)>, 0.567, 0.567 * A)
METRIC_LITERALS_TEST(Mole, eng::SIUnit<eng::AmountT(1)>, 56.123, 56.123 * mol)
METRIC_LITERALS_TEST(Candela, eng::SIUnit<eng::LuminosityT(1)>, 4, 4 * cd)

// Arithmetic combinations tests
METRIC_LITERALS_TEST(Frequency, eng::SIUnit<eng::TimeT(-1)>, 7.7, 7.7 / s)
METRIC_LITERALS_TEST(Velocity, eng::SIUnit<eng::LengthT(1) - eng::TimeT(1)>, 4, 4 * m / s)
METRIC_LITERALS_TEST(Powers,
                     eng::SIUnit<eng::MassT(1) + eng::LengthT(2) - eng::TimeT(3) - eng::CurrentT(2)>,
                     300,
                     300 * kg * pow<2>(m) * pow<-3>(s) * pow<-2>(A))
METRIC_LITERALS_TEST(Roots,
                     eng::SIUnit<eng::MassT({1, 2}) + eng::TimeT({-3, 5}) - eng::LuminosityT({1, 5})>,
                     12.6,
                     12.6 * (rt<2>(kg) * pow<-3, 5>(s) * rt<-5>(cd)))
METRIC_LITERALS_TEST(Exponentiation,
                     eng::SIUnit<eng::MassT({1, 3}) + eng::TimeT({3, 2}) + eng::CurrentT({-1, 2})>,
                     4.8,
                     (pow<1, 3>(27 * kg) * pow<3, 2>(4 * s) / rt<2>(25 * A)))

// Secondary units tests
METRIC_LITERALS_TEST(Hertz, eng::Frequency, 3.5, 3.5 * Hz)

METRIC_LITERALS_TEST(MetersSquared, eng::Area, 6.78, 6.78 * m2)
METRIC_LITERALS_TEST(MetersCubed, eng::Volume, -9.043, -9.043 * m3)
METRIC_LITERALS_TEST(MetersFourth, eng::SecondMomentOfArea, 6.7e8, 6.7e8 * m4)

METRIC_LITERALS_TEST(MetersPerSecond, eng::Velocity, 6.67, 6.67 * m / s)
METRIC_LITERALS_TEST(MetersPerSecondSquared, eng::Acceleration, 0.4, 0.4 * m / s2)
METRIC_LITERALS_TEST(MetersPerSecondCubed, eng::Jerk, 1.1, 1.1 * m / s3)

METRIC_LITERALS_TEST(Newtons, eng::Force, -5, -5 * N)
METRIC_LITERALS_TEST(Joules, eng::Energy, 8.8, 8.8 * J)
METRIC_LITERALS_TEST(Watts, eng::Power, 0.456, 0.456 * W)

METRIC_LITERALS_TEST(Coulombs, eng::Charge, 12, 12 * C)
METRIC_LITERALS_TEST(Volts, eng::Voltage, -5.5, -5.5 * V)
METRIC_LITERALS_TEST(Ohms, eng::Resistance, 6.5e2, 6.5e2 * Ohm)
METRIC_LITERALS_TEST(Farads, eng::Capacitance, 43e-5, 43e-5 * F)
METRIC_LITERALS_TEST(Henries, eng::Inductance, 0.34e-2, 0.34e-2 * H)

METRIC_LITERALS_TEST(Pascals, eng::Pressure, 5.6e4, 5.6e4 * Pa)
