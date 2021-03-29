#include "helpers.h"

#include <array>
#include <cmath>
#include <random>
#include <vector>

std::vector<helpers::Position> helpers::GenerateSamples(
    size_t size, double gps_x, double gps_y, double theta, double std_x,
    double std_y, double std_theta) {
  {
    std::default_random_engine gen;
    std::normal_distribution<double> dist_x(gps_x, std_x);
    std::normal_distribution<double> dist_y(gps_y, std_y);
    std::normal_distribution<double> dist_theta(theta, std_theta);
    std::vector<Position> samples;
    samples.reserve(size);
    for (int i = 0; i < size; ++i)
      samples.emplace_back(Position{dist_x(gen), dist_y(gen), dist_theta(gen)});
    return samples;
  }
}

helpers::Position helpers::ToMap(helpers::Position particle,
                                 helpers::Position observation) {
  return helpers::Position{particle.x + observation.x * cos(particle.theta) -
                               observation.y * sin(particle.theta),
                           particle.y + observation.x * sin(particle.theta) +
                               observation.y * cos(particle.theta)};
}
double helpers::NormPDF(double x, double y, double mu_x, double mu_y,
                        double std_x, double std_y) {
  auto distance = [](const auto& value, const auto& mu, const auto& std) {
    return pow(value - mu, 2) / 2 / pow(std, 2);
  };
  return exp(-(distance(x, mu_x, std_x) + distance(y, mu_y, std_y))) / 2 /
         M_PI / std_x / std_y;
}
