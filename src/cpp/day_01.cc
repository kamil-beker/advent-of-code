#include "day_01.h"

#include <algorithm>
#include <functional>
#include <numeric>

namespace aoc2022 {
namespace day01 {

std::int64_t Part01(const std::vector<std::vector<std::int32_t>>& data) {
  std::int64_t max = 0;

  for (const auto& i : data) {
    auto current = std::accumulate(i.begin(), i.end(), 0);
    if (current > max) {
      max = current;
    }
  }

  return max;
}

std::int64_t Part02(const std::vector<std::vector<std::int32_t>>& data) {
  std::int64_t max = 0;
  std::vector<std::int32_t> sums;

  for (const auto& i : data) {
    auto sum = std::accumulate(i.begin(), i.end(), 0);
    sums.push_back(sum);
  }

  std::nth_element(sums.begin(), sums.begin() + 3, sums.end(),
                   std::greater<std::int32_t>());

  max = std::accumulate(sums.begin(), sums.begin() + 3, 0);

  return max;
}

}  // namespace day01
}  // namespace aoc2022
