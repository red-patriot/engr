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

  void test();
}  // namespace eng

#endif
