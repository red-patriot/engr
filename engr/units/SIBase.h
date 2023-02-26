#ifndef ENGR_LIB_UNITS_SI_BASE_H
#define ENGR_LIB_UNITS_SI_BASE_H

#include <cmath>

#include "SIDimension.h"

namespace eng {
  template <SIDimension Dim>
  class SIUnit {
   public:
    explicit SIUnit(double base) noexcept :
        base_(base) { }

    static constexpr SIDimension unit = Dim;

    double base() const noexcept { return base_; }

    inline auto operator<=>(const SIUnit<Dim>&) const& noexcept = default;

   private:
    double base_;
  };

  template <SIDimension Dim>
  inline SIUnit<Dim> operator-(const SIUnit<Dim>& rhs) {
    return SIUnit<Dim>(-rhs.base());
  }

  template <SIDimension Dim>
  inline SIUnit<Dim> operator+(const SIUnit<Dim>& lhs, const SIUnit<Dim>& rhs) noexcept {
    return SIUnit<Dim>(lhs.base() + rhs.base());
  }

  template <SIDimension Dim>
  inline SIUnit<Dim> operator-(const SIUnit<Dim>& lhs, const SIUnit<Dim>& rhs) noexcept {
    return SIUnit<Dim>(lhs.base() - rhs.base());
  }

  template <SIDimension L, SIDimension R>
  inline auto operator*(const SIUnit<L>& lhs, const SIUnit<R>& rhs) noexcept {
    return SIUnit<dimAdd(L, R)>{lhs.base() * rhs.base()};
  }

  template <SIDimension Dim>
  constexpr SIUnit<Dim> operator*(double lhs, const SIUnit<Dim>& rhs) noexcept {
    return SIUnit<Dim>{lhs * rhs.base()};
  }

  template <SIDimension Dim>
  constexpr SIUnit<Dim> operator*(const SIUnit<Dim>& lhs, double rhs) noexcept {
    return SIUnit<Dim>{lhs.base() * rhs};
  }

  template <SIDimension L, SIDimension R>
  inline auto operator/(const SIUnit<L>& lhs, const SIUnit<R>& rhs) noexcept {
    return SIUnit<dimSub(L, R)>{lhs.base() / rhs.base()};
  }

  template <SIDimension Dim>
  constexpr auto operator/(double lhs, const SIUnit<Dim>& rhs) noexcept {
    return SIUnit<invert(Dim)>{lhs / rhs.base()};
  }

  template <SIDimension Dim>
  constexpr auto operator/(const SIUnit<Dim>& lhs, double rhs) noexcept {
    return SIUnit<Dim>{lhs.base() / rhs};
  }

  template <std::intmax_t P, SIDimension Dim>
  inline constexpr auto pow(const SIUnit<Dim>& lhs) noexcept {
    return SIUnit<dimMult(Dim, P)>(std::pow(lhs.base(), P));
  }

  template <std::intmax_t P, std::intmax_t R, SIDimension Dim>
  inline constexpr auto pow(const SIUnit<Dim>& lhs) noexcept {
    return SIUnit<dimMult(Dim, {P, R})>(std::pow(lhs.base(), (double)P / (double)R));
  }

  template <std::intmax_t R, SIDimension Dim>
  inline constexpr auto rt(const SIUnit<Dim>& lhs) noexcept {
    return pow<1, R>(lhs);
  }

  void test();
}  // namespace eng

#endif
