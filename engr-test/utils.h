#pragma once

#include <ostream>

#include <units/SIDimension.h>
#include <util/rational.h>

namespace eng {
  inline std::ostream& operator<<(std::ostream& os, const eng::util::Rational r) {
    os << r.numerator_ << "/" << r.denominator_;
    return os;
  }

  inline std::ostream& operator<<(std::ostream& os, const SIDimension& dim) {
    os << '{' << dim.time << ' '
       << dim.mass << ' '
       << dim.length << ' '
       << dim.temperature << ' '
       << dim.current << ' '
       << dim.amount << ' '
       << dim.luminosity << '}';

    return os;
  }
}  // namespace eng
