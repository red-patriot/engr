#ifndef ENGR_LIB_UNITS_SI_BASE_H
#define ENGR_LIB_UNITS_SI_BASE_H

#include <ratio>

#include "SIDimension.h"

namespace eng {
  template <eng::SIDimension>
  class SIUnit {
   public:
    explicit SIUnit(double base) noexcept :
        base_(base) { }

    double base() const noexcept {
      return base_;
    }

   private:
    double base_;
  };

  void test();
}  // namespace eng

#endif
