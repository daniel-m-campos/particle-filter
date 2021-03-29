#ifndef PARTICLEFILTER_SRC_HELPERS_H_
#define PARTICLEFILTER_SRC_HELPERS_H_

#include <vector>

namespace helpers {

struct Sample {
  double x;
  double y;
  double theta;
  bool operator==(const Sample& rhs) const {
    return std::tie(x, y, theta) == std::tie(rhs.x, rhs.y, rhs.theta);
  }
  bool operator!=(const Sample& rhs) const { return !(rhs == *this); }
};

std::vector<Sample> GenerateSamples(size_t size, double gps_x, double gps_y,
                                    double theta, double std_x, double std_y,
                                    double std_theta);

}  // namespace helpers

#endif  // PARTICLEFILTER_SRC_HELPERS_H_
