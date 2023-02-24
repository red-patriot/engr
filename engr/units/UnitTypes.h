#ifndef ENGR_LIB_UNITS_UNIT_TYPES_H
#define ENGR_LIB_UNITS_UNIT_TYPES_H

#include "SIBase.h"

namespace eng {
  using Time = SIUnit<TimeT(1)>;
  using Mass = SIUnit<MassT(1)>;
  using Length = SIUnit<LengthT(1)>;
  using Temperature = SIUnit<TemperatureT(1)>;
  using Current = SIUnit<CurrentT(1)>;
  using Amount = SIUnit<AmountT(1)>;
  using Luminosity = SIUnit<LuminosityT(1)>;
}  // namespace eng

#endif
