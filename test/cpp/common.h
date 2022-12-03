#ifndef TEST_CPP_COMMON_H
#define TEST_CPP_COMMON_H

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace helpers {

inline std::vector<std::vector<int32_t>> GetSplittedValuesFromFile(
    const char* path) {
  std::ifstream infile(path);
  std::string line;

  std::vector<std::vector<std::int32_t>> values_container;
  std::vector<std::int32_t> values;

  while (std::getline(infile, line)) {
    if (!line.empty()) {
      std::int32_t val = std::stoi(line);
      values.push_back(val);
    } else {
      values_container.push_back(values);
      values.clear();
    }
  }

  // push leftovers
  if (!values.empty()) {
    values_container.push_back(values);
  }
  return values_container;
}

inline std::vector<std::pair<std::string, std::string>>
GetStrategyGuideFromFile(const char* path) {
  std::ifstream infile(path);
  std::string line;
  std::vector<std::pair<std::string, std::string>> strategies;

  while (std::getline(infile, line)) {
    std::istringstream iss(line);
    std::string player_a_move;
    std::string player_b_move;
    std::pair<std::string, std::string> strategy;

    iss >> player_a_move;
    iss >> player_b_move;

    strategy = std::make_pair(player_a_move, player_b_move);

    strategies.push_back(strategy);
  }

  return strategies;
}

inline std::vector<std::pair<std::string, std::string>> GetRucksacksFromFile(
    const char* path) {
  std::ifstream infile(path);
  std::string line;
  std::vector<std::pair<std::string, std::string>> rucksacks;

  while (std::getline(infile, line)) {
    std::pair<std::string, std::string> compartments;
    const auto size = line.size();
    std::string first_compartment = line.substr(0, size / 2);
    std::string second_compartment = line.substr((size / 2), size);

    compartments = std::make_pair(first_compartment, second_compartment);

    rucksacks.push_back(compartments);
  }

  return rucksacks;
}

inline std::vector<std::vector<std::string>> GetRucksackGroupsFromFile(
    const char* path) {
  std::ifstream infile(path);
  std::string line;

  std::vector<std::vector<std::string>> groups;
  std::vector<std::string> group;
  auto index = 0;

  while (std::getline(infile, line)) {
    if ((index % 3 == 0) && (index != 0)) {
      groups.push_back(group);
      group.clear();
    }

    group.push_back(line);
    index++;
  }

  if (!group.empty()) {
    groups.push_back(group);
  }

  return groups;
}

}  // namespace helpers

#endif  // TEST_CPP_COMMON_H
