#ifndef ENGR_LIB_COMMON_UNITS_LITERALS_H
#define ENGR_LIB_COMMON_UNITS_LITERALS_H

#include "../units/SIBase.h"
#include "../units/UnitTypes.h"

namespace engr {
  namespace units {
    static const ::engr::Time s{1};
    static const ::engr::Current A{1};

    static const ::engr::Amount mol{1};

    static const ::engr::Luminosity cd{1};
  }
}

#endif
