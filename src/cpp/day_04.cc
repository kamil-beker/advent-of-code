#include "day_04.h"

#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>

namespace aoc2022 {
namespace day04 {

std::vector<std::int32_t> GenRangeFromString(std::string range_as_string) {
  const auto split_on = [](std::string str, char split_on) {
    std::stringstream sstr(str);
    std::string segment;
    std::vector<std::string> tokens;

    while (std::getline(sstr, segment, split_on)) {
      tokens.push_back(segment);
    };

    return tokens;
  };

  const auto tokens = split_on(range_as_string, '-');
  std::vector<std::int32_t> range;

  const std::int32_t from = std::stoi(tokens.at(0));
  const std::int32_t to = std::stoi(tokens.at(1));

  for (std::int32_t i = from; i <= to; i++) {
    range.push_back(i);
  }

  return range;
}

bool IsFullyContainedPair(std::pair<std::string, std::string> assignment_pair) {
  bool is_included = false;

  const auto first_range_string = assignment_pair.first;
  const auto second_range_string = assignment_pair.second;

  const auto first_range = GenRangeFromString(first_range_string);
  const auto second_range = GenRangeFromString(second_range_string);

  if (std::includes(first_range.begin(), first_range.end(),
                    second_range.begin(), second_range.end()) ||
      std::includes(second_range.begin(), second_range.end(),
                    first_range.begin(), first_range.end())) {
    is_included = true;
  }

  return is_included;
}

bool IsSemiContainedPair(std::pair<std::string, std::string> assignment_pair) {
  bool is_included = false;

  const auto first_range_string = assignment_pair.first;
  const auto second_range_string = assignment_pair.second;

  const auto first_range = GenRangeFromString(first_range_string);
  const auto second_range = GenRangeFromString(second_range_string);

  std::vector<std::int32_t> intersection;

  std::set_intersection(first_range.begin(), first_range.end(),
                        second_range.begin(), second_range.end(),
                        std::back_inserter(intersection));

  is_included = !intersection.empty();

  return is_included;
}

std::int64_t Part01(
    const std::vector<std::pair<std::string, std::string>>& data) {
  const auto total_fully_contained_pairs = std::count_if(
      data.begin(), data.end(),
      [](std::pair<std::string, std::string> assignment_pair) {
        const auto pair_value = IsFullyContainedPair(assignment_pair);

        return pair_value;
      });

  return total_fully_contained_pairs;
}

std::int64_t Part02(
    const std::vector<std::pair<std::string, std::string>>& data) {
  const auto total_semi_contained_pairs = std::count_if(
      data.begin(), data.end(),
      [](std::pair<std::string, std::string> assignment_pair) {
        const bool pair_value = IsSemiContainedPair(assignment_pair);

        return pair_value;
      });

  return total_semi_contained_pairs;
}

}  // namespace day04
}  // namespace aoc2022
