#ifndef ENGR_LIB_UNITS_LITERALS_H
#define ENGR_LIB_UNITS_LITERALS_H

#include "SIBase.h"

namespace eng {
  namespace units {
    namespace metric {
      const ::eng::SIUnit< ::eng::TimeT(1)> s{1};

      const ::eng::SIUnit< ::eng::MassT(1)> kg{1};

      const ::eng::SIUnit< ::eng::LengthT(1)> m{1};
    }  // namespace metric
  }  // namespace units
}  // namespace eng

#endif
