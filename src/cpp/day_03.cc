#include "day_03.h"
#include <numeric>

namespace aoc2022 {
namespace day03 {

namespace {
constexpr auto kAsciiZeroValue = 48;
constexpr auto kLowerCharModifier = 48;
constexpr auto kUpperCharModifier = 10;

}  // namespace
std::int64_t CharToPriority(char ch) {
  auto priority = static_cast<int>(ch) - kAsciiZeroValue;

  if (std::islower(ch)) {
    priority -= kLowerCharModifier;
  } else {
    priority += kUpperCharModifier;
  }

  return priority;
}

std::string GetIntersection(std::string first_compartment,
                            std::string second_compartment) {
  std::sort(first_compartment.begin(), first_compartment.end());
  std::sort(second_compartment.begin(), second_compartment.end());

  std::string compartment_intersection;

  std::set_intersection(first_compartment.begin(), first_compartment.end(),
                        second_compartment.begin(), second_compartment.end(),
                        std::back_inserter(compartment_intersection));

  std::string s(compartment_intersection.begin(),
                compartment_intersection.end());

  return s;
}

std::int64_t CountRucksackPriority(std::string first_compartment,
                                   std::string second_compartment) {
  std::string compartment_intersection =
      GetIntersection(first_compartment, second_compartment);

  const auto common_element = compartment_intersection.at(0);
  const auto priority = CharToPriority(common_element);

  return priority;
}

std::int64_t CountGroupPriority(std::vector<std::string> group) {
  auto first_compartment = group.at(0);
  auto second_compartment = group.at(1);
  auto third_compartment = group.at(2);

  auto first_intersecton =
      GetIntersection(first_compartment, second_compartment);
  auto second_intersection =
      GetIntersection(second_compartment, third_compartment);
  auto group_intersection =
      GetIntersection(first_intersecton, second_intersection);

  const auto common_element = group_intersection.at(0);
  const auto priority = CharToPriority(common_element);

  return priority;
}

std::int64_t Part01(
    const std::vector<std::pair<std::string, std::string>>& data) {
  const auto total_priority = std::accumulate(
      data.begin(), data.end(), 0,
      [](std::int64_t acc, std::pair<std::string, std::string> compartment) {
        const auto priority_value =
            CountRucksackPriority(compartment.first, compartment.second);

        return acc + priority_value;
      });

  return total_priority;
}
std::int64_t Part02(const std::vector<std::vector<std::string>>& data) {
  const auto total_priority =
      std::accumulate(data.begin(), data.end(), 0,
                      [](std::int64_t acc, std::vector<std::string> group) {
                        const auto priority_value = CountGroupPriority(group);

                        return acc + priority_value;
                      });

  return total_priority;
}

}  // namespace day03
}  // namespace aoc2022
