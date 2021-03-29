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
  helpers::Position expected{6, 3};  // L1(5,3)
  auto actual = helpers::ToMap(particle_in_map, obs);
  ASSERT_EQ(actual, expected);
}

TEST(HelpersTest, TestToMap2) {
  helpers::Position particle_in_map{4, 5, -M_PI_2};
  helpers::Position obs{3, -2};
  // FIXME: need to implement proper floating point comparison
  helpers::Position expected{2, 1.9999999999999998};  // L2(2,1)
  auto actual = helpers::ToMap(particle_in_map, obs);
  ASSERT_EQ(actual, expected);
}

TEST(HelpersTest, TestToMap3) {
  helpers::Position particle_in_map{4, 5, -M_PI_2};
  helpers::Position obs{0, -4};
  helpers::Position expected{0, 5};  // L5(4,7)
  auto actual = helpers::ToMap(particle_in_map, obs);
  ASSERT_EQ(actual, expected);
}

TEST(HelpersTest, TestNormPDF1) {
  helpers::Position obs{6, 3};
  auto actual = helpers::NormPDF(obs.x, obs.y, 5, 3, 0.3, 0.3);
  ASSERT_NEAR(actual, 0.00683645, 1e-6);
}

TEST(HelpersTest, TestNormPDF2) {
  helpers::Position obs{2, 2};
  auto actual = helpers::NormPDF(obs.x, obs.y, 2, 1, 0.3, 0.3);
  ASSERT_NEAR(actual, 0.00683645, 1e-6);
}

TEST(HelpersTest, TestNormPDF3) {
  helpers::Position obs{0, 5};
  auto actual = helpers::NormPDF(obs.x, obs.y, 4, 7, 0.3, 0.3);
  ASSERT_NEAR(actual, 9.8318487415059318e-49, 1e-6);
}