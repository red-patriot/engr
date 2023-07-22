#ifndef ENGR_LIB_US_CUSTOMARY_UNITS_LITERALS_H
#define ENGR_LIB_US_CUSTOMARY_UNITS_LITERALS_H

#include "../util/CommonUnits.h"

namespace engr {
  namespace units {
    static const ::engr::Mass pound_mass{0.45359237};
    static const ::engr::Length yard{0.9144};
    static const ::engr::Temperature rankine{1 / 1.8};

    static const ::engr::Length foot{0.3048};
    static const ::engr::Length inch{0.0254};

    static const ::engr::Force pound_force{pound_mass * ::engr::Acceleration{9.80665}};
  }  // namespace units
}  // namespace engr

#endif
