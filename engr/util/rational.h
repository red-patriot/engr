#ifndef ENGR_LIB_UTIL_RATIONAL_H
#define ENGR_LIB_UTIL_RATIONAL_H

#include <cmath>
#include <numeric>
#include <cstdint>
#include <exception>

namespace eng {
  namespace util {
    class Rational {
     public:
      constexpr Rational(std::intmax_t num, std::intmax_t denom=1) :
          numerator_(sign(denom) * num / std::gcd(num, denom)),
          denominator_(absConstexpr(denom) / std::gcd(num, denom)) {
        if (denom == 0) {
          throw std::exception("denom of eng::Rational cannot be zero");
        }
      }

      constexpr ~Rational() noexcept = default;

      friend bool operator==(const Rational&, const Rational&) = default;

      const std::intmax_t numerator_;
      const std::intmax_t denominator_;

     private:
      static constexpr std::intmax_t sign(std::intmax_t a) {
        return a < 0 ? -1 : 1;
      }

      static constexpr std::intmax_t absConstexpr(std::intmax_t a) {
        return a < 0 ? -a : a;
      }
    };
  }  // namespace util
}  // namespace eng

#endif
