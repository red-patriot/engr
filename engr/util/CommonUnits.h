#ifndef ENGR_LIB_COMMON_UNITS_LITERALS_H
#define ENGR_LIB_COMMON_UNITS_LITERALS_H

#include "../units/SIBase.h"
#include "../units/UnitTypes.h"

namespace eng {
  namespace units {
    static const ::eng::Time s{1};
    static const ::eng::Current A{1};

    static const ::eng::Amount mol{1};

    static const ::eng::Luminosity cd{1};
  }
}

#endif
