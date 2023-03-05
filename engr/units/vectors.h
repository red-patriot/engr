#ifndef ENGR_LIB_VECTORS_H
#define ENGR_LIB_VECTORS_H

#include <Eigen/Core>

#include "UnitTypes.h"

namespace Eigen {
  template <engr::SIDimension Dim>
  struct NumTraits<engr::SIUnit<Dim>> {
    using Real = engr::SIUnit<Dim>;
    using NonInteger = engr::SIUnit<Dim>;
    using Nested = engr::SIUnit<Dim>;

    enum {
      IsComplex = 0,
      IsInteger = 0,
      IsSigned = 1,
      RequireInitialization = 0,
      ReadCost = 1,
      AddCost = 3,
      MulCost = 3
    };
  };
}  // namespace Eigen

#endif
