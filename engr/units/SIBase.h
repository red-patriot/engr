#ifndef ENGR_LIB_UNITS_SI_BASE_H
#define ENGR_LIB_UNITS_SI_BASE_H

#include <ratio>

#include "../util/rational.h"

namespace eng {
 class SIUnit {
   public:
    SIUnit(double base) noexcept :
        base_(base) { }

   private:
    double base_;
  };

  void test();
}  // namespace eng

#endif
