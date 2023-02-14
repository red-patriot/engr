#include "pch.h"

#include <type_traits>

#include <units/SIDimension.h>

TEST(TestSIDimension, CreateTimeT) {
  eng::SIDimension<1, 0, 0, 0, 0, 0, 0> expected;
}
