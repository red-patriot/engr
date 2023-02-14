#include "pch.h"

#include <tuple>

#include <util/rational.h>

using eng::util::Rational;
using std::tuple;

class TestRationalConstruct : public ::testing::TestWithParam<tuple<Rational,
                                                           int, int>> {
};

TEST_P(TestRationalConstruct, InstantiateWithTwoInts) {
  auto [expected, numerator, denominator] = GetParam();

  Rational actual(numerator, denominator);

  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(TestRational, TestRationalConstruct,
                        testing::Values(tuple{Rational{1, 2}, 1, 2},
                                        tuple{Rational{1, 1}, 1, 1},
                                        tuple{Rational{2, 3}, 2, 3},
                                        tuple{Rational{2, 2}, 1, 1}));

TEST(TestRational, ImplicitDenominator) {
  Rational expected(2, 1);

  Rational actual(2);

  EXPECT_EQ(expected, actual);
}

TEST(TestRational, ZeroDemoninator) {
  EXPECT_ANY_THROW(Rational(1, 0));
}
