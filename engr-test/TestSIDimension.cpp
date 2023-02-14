#include "pch.h"

#include <type_traits>

#include <units/SIDimension.h>

TEST(TestSIDimension, CreateTimeT) {
  eng::SIDimension type{eng::TimeT(1)};

  EXPECT_EQ(eng::util::Rational(1, 1), type.time);
  EXPECT_EQ(eng::util::Rational(0, 1), type.mass);
  EXPECT_EQ(eng::util::Rational(0, 1), type.length);
  EXPECT_EQ(eng::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(0, 1), type.amount);
  EXPECT_EQ(eng::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateMassT) {
  eng::SIDimension type{eng::MassT({2, 3})};

  EXPECT_EQ(eng::util::Rational(0, 1), type.time);
  EXPECT_EQ(eng::util::Rational(2, 3), type.mass);
  EXPECT_EQ(eng::util::Rational(0, 1), type.length);
  EXPECT_EQ(eng::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(0, 1), type.amount);
  EXPECT_EQ(eng::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateLengthT) {
  eng::SIDimension type{eng::LengthT({5, 4})};

  EXPECT_EQ(eng::util::Rational(0, 1), type.time);
  EXPECT_EQ(eng::util::Rational(0, 1), type.mass);
  EXPECT_EQ(eng::util::Rational(5, 4), type.length);
  EXPECT_EQ(eng::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(0, 1), type.amount);
  EXPECT_EQ(eng::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateTerperatureT) {
  eng::SIDimension type{eng::TemperatureT({7, 2})};

  EXPECT_EQ(eng::util::Rational(0, 1), type.time);
  EXPECT_EQ(eng::util::Rational(0, 1), type.mass);
  EXPECT_EQ(eng::util::Rational(0, 1), type.length);
  EXPECT_EQ(eng::util::Rational(7, 2), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(0, 1), type.amount);
  EXPECT_EQ(eng::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateCurrentT) {
  eng::SIDimension type{eng::CurrentT({9, 5})};

  EXPECT_EQ(eng::util::Rational(0, 1), type.time);
  EXPECT_EQ(eng::util::Rational(0, 1), type.mass);
  EXPECT_EQ(eng::util::Rational(0, 1), type.length);
  EXPECT_EQ(eng::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(9, 5), type.current);
  EXPECT_EQ(eng::util::Rational(0, 1), type.amount);
  EXPECT_EQ(eng::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateAmountT) {
  eng::SIDimension type{eng::AmountT({5, 9})};

  EXPECT_EQ(eng::util::Rational(0, 1), type.time);
  EXPECT_EQ(eng::util::Rational(0, 1), type.mass);
  EXPECT_EQ(eng::util::Rational(0, 1), type.length);
  EXPECT_EQ(eng::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(5, 9), type.amount);
  EXPECT_EQ(eng::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateLuminosityT) {
  eng::SIDimension type{eng::LuminosityT({4, 7})};

  EXPECT_EQ(eng::util::Rational(0, 1), type.time);
  EXPECT_EQ(eng::util::Rational(0, 1), type.mass);
  EXPECT_EQ(eng::util::Rational(0, 1), type.length);
  EXPECT_EQ(eng::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(0, 1), type.amount);
  EXPECT_EQ(eng::util::Rational({4, 7}), type.luminosity);
}

TEST(TestSIDimension, CreateCompoundT1) {
  eng::SIDimension type{eng::TimeT({1, 2}) + eng::LengthT(1)};

  EXPECT_EQ(eng::util::Rational(1, 2), type.time);
  EXPECT_EQ(eng::util::Rational(0, 1), type.mass);
  EXPECT_EQ(eng::util::Rational(1, 1), type.length);
  EXPECT_EQ(eng::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(0, 1), type.amount);
  EXPECT_EQ(eng::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateCompoundT2) {
  eng::SIDimension type = eng::MassT({3, 2}) +
                          eng::AmountT(-2);

  EXPECT_EQ(eng::util::Rational(0, 1), type.time);
  EXPECT_EQ(eng::util::Rational(3, 2), type.mass);
  EXPECT_EQ(eng::util::Rational(0, 1), type.length);
  EXPECT_EQ(eng::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(-2, 1), type.amount);
  EXPECT_EQ(eng::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateCompoundT3) {
  eng::SIDimension type = eng::LuminosityT(4) -
                          eng::LengthT({3, 4}) +
                          eng::TemperatureT({6}) -
                          eng::TimeT(-1);

  EXPECT_EQ(eng::util::Rational(-1, 1), type.time);
  EXPECT_EQ(eng::util::Rational(0, 1), type.mass);
  EXPECT_EQ(eng::util::Rational(3, 4), type.length);
  EXPECT_EQ(eng::util::Rational(6, 1), type.temperature);
  EXPECT_EQ(eng::util::Rational(0, 1), type.current);
  EXPECT_EQ(eng::util::Rational(0, 1), type.amount);
  EXPECT_EQ(eng::util::Rational(4, 1), type.luminosity);
}
