#ifndef ENGR_LIB_UNITS_SI_BASE_H
#define ENGR_LIB_UNITS_SI_BASE_H

#include <ratio>

#include "SIDimension.h"

namespace eng {
  template <SIDimension Dim>
  class SIUnit {
   public:
    explicit SIUnit(double base) noexcept :
        base_(base) { }

    double base() const noexcept { return base_; }

    inline auto operator<=>(const SIUnit<Dim>&) const& noexcept = default;

   private:
    double base_;
  };

  template<SIDimension Dim>
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

  void test();
}  // namespace eng

#endif
