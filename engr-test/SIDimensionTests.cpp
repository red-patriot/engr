#include "pch.h"

#include <type_traits>

#include <units/SIDimension.h>

TEST(TestSIDimension, CreateTimeT) {
  engr::SIDimension type{engr::TimeT(1)};

  EXPECT_EQ(engr::util::Rational(1, 1), type.time);
  EXPECT_EQ(engr::util::Rational(0, 1), type.mass);
  EXPECT_EQ(engr::util::Rational(0, 1), type.length);
  EXPECT_EQ(engr::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(0, 1), type.amount);
  EXPECT_EQ(engr::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateMassT) {
  engr::SIDimension type{engr::MassT({2, 3})};

  EXPECT_EQ(engr::util::Rational(0, 1), type.time);
  EXPECT_EQ(engr::util::Rational(2, 3), type.mass);
  EXPECT_EQ(engr::util::Rational(0, 1), type.length);
  EXPECT_EQ(engr::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(0, 1), type.amount);
  EXPECT_EQ(engr::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateLengthT) {
  engr::SIDimension type{engr::LengthT({5, 4})};

  EXPECT_EQ(engr::util::Rational(0, 1), type.time);
  EXPECT_EQ(engr::util::Rational(0, 1), type.mass);
  EXPECT_EQ(engr::util::Rational(5, 4), type.length);
  EXPECT_EQ(engr::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(0, 1), type.amount);
  EXPECT_EQ(engr::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateTerperatureT) {
  engr::SIDimension type{engr::TemperatureT({7, 2})};

  EXPECT_EQ(engr::util::Rational(0, 1), type.time);
  EXPECT_EQ(engr::util::Rational(0, 1), type.mass);
  EXPECT_EQ(engr::util::Rational(0, 1), type.length);
  EXPECT_EQ(engr::util::Rational(7, 2), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(0, 1), type.amount);
  EXPECT_EQ(engr::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateCurrentT) {
  engr::SIDimension type{engr::CurrentT({9, 5})};

  EXPECT_EQ(engr::util::Rational(0, 1), type.time);
  EXPECT_EQ(engr::util::Rational(0, 1), type.mass);
  EXPECT_EQ(engr::util::Rational(0, 1), type.length);
  EXPECT_EQ(engr::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(9, 5), type.current);
  EXPECT_EQ(engr::util::Rational(0, 1), type.amount);
  EXPECT_EQ(engr::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateAmountT) {
  engr::SIDimension type{engr::AmountT({5, 9})};

  EXPECT_EQ(engr::util::Rational(0, 1), type.time);
  EXPECT_EQ(engr::util::Rational(0, 1), type.mass);
  EXPECT_EQ(engr::util::Rational(0, 1), type.length);
  EXPECT_EQ(engr::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(5, 9), type.amount);
  EXPECT_EQ(engr::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateLuminosityT) {
  engr::SIDimension type{engr::LuminosityT({4, 7})};

  EXPECT_EQ(engr::util::Rational(0, 1), type.time);
  EXPECT_EQ(engr::util::Rational(0, 1), type.mass);
  EXPECT_EQ(engr::util::Rational(0, 1), type.length);
  EXPECT_EQ(engr::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(0, 1), type.amount);
  EXPECT_EQ(engr::util::Rational({4, 7}), type.luminosity);
}

TEST(TestSIDimension, CreateCompoundT1) {
  engr::SIDimension type{engr::TimeT({1, 2}) + engr::LengthT(1)};

  EXPECT_EQ(engr::util::Rational(1, 2), type.time);
  EXPECT_EQ(engr::util::Rational(0, 1), type.mass);
  EXPECT_EQ(engr::util::Rational(1, 1), type.length);
  EXPECT_EQ(engr::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(0, 1), type.amount);
  EXPECT_EQ(engr::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateCompoundT2) {
  engr::SIDimension type = engr::MassT({3, 2}) +
                          engr::AmountT(-2);

  EXPECT_EQ(engr::util::Rational(0, 1), type.time);
  EXPECT_EQ(engr::util::Rational(3, 2), type.mass);
  EXPECT_EQ(engr::util::Rational(0, 1), type.length);
  EXPECT_EQ(engr::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(-2, 1), type.amount);
  EXPECT_EQ(engr::util::Rational(0, 1), type.luminosity);
}

TEST(TestSIDimension, CreateCompoundT3) {
  engr::SIDimension type = engr::LuminosityT(4) -
                          engr::LengthT({3, 4}) +
                          engr::TemperatureT({6}) -
                          engr::TimeT(-1);

  EXPECT_EQ(engr::util::Rational(1, 1), type.time);
  EXPECT_EQ(engr::util::Rational(0, 1), type.mass);
  EXPECT_EQ(engr::util::Rational(-3, 4), type.length);
  EXPECT_EQ(engr::util::Rational(6, 1), type.temperature);
  EXPECT_EQ(engr::util::Rational(0, 1), type.current);
  EXPECT_EQ(engr::util::Rational(0, 1), type.amount);
  EXPECT_EQ(engr::util::Rational(4, 1), type.luminosity);
}
