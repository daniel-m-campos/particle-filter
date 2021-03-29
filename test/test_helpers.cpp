#include "gtest/gtest.h"
#include "helpers.h"

TEST(HelpersTest, TestSample) {
  auto actual = helpers::GenerateSamples(1, 4983, 5029, 1.201, 2, 2, 0.05);
  helpers::Sample expected{4980.5205281926819, 5032.2240188674632,
                           1.2701400834957814};
  int i = 0;
  ASSERT_EQ(expected, actual[0]);
  for (const auto& sample : actual) {
    std::cout << "Sample " << ++i << " " << sample.x << " " << sample.y << " "
              << sample.theta << std::endl;
  }
}