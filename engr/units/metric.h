#ifndef ENGR_LIB_METRIC_UNITS_LITERALS_H
#define ENGR_LIB_METRIC_UNITS_LITERALS_H

#include "../util/CommonUnits.h"

namespace eng {
  namespace units {
    static const ::eng::Mass kg{1};

    static const ::eng::Length m{1};

    static const ::eng::Temperature K{1};

    static const ::eng::SIUnit<::eng::TimeT(3)> s3{1};
    static const ::eng::SIUnit<::eng::TimeT(2)> s2{1};
    static const ::eng::Frequency Hz{1};

    static const ::eng::SecondMomentOfArea m4{1};
    static const ::eng::Volume m3{1};
    static const ::eng::Area m2{1};

    static const ::eng::Force N{1};
    static const ::eng::Energy J{1};
    static const ::eng::Power W{1};

  }  // namespace units
}  // namespace eng

#endif
