#include "day_09.h"

#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <set>

namespace aoc2022 {
namespace day09 {

int sgn(int val) {
  return (val > 0) - (val < 0);
}

std::pair<std::int32_t, std::int32_t> ConvertDirectionAndSteps(
    char direction,
    std::int32_t steps) {
  std::pair<std::int64_t, std::int64_t> result;
  switch (direction) {
    case 'R':
      result = std::make_pair(0, steps);
      break;
    case 'L':
      result = std::make_pair(0, -steps);
      break;
    case 'U':
      result = std::make_pair(steps, 0);
      break;
    case 'D':
      result = std::make_pair(-steps, 0);
      break;
    default:
      static_cast<void>(steps);
      result = std::make_pair(0, 0);
      break;
  }

  return result;
};

std::int64_t Part01(const std::vector<std::pair<char, std::int32_t>>& data) {
  std::pair<std::int32_t, std::int32_t> head{0, 0};
  std::pair<std::int32_t, std::int32_t> tail{0, 0};

  std::set<std::pair<std::int32_t, std::int32_t>> set;
  std::map<char, std::pair<std::int32_t, std::int32_t>> dir_map = {
      {'U', {0, 1}},
      {'D', {0, -1}},
      {'L', {-1, 0}},
      {'R', {1, 0}},
  };

  const auto add_pair = [](std::pair<std::int32_t, std::int32_t> p_1,
                           std::pair<std::int32_t, std::int32_t> p_2) {
    std::pair<std::int32_t, std::int32_t> p_sum{p_1.first + p_2.first,
                                                p_1.second + p_2.second};

    return p_sum;
  };

  set.insert(tail);

  for (auto it = data.begin(); it != data.end(); ++it) {
    const auto direction = it->first;
    const auto steps = it->second;

    auto x = dir_map[direction];
    for (auto i = 0; i < steps; i++) {
      head = add_pair(head, x);
      const auto dx = head.first - tail.first;
      const auto dy = head.second - tail.second;

      if (std::abs(dx) > 1 || std::abs(dy) > 1) {
        std::pair<std::int32_t, std::int32_t> dxy_1{sgn(dx), sgn(dy)};
        tail = add_pair(tail, dxy_1);
        set.insert(tail);
      }
    }
  }

  return set.size();
}

std::int64_t Part02(const std::vector<std::pair<char, std::int32_t>>& data) {
  (void)data;
  return 0;
}

}  // namespace day09
}  // namespace aoc2022
