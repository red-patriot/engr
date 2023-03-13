#include "pch.h"

#include <systems/StaticSystem.h>
#include <units/metric.h>

using namespace engr::units;

TEST(TestStaticSystem, 2DSystemForceOnly) {
  /** This problem taken from Engineering Mechanics: Statics by Plesha, et. al.
   *  Problem 3.24 */
  engr::Force expectedR = 315.5 * N;
  engr::Force expectedTABC = 144.2 * N;

  engr::StaticSystem sys;
  engr::Load actualR = engr::unknownForce({1.2 / 3.7, 3.5 / 3.7, 0},
                                          engr::Vector3<engr::Length>::Zero);
  engr::Load actualTABC = engr::unknownForce(engr::unknownDirection,
                                             engr::Vector3<engr::Length>::Zero);

  sys.add(engr::Vector3<engr::Force>{0 * N, -400 * N, 0.0 * N},
          engr::Vector3<engr::Length>::Zero);
  sys.add(actualR);
  sys.add(actualTABC);

  auto result = sys.solve();

  EXPECT_TRUE(result);
  EXPECT_NEAR(expectedR.as(N), actualR.force().norm().as(N), 1e-10);
  EXPECT_NEAR(expectedTABC.as(N), actualTABC.force().norm().as(N), 1e-10);
}
