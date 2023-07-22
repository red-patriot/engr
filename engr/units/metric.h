#ifndef ENGR_LIB_METRIC_UNITS_LITERALS_H
#define ENGR_LIB_METRIC_UNITS_LITERALS_H

#include "../util/CommonUnits.h"
#include "metric-prefix.h"

namespace engr {
  namespace units {
    static const ::engr::Mass kilogram{1};

    static const ::engr::Length meter{1};

    static const ::engr::Temperature kelvin{1};

    static const ::engr::SIUnit<::engr::TimeT(3)> second3{1};
    static const ::engr::SIUnit<::engr::TimeT(2)> second2{1};
    static const ::engr::Frequency hertz{1};

    static const ::engr::Mass gram{0.001};

    static const ::engr::SecondMomentOfArea meter4{1};
    static const ::engr::Volume meter3{1};
    static const ::engr::Area meter2{1};

    static const ::engr::Force newton{1};
    static const ::engr::Energy joule{1};
    static const ::engr::Power watt{1};

    static const ::engr::Charge coulomb{1};
    static const ::engr::Voltage volt{1};
    static const ::engr::Resistance ohm{1};
    static const ::engr::Capacitance farad{1};
    static const ::engr::Inductance henry{1};

    static const ::engr::Pressure pascal{1};
  }  // namespace units
}  // namespace engr

#endif
