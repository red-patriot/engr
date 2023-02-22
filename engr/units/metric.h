#ifndef ENGR_LIB_METRIC_UNITS_LITERALS_H
#define ENGR_LIB_METRIC_UNITS_LITERALS_H

#include "../util/CommonUnits.h"

namespace eng {
  namespace units {
    static const ::eng::SIUnit<::eng::MassT(1)> kg{1};

    static const ::eng::SIUnit<::eng::LengthT(1)> m{1};

    static const ::eng::SIUnit<::eng::TemperatureT(1)> K{1};
  }  // namespace units
}  // namespace eng

#endif
