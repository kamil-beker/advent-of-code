#ifndef TEST_CPP_COMMON_H
#define TEST_CPP_COMMON_H

#include <cstdint>
#include <fstream>
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

}  // namespace helpers

#endif  // TEST_CPP_COMMON_H
