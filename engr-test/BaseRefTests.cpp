#include "pch.h"

#include <type_traits>
#include <array>

#include <units/SIBaseRef.h>

TEST(TestSIUnitRef, NotDefaultConstructible) {
  EXPECT_FALSE(std::is_default_constructible_v<engr::SIUnitRef<engr::TimeT(1)>>);
}

TEST(TestSIUnitRef, SimpleInstantiate) {
  engr::SIUnitRef<engr::TimeT({1, 2})> test{4.5};

  EXPECT_DOUBLE_EQ(4.5, test.base());
}

TEST(TestSIUnitRef, ReferenceSemantics) {
  double expected = 5.0;
  double value = 0.0;
  engr::SIUnitRef<engr::TimeT({1, 2})> test{value};
  test.base() = expected;

  EXPECT_DOUBLE_EQ(expected, test.base());
}

TEST(TestSIUnitRef, CoumpoundInstantiate) {
  engr::SIUnitRef<engr::TimeT({1, 2}) + engr::LengthT({-3})> test{1.3e-7};

  EXPECT_DOUBLE_EQ(1.3e-7, test.base());
}

template <engr::SIDimension Left, engr::SIDimension Right>
inline void testComparison(const engr::SIUnitRef<Left>& lhs, const engr::SIUnitRef<Right>& rhs,
                           const std::array<bool, 6>& comparisons) {
  EXPECT_EQ(comparisons[0], lhs == rhs);
  EXPECT_EQ(comparisons[1], lhs != rhs);

  EXPECT_EQ(comparisons[2], lhs > rhs);
  EXPECT_EQ(comparisons[3], lhs < rhs);

  EXPECT_EQ(comparisons[4], lhs >= rhs);
  EXPECT_EQ(comparisons[5], lhs <= rhs);
}

TEST(TestSIUnitRef, EqualComparisons) {
  engr::SIUnitRef<engr::AmountT({2, 3})> a{-5}, b{-5};

  testComparison(a, b, {true, false, false, false, true, true});
}

TEST(TestSIUnitRef, TestLessComparisons) {
  engr::SIUnitRef<engr::AmountT({2, 3})> a{4.5}, b{5.0};

  testComparison(a, b, {false, true, false, true, false, true});
}

TEST(TestSIUnitRef, GreaterComparisons) {
  engr::SIUnitRef<engr::AmountT({2, 3})> a{170.54}, b{-65.754};

  testComparison(a, b, {false, true, true, false, true, false});
}

// TODO: Figure out how to make this test work
// TEST(TestSIUnitRef, DifferentTypesComparisons) {
//  eng::SIUnitRef<eng::TimeT(1)> a{5.67};
//  eng::SIUnitRef<eng::LengthT(3)> b{5.67};
//
//  testComparison(a, b, {false, true, false, false, false, false});
//}

TEST(TestSIUnitRef, ArithmeticNegation) {
  engr::SIUnitRef<engr::LuminosityT(1) + engr::MassT(-1)> a{12};
  engr::SIUnitRef<engr::LuminosityT(1) + engr::MassT(-1)> expected{-12};

  auto actual = -a;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnitRef, ArithmeticAddition) {
  engr::SIUnitRef<engr::LengthT(3)> a{-6.7}, b{3};
  engr::SIUnitRef<engr::LengthT(3)> expected{-3.7};

  auto actual = a + b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnitRef, ArithmeticSubtraction) {
  engr::SIUnitRef<engr::CurrentT({-2, 3})> a{18}, b{6.8};
  engr::SIUnitRef<engr::CurrentT({-2, 3})> expected{11.2};

  auto actual = a - b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnitRef, ArithmeticMultiplication) {
  engr::SIUnitRef<engr::LengthT(1)> a(3);
  engr::SIUnitRef<engr::TimeT(-1)> b{2.2};
  engr::SIUnitRef<engr::LengthT(1) + engr::TimeT(-1)> expected{6.6};

  auto actual = a * b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnitRef, ArithmeticDivision) {
  engr::SIUnitRef<engr::LengthT(1)> a(14);
  engr::SIUnitRef<engr::TimeT(1)> b{2};
  engr::SIUnitRef<engr::LengthT(1) - engr::TimeT(1)> expected{7};

  auto actual = a / b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnitRef, ArithmeticDoublePreMultiplication) {
  engr::SIUnitRef<engr::CurrentT(4)> a{16.43};
  double b{5};
  engr::SIUnitRef<engr::CurrentT(4)> expected{82.15};

  auto actual = b * a;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnitRef, ArithmeticDoublePostMultiplication) {
  engr::SIUnitRef<engr::CurrentT(4)> a{16.43};
  double b{5};
  engr::SIUnitRef<engr::CurrentT(4)> expected{82.15};

  auto actual = a * b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnitRef, ArithmeticDoublePreDivision) {
  engr::SIUnitRef<engr::LengthT(2)> a{6};
  double b{26.2};
  engr::SIUnitRef<engr::LengthT(-2)> expected{4.366'666'666'667};

  auto actual = b / a;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestSIUnitRef, ArithmeticDoublePostDivision) {
  engr::SIUnitRef<engr::LengthT(2)> a{63};
  double b{5};
  engr::SIUnitRef<engr::LengthT(2)> expected{12.6};

  auto actual = a / b;

  EXPECT_EQ(expected.unit, actual.unit);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}
