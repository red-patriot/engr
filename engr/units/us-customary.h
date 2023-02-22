#ifndef ENGR_LIB_US_CUSTOMARY_UNITS_LITERALS_H
#define ENGR_LIB_US_CUSTOMARY_UNITS_LITERALS_H

#include "../util/CommonUnits.h"

namespace eng {
  namespace units {
    static const ::eng::SIUnit<::eng::MassT(1)> lbm{0.45359237};

    static const ::eng::SIUnit<::eng::LengthT(1)> yd{0.9144};

    static const ::eng::SIUnit<::eng::TemperatureT(1)> R{1 / 1.8};
  }  // namespace units
}  // namespace eng

#endif
