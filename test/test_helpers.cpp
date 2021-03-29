#include "gtest/gtest.h"
#include "helpers.h"

TEST(HelpersTest, TestGenerateSample) {
  auto actual = helpers::GenerateSamples(1, 4983, 5029, 1.201, 2, 2, 0.05);
  helpers::Position expected{4980.5205281926819, 5032.2240188674632,
                             1.2701400834957814};
  ASSERT_EQ(expected, actual[0]);
}

TEST(HelpersTest, TestToMap1) {
  helpers::Position particle_in_map{4, 5, -M_PI_2};
  helpers::Position obs{2, 2};
  helpers::Position expected{6, 3};
  auto actual = helpers::ToMap(particle_in_map, obs);
  ASSERT_EQ(actual, expected);
}

TEST(HelpersTest, TestToMap2) {
  helpers::Position particle_in_map{4, 5, -M_PI_2};
  helpers::Position obs{3, -2};
  // FIXME: need to implement proper floating point comparison
  helpers::Position expected{2, 1.9999999999999998};
  auto actual = helpers::ToMap(particle_in_map, obs);
  ASSERT_EQ(actual, expected);
}

TEST(HelpersTest, TestToMap3) {
  helpers::Position particle_in_map{4, 5, -M_PI_2};
  helpers::Position obs{0, -4};
  helpers::Position expected{0, 5};
  auto actual = helpers::ToMap(particle_in_map, obs);
  ASSERT_EQ(actual, expected);
}