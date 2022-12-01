#include "day_01.h"

#include <functional>
#include <numeric>

namespace aoc2022 {
namespace day01 {

std::int64_t Part01(std::vector<std::vector<std::int32_t>> data) {
  std::int64_t max = 0;

  for (const auto& i : data) {
    auto current = std::accumulate(i.begin(), i.end(), 0);
    if (current > max) {
      max = current;
    }
  }

  return max;
}

std::int64_t Part02(std::vector<std::vector<std::int32_t>> data) {
  std::int64_t acc_sum = 0;
  std::vector<std::int32_t> sums;

  for (const auto& i : data) {
    const std::int32_t sum = std::accumulate(i.begin(), i.end(), 0);
    sums.push_back(sum);
  }

  std::sort(sums.begin(), sums.end(), std::greater<std::int32_t>());
  acc_sum = std::accumulate(sums.begin(), sums.begin() + 3, 0);

  return acc_sum;
}

}  // namespace day01
}  // namespace aoc2022
