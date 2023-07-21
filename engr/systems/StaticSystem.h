#ifndef ENGR_LIB_SYSTEMS_STATIC_SYSTEM_H
#define ENGR_LIB_SYSTEMS_STATIC_SYSTEM_H

#include <units/Vector.h>
#include "Load.h"

namespace engr {
  class StaticSystem {
   public:
    void add(Load& load);
    void add(engr::Vector<engr::Force::unit, 3> knownLoad,
             engr::Vector<engr::Length::unit, 3> position);

    bool solve();
  };
}  // namespace engr

#endif
