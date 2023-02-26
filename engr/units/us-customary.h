#ifndef ENGR_LIB_US_CUSTOMARY_UNITS_LITERALS_H
#define ENGR_LIB_US_CUSTOMARY_UNITS_LITERALS_H

#include "../util/CommonUnits.h"

namespace eng {
  namespace units {
    static const ::eng::Mass lbm{0.45359237};
    static const ::eng::Length yd{0.9144};
    static const ::eng::Temperature R{1 / 1.8};

    static const ::eng::Length ft{0.3048};
    static const ::eng::Length in{0.0254};

    static const ::eng::Force lbf{lbm * ::eng::Acceleration{9.80665}};
  }  // namespace units
}  // namespace eng

#endif
