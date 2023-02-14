#include "pch.h"

#include <units/SIBase.h>

TEST(TestSIUnit, SimpleInstantiate) {
  eng::SIUnit<eng::TimeT({1, 2})> test = 4.5;

  EXPECT_DOUBLE_EQ(4.5, test.base());
}

TEST(TestSIUnit, CoumpoundInstantiate) {
  eng::SIUnit<eng::TimeT({1, 2}) + eng::LengthT({-3})> test = 1.3e-7;

  EXPECT_DOUBLE_EQ(1.3e-7, test.base());
}
