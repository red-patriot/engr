#include "pch.h"

#include <units/metric.h>

using namespace engr::units;
using engr::invert;
using engr::pow;

#define METRIC_LITERALS_TEST(name, expectedType, expectedValue, actualValue) \
  TEST(TestLiteralsMetric, name) {                                           \
    expectedType expected{expectedValue};                                    \
    auto actual = actualValue;                                               \
    EXPECT_EQ(expected.unit, actual.unit);                                   \
    EXPECT_NEAR(expected.base(), actual.base(), 1e-10);                      \
  }

// Base unit literals tests
METRIC_LITERALS_TEST(Second, engr::SIUnit<engr::TimeT(1)>, 23.5, 23.5 * second)
METRIC_LITERALS_TEST(Kilogram, engr::SIUnit<engr::MassT(1)>, -4, -4 * kilogram)
METRIC_LITERALS_TEST(Meter, engr::SIUnit<engr::LengthT(1)>, 2, 2 * meter)
METRIC_LITERALS_TEST(Kelvin, engr::SIUnit<engr::TemperatureT(1)>, 810.7, 810.7 * kelvin)
METRIC_LITERALS_TEST(Ampere, engr::SIUnit<engr::CurrentT(1)>, 0.567, 0.567 * ampere)
METRIC_LITERALS_TEST(Mole, engr::SIUnit<engr::AmountT(1)>, 56.123, 56.123 * mole)
METRIC_LITERALS_TEST(Candela, engr::SIUnit<engr::LuminosityT(1)>, 4, 4 * candela)

// Arithmetic combinations tests
METRIC_LITERALS_TEST(Frequency, engr::SIUnit<engr::TimeT(-1)>, 7.7, 7.7 / second)
METRIC_LITERALS_TEST(Velocity, engr::SIUnit<engr::LengthT(1) - engr::TimeT(1)>, 4, 4 * meter / second)
METRIC_LITERALS_TEST(Powers,
                     engr::SIUnit<engr::MassT(1) + engr::LengthT(2) - engr::TimeT(3) - engr::CurrentT(2)>,
                     300,
                     300 * kilogram * pow<2>(meter) * pow<-3>(second) * pow<-2>(ampere))
METRIC_LITERALS_TEST(Roots,
                     engr::SIUnit<engr::MassT({1, 2}) + engr::TimeT({-3, 5}) - engr::LuminosityT({1, 5})>,
                     12.6,
                     12.6 * (rt<2>(kilogram) * pow<-3, 5>(second) * rt<-5>(candela)))
METRIC_LITERALS_TEST(Exponentiation,
                     engr::SIUnit<engr::MassT({1, 3}) + engr::TimeT({3, 2}) + engr::CurrentT({-1, 2})>,
                     4.8,
                     (pow<1, 3>(27 * kilogram) * pow<3, 2>(4 * second) / rt<2>(25 * ampere)))

// Secondary units tests
METRIC_LITERALS_TEST(Hertz, engr::Frequency, 3.5, 3.5 * hertz)

METRIC_LITERALS_TEST(MetersSquared, engr::Area, 6.78, 6.78 * meter2)
METRIC_LITERALS_TEST(MetersCubed, engr::Volume, -9.043, -9.043 * meter3)
METRIC_LITERALS_TEST(MetersFourth, engr::SecondMomentOfArea, 6.7e8, 6.7e8 * meter4)

METRIC_LITERALS_TEST(MetersPerSecond, engr::Velocity, 6.67, 6.67 * meter / second)
METRIC_LITERALS_TEST(MetersPerSecondSquared, engr::Acceleration, 0.4, 0.4 * meter / second3)
METRIC_LITERALS_TEST(MetersPerSecondCubed, engr::Jerk, 1.1, 1.1 * meter / second2)

METRIC_LITERALS_TEST(Newtons, engr::Force, -5, -5 * newton)
METRIC_LITERALS_TEST(Joules, engr::Energy, 8.8, 8.8 * joule)
METRIC_LITERALS_TEST(Watts, engr::Power, 0.456, 0.456 * watt)

METRIC_LITERALS_TEST(Coulombs, engr::Charge, 12, 12 * coulomb)
METRIC_LITERALS_TEST(Volts, engr::Voltage, -5.5, -5.5 * volt)
METRIC_LITERALS_TEST(Ohms, engr::Resistance, 6.5e2, 6.5e2 * ohm)
METRIC_LITERALS_TEST(Farads, engr::Capacitance, 43e-5, 43e-5 * farad)
METRIC_LITERALS_TEST(Henries, engr::Inductance, 0.34e-2, 0.34e-2 * henry)

METRIC_LITERALS_TEST(Pascals, engr::Pressure, 5.6e4, 5.6e4 * pascals)

// Test Prefix functions
METRIC_LITERALS_TEST(PrefixNano, engr::Length, 12.45e-9, 12.45 * nano(meter));
METRIC_LITERALS_TEST(PrefixMicro, engr::Length, 12.45e-6, 12.45 * micro(meter));
METRIC_LITERALS_TEST(PrefixMilli, engr::Length, 12.45e-3, 12.45 * milli(meter));
METRIC_LITERALS_TEST(PrefixKilo, engr::Length, 12.45e3, 12.45 * kilo(meter));
METRIC_LITERALS_TEST(PrefixMega, engr::Length, 12.45e6, 12.45 * mega(meter));
METRIC_LITERALS_TEST(PrefixGiga, engr::Length, 12.45e9, 12.45 * giga(meter));
