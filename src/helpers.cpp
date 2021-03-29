#include "helpers.h"

#include <array>
#include <random>
#include <vector>

std::vector<helpers::Sample> helpers::GenerateSamples(
    size_t size, double gps_x, double gps_y, double theta, double std_x,
    double std_y, double std_theta) {
  {
    std::default_random_engine gen;
    std::normal_distribution<double> dist_x(gps_x, std_x);
    std::normal_distribution<double> dist_y(gps_y, std_y);
    std::normal_distribution<double> dist_theta(theta, std_theta);
    std::vector<Sample> samples;
    samples.reserve(size);
    for (int i = 0; i < size; ++i)
      samples.emplace_back(Sample{dist_x(gen), dist_y(gen), dist_theta(gen)});
    return samples;
  }
}