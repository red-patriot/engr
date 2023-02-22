#ifndef ENGR_LIB_COMMON_UNITS_LITERALS_H
#define ENGR_LIB_COMMON_UNITS_LITERALS_H

#include "../units/SIBase.h"

namespace eng {
  namespace units {
    static const ::eng::SIUnit<::eng::TimeT(1)> s{1};
    static const ::eng::SIUnit<::eng::CurrentT(1)> A{1};

    static const ::eng::SIUnit<::eng::AmountT(1)> mol{1};

    static const ::eng::SIUnit<::eng::LuminosityT(1)> cd{1};
  }
}

#endif
