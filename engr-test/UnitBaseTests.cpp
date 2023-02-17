#include "pch.h"

#include <array>

#include <units/SIBase.h>

TEST(TestSIUnit, SimpleInstantiate) {
  eng::SIUnit<eng::TimeT({1, 2})> test{4.5};

  EXPECT_DOUBLE_EQ(4.5, test.base());
}

TEST(TestSIUnit, CoumpoundInstantiate) {
  eng::SIUnit<eng::TimeT({1, 2}) + eng::LengthT({-3})> test{1.3e-7};

  EXPECT_DOUBLE_EQ(1.3e-7, test.base());
}

template <eng::SIDimension Left, eng::SIDimension Right>
inline void testComparison(const eng::SIUnit<Left>& lhs, const eng::SIUnit<Right>& rhs,
                           const std::array<bool, 6>& comparisons) {
  EXPECT_EQ(comparisons[0], lhs == rhs);
  EXPECT_EQ(comparisons[1], lhs != rhs);

  EXPECT_EQ(comparisons[2], lhs > rhs);
  EXPECT_EQ(comparisons[3], lhs < rhs);

  EXPECT_EQ(comparisons[4], lhs >= rhs);
  EXPECT_EQ(comparisons[5], lhs <= rhs);
}

TEST(TestSIUnit, EqualComparisons) {
  eng::SIUnit<eng::AmountT({2, 3})> a{-5}, b{-5};

  testComparison(a, b, {true, false, false, false, true, true});
}

TEST(TestSIUnit, TestLessComparisons) {
  eng::SIUnit<eng::AmountT({2, 3})> a{4.5}, b{5.0};

  testComparison(a, b, {false, true, false, true, false, true});
}

TEST(TestSIUnit, GreaterComparisons) {
  eng::SIUnit<eng::AmountT({2, 3})> a{170.54}, b{-65.754};

  testComparison(a, b, {false, true, true, false, true, false});
}

// TODO: Figure out how to make this test work
//TEST(TestSIUnit, DifferentTypesComparisons) {
//  eng::SIUnit<eng::TimeT(1)> a{5.67};
//  eng::SIUnit<eng::LengthT(3)> b{5.67};
//
//  testComparison(a, b, {false, true, false, false, false, false});
//}

TEST(TestSIUnit, ArithmeticNegation) {
  eng::SIUnit<eng::LuminosityT(1) + eng::MassT(-1)> a{12};
  eng::SIUnit<eng::LuminosityT(1) + eng::MassT(-1)> expected{-12};

  auto actual = -a;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIUnit, ArithmeticAddition) { 
  eng::SIUnit<eng::LengthT(3)> a{-6.7}, b{3};
  eng::SIUnit<eng::LengthT(3)> expected{-3.7};

  auto actual = a + b;
  
  EXPECT_EQ(expected, actual);
}

TEST(TestSIUnit, ArithmeticSubtraction) {
  eng::SIUnit<eng::CurrentT({-2, 3})> a{18}, b{6.8};
  eng::SIUnit<eng::CurrentT({-2, 3})> expected{11.2};

  auto actual = a - b;

  EXPECT_EQ(expected, actual);
}

