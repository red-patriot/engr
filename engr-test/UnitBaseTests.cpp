#include "pch.h"

#include <type_traits>
#include <array>

#include <units/SIBase.h>

TEST(TestSIUnit, DefaultConstructible) {
  EXPECT_TRUE(std::is_default_constructible_v<engr::SIUnit<engr::TimeT(1)>>);
}

TEST(TestSIUnit, SimpleInstantiate) {
  engr::SIUnit<engr::TimeT({1, 2})> test{4.5};

  EXPECT_DOUBLE_EQ(4.5, test.base());
}

TEST(TestSIUnit, CoumpoundInstantiate) {
  engr::SIUnit<engr::TimeT({1, 2}) + engr::LengthT({-3})> test{1.3e-7};

  EXPECT_DOUBLE_EQ(1.3e-7, test.base());
}

template <engr::SIDimension Left, engr::SIDimension Right>
inline void testComparison(const engr::SIUnit<Left>& lhs, const engr::SIUnit<Right>& rhs,
                           const std::array<bool, 6>& comparisons) {
  EXPECT_EQ(comparisons[0], lhs == rhs);
  EXPECT_EQ(comparisons[1], lhs != rhs);

  EXPECT_EQ(comparisons[2], lhs > rhs);
  EXPECT_EQ(comparisons[3], lhs < rhs);

  EXPECT_EQ(comparisons[4], lhs >= rhs);
  EXPECT_EQ(comparisons[5], lhs <= rhs);
}

TEST(TestSIUnit, EqualComparisons) {
  engr::SIUnit<engr::AmountT({2, 3})> a{-5}, b{-5};

  testComparison(a, b, {true, false, false, false, true, true});
}

TEST(TestSIUnit, TestLessComparisons) {
  engr::SIUnit<engr::AmountT({2, 3})> a{4.5}, b{5.0};

  testComparison(a, b, {false, true, false, true, false, true});
}

TEST(TestSIUnit, GreaterComparisons) {
  engr::SIUnit<engr::AmountT({2, 3})> a{170.54}, b{-65.754};

  testComparison(a, b, {false, true, true, false, true, false});
}

// TODO: Figure out how to make this test work
// TEST(TestSIUnit, DifferentTypesComparisons) {
//  eng::SIUnit<eng::TimeT(1)> a{5.67};
//  eng::SIUnit<eng::LengthT(3)> b{5.67};
//
//  testComparison(a, b, {false, true, false, false, false, false});
//}

TEST(TestSIUnit, ArithmeticNegation) {
  engr::SIUnit<engr::LuminosityT(1) + engr::MassT(-1)> a{12};
  engr::SIUnit<engr::LuminosityT(1) + engr::MassT(-1)> expected{-12};

  auto actual = -a;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnit, ArithmeticAddition) {
  engr::SIUnit<engr::LengthT(3)> a{-6.7}, b{3};
  engr::SIUnit<engr::LengthT(3)> expected{-3.7};

  auto actual = a + b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnit, ArithmeticSubtraction) {
  engr::SIUnit<engr::CurrentT({-2, 3})> a{18}, b{6.8};
  engr::SIUnit<engr::CurrentT({-2, 3})> expected{11.2};

  auto actual = a - b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnit, ArithmeticMultiplication) {
  engr::SIUnit<engr::LengthT(1)> a(3);
  engr::SIUnit<engr::TimeT(-1)> b{2.2};
  engr::SIUnit<engr::LengthT(1) + engr::TimeT(-1)> expected{6.6};

  auto actual = a * b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnit, ArithmeticDivision) {
  engr::SIUnit<engr::LengthT(1)> a(14);
  engr::SIUnit<engr::TimeT(1)> b{2};
  engr::SIUnit<engr::LengthT(1) - engr::TimeT(1)> expected{7};

  auto actual = a / b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnit, ArithmeticDoublePreMultiplication) {
  engr::SIUnit<engr::CurrentT(4)> a{16.43};
  double b{5};
  engr::SIUnit<engr::CurrentT(4)> expected{82.15};

  auto actual = b * a;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnit, ArithmeticDoublePostMultiplication) {
  engr::SIUnit<engr::CurrentT(4)> a{16.43};
  double b{5};
  engr::SIUnit<engr::CurrentT(4)> expected{82.15};

  auto actual = a * b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnit, ArithmeticDoublePreDivision) {
  engr::SIUnit<engr::LengthT(2)> a{6};
  double b{26.2};
  engr::SIUnit<engr::LengthT(-2)> expected{4.366'666'666'667};

  auto actual = b / a;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnit, ArithmeticDoublePostDivision) {
  engr::SIUnit<engr::LengthT(2)> a{63};
  double b{5};
  engr::SIUnit<engr::LengthT(2)> expected{12.6};

  auto actual = a / b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}
