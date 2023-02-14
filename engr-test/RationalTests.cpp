#include "pch.h"

#include <tuple>

#include <util/rational.h>

using eng::util::Rational;
using std::tuple;

class TestRational : public ::testing::TestWithParam<tuple<Rational,
                                                           int, int>> {
};

TEST_P(TestRational, InstantiateWithTwoInts) {
  auto [expected, numerator, denominator] = GetParam();

  Rational actual(numerator, denominator);

  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(TestRational, TestRational,
                        testing::Values(tuple{Rational{1, 2}, 1, 2},
                                        tuple{Rational{1, 1}, 1, 1},
                                        tuple{Rational{2, 3}, 2, 3},
                                        tuple{Rational{2, 2}, 1, 1}));
