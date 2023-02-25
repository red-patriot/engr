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

  using Frequency = SIUnit<TimeT(-1)>;

  using Area = SIUnit<LengthT(2)>;
  using Volume = SIUnit<LengthT(3)>;
  using SecondMomentOfArea = SIUnit<LengthT(4)>;

  using Velocity = SIUnit<LengthT(1) - TimeT(1)>;
  using Acceleration = SIUnit<LengthT(1) - TimeT(2)>;
  using Jerk = SIUnit<LengthT(1) - TimeT(3)>;

  using Force = SIUnit<MassT(1) + LengthT(1) - TimeT(2)>;
  using Energy = SIUnit<MassT(1) + LengthT(2) - TimeT(2)>;
  using Power = SIUnit<MassT(1) + LengthT(2) - TimeT(3)>;
}  // namespace eng

#endif