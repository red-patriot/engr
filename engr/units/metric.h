#ifndef ENGR_LIB_UNITS_LITERALS_H
#define ENGR_LIB_UNITS_LITERALS_H

#include "SIBase.h"

namespace eng {
  namespace units {
    namespace metric {
      static const ::eng::SIUnit<::eng::TimeT(1)> s{1};

      static const ::eng::SIUnit<::eng::MassT(1)> kg{1};

      static const ::eng::SIUnit<::eng::LengthT(1)> m{1};

      static const ::eng::SIUnit<::eng::TemperatureT(1)> K{1};

      static const ::eng::SIUnit<::eng::CurrentT(1)> A{1};

      static const ::eng::SIUnit<::eng::AmountT(1)> mol{1};

      static const ::eng::SIUnit<::eng::LuminosityT(1)> cd{1};
    }  // namespace metric
  }    // namespace units
}  // namespace eng

#endif
