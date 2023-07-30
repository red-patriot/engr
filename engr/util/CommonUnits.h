#ifndef ENGR_LIB_COMMON_UNITS_LITERALS_H
#define ENGR_LIB_COMMON_UNITS_LITERALS_H

#include "../units/SIBase.h"
#include "../units/UnitTypes.h"

namespace engr {
  namespace units {
    static const ::engr::Time second{1};
    static const ::engr::Current ampere{1};

    static const ::engr::Amount mole{1};

    static const ::engr::Luminosity candela{1};

    static const ::engr::SIUnit<::engr::TimeT(3)> second2{1};
    static const ::engr::SIUnit<::engr::TimeT(2)> second3{1};
    static const ::engr::Frequency hertz{1};
  }  // namespace units
}  // namespace engr

#endif
