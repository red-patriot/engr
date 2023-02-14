#ifndef ENGR_LIB_UNITS_SI_DIMENSION_H
#define ENGR_LIB_UNITS_SI_DIMENSION_H

#include "../util/rational.h"

namespace eng {
  class SIDimension {
   public:
    const util::Rational time;
    const util::Rational mass;
    const util::Rational length;
    const util::Rational temperature;
    const util::Rational current;
    const util::Rational amount;
    const util::Rational luminosity;

    constexpr ~SIDimension() = default;

    friend constexpr SIDimension TimeT(const util::Rational& time);
    friend constexpr SIDimension MassT(const util::Rational& mass);
    friend constexpr SIDimension LengthT(const util::Rational& length);
    friend constexpr SIDimension TemperatureT(const util::Rational& temperature);
    friend constexpr SIDimension CurrentT(const util::Rational& current);
    friend constexpr SIDimension AmountT(const util::Rational& amount);
    friend constexpr SIDimension LuminosityT(const util::Rational& luminosity);

    friend constexpr SIDimension operator+(const SIDimension& a, const SIDimension& b);
    friend constexpr SIDimension operator-(const SIDimension& a, const SIDimension& b);

   private:
    constexpr SIDimension(util::Rational time_ = util::Rational(0),
                          util::Rational mass_ = util::Rational(0),
                          util::Rational length_ = util::Rational(0),
                          util::Rational temperature_ = util::Rational(0),
                          util::Rational current_ = util::Rational(0),
                          util::Rational amount_ = util::Rational(0),
                          util::Rational luminosity_ = util::Rational(0)) :
        time(time_),
        mass(mass_),
        length(length_),
        temperature(temperature_),
        current(current_),
        amount(amount_),
        luminosity(luminosity_) { }
  };

  constexpr SIDimension TimeT(const util::Rational& time) {
    return SIDimension(time);
  }

  constexpr SIDimension MassT(const util::Rational& mass) {
    return SIDimension({0}, mass);
  }

  constexpr SIDimension LengthT(const util::Rational& length) {
    return SIDimension({0}, {0}, length);
  }

  constexpr SIDimension TemperatureT(const util::Rational& temperature) {
    return SIDimension({0}, {0}, {0}, temperature);
  }

  constexpr SIDimension CurrentT(const util::Rational& current) {
    return SIDimension({0}, {0}, {0}, {0}, current);
  }

  constexpr SIDimension AmountT(const util::Rational& amount) {
    return SIDimension({0}, {0}, {0}, {0}, {0}, amount);
  }

  constexpr SIDimension LuminosityT(const util::Rational& luminosity) {
    return SIDimension({0}, {0}, {0}, {0}, {0}, {0}, luminosity);
  }

  constexpr SIDimension operator+(const SIDimension& a, const SIDimension& b) {
    return SIDimension(a.time + b.time,
                       a.mass + b.mass,
                       a.length + b.length,
                       a.temperature + b.temperature,
                       a.current + b.current,
                       a.amount + b.amount,
                       a.luminosity + b.luminosity);
  }

  constexpr SIDimension operator-(const SIDimension& a, const SIDimension& b) {
    return SIDimension(a.time - b.time,
                       a.mass - b.mass,
                       a.length - b.length,
                       a.temperature - b.temperature,
                       a.current - b.current,
                       a.amount - b.amount,
                       a.luminosity - b.luminosity);
  }

}  // namespace eng

#endif
