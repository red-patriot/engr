#ifndef ENGR_LIB_US_CUSTOMARY_UNITS_LITERALS_H
#define ENGR_LIB_US_CUSTOMARY_UNITS_LITERALS_H

#include "../util/CommonUnits.h"

namespace engr {
  namespace units {
    static const ::engr::Mass lbm{0.45359237};
    static const ::engr::Length yd{0.9144};
    static const ::engr::Temperature R{1 / 1.8};

    static const ::engr::Length ft{0.3048};
    static const ::engr::Length in{0.0254};

    static const ::engr::Force lbf{lbm * ::engr::Acceleration{9.80665}};
  }  // namespace units
}  // namespace engr

#endif
