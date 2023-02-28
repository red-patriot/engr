#ifndef ENGR_LIB_METRIC_UNITS_LITERALS_H
#define ENGR_LIB_METRIC_UNITS_LITERALS_H

#include "../util/CommonUnits.h"
#include "metric-prefix.h"

namespace engr {
  namespace units {
    static const ::engr::Mass kg{1};

    static const ::engr::Length m{1};

    static const ::engr::Temperature K{1};

    static const ::engr::SIUnit<::engr::TimeT(3)> s3{1};
    static const ::engr::SIUnit<::engr::TimeT(2)> s2{1};
    static const ::engr::Frequency Hz{1};

    static const ::engr::Mass g{0.001};

    static const ::engr::SecondMomentOfArea m4{1};
    static const ::engr::Volume m3{1};
    static const ::engr::Area m2{1};

    static const ::engr::Force N{1};
    static const ::engr::Energy J{1};
    static const ::engr::Power W{1};

    static const ::engr::Charge C{1};
    static const ::engr::Voltage V{1};
    static const ::engr::Resistance Ohm{1};
    static const ::engr::Capacitance F{1};
    static const ::engr::Inductance H{1};

    static const ::engr::Pressure Pa{1};
  }  // namespace units
}  // namespace engr

#endif
