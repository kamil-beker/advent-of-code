#include "day_06.h"

#include <set>

namespace aoc2022 {
namespace day06 {

std::int64_t Part01(const std::string& data) {
  std::int64_t first_marker_after = 0;

  for (size_t i = 0; i < data.size() - 3; i++) {
    auto sub_str = data.substr(i, 4);
    std::set<char> char_set(sub_str.begin(), sub_str.end());

    if (char_set.size() == 4) {
      first_marker_after = i + 4;
      break;
    }
  }

  return first_marker_after;
}

std::int64_t Part02(const std::string& data) {
  std::int64_t first_marker_after = 0;

  for (size_t i = 0; i < data.size() - 15; i++) {
    auto sub_str = data.substr(i, 14);
    std::set<char> char_set(sub_str.begin(), sub_str.end());

    if (char_set.size() == 14) {
      first_marker_after = i + 14;
      break;
    }
  }

  return first_marker_after;
}

}  // namespace day06
}  // namespace aoc2022
