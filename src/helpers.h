#ifndef PARTICLEFILTER_SRC_HELPERS_H_
#define PARTICLEFILTER_SRC_HELPERS_H_

#include <optional>
#include <ostream>
#include <vector>

namespace helpers {

struct Position {
  double x;
  double y;
  double theta;
  bool operator==(const Position& rhs) const {
    if (isnan(theta) && isnan(rhs.theta))
      return std::tie(x, y) == std::tie(rhs.x, rhs.y);
    if (!isnan(theta) && !isnan(rhs.theta))
      return std::tie(x, y, theta) == std::tie(rhs.x, rhs.y, rhs.theta);
    return false;
  }
  bool operator!=(const Position& rhs) const { return !(rhs == *this); }
  Position(double x, double y, double theta) : x{x}, y{y}, theta{theta} {};
  Position(double x, double y)
      : x{x}, y{y}, theta{std::numeric_limits<double>::quiet_NaN()} {};
  friend std::ostream& operator<<(std::ostream& os, const Position& position) {
    os << "x: " << position.x << " y: " << position.y
       << " theta: " << position.theta;
    return os;
  }
};

std::vector<Position> GenerateSamples(size_t size, double gps_x, double gps_y,
                                      double theta, double std_x, double std_y,
                                      double std_theta);

Position ToMap(Position particle, Position observation);

}  // namespace helpers

#endif  // PARTICLEFILTER_SRC_HELPERS_H_
