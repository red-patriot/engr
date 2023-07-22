#include "pch.h"

#include <units/metric.h>
#include <units/Vector.h>

using namespace engr::units;

//TEST(TestSIUnit, Construct2DVector) {
//  engr::Vector<engr::Length::unit, 2> expected = {3.4, 5.6} * meter;
//
//  EXPECT_DOUBLE_EQ(3.4, expected.x().as(meter));
//  EXPECT_DOUBLE_EQ(5.6, expected.y().as(meter));
//}
//
//TEST(TestSIUnit, Construct3DVector) {
//  engr::Vector<engr::Force::unit, 3> expected = {12, 0.5, -4.67} * engr::kilo(newton);
//
//  EXPECT_DOUBLE_EQ(12'000, expected.x().as(newton));
//  EXPECT_DOUBLE_EQ(500, expected.y().as(newton));
//  EXPECT_DOUBLE_EQ(-4'670, expected.z().as(newton));
//}
