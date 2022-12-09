#ifndef TEST_CPP_COMMON_H
#define TEST_CPP_COMMON_H

#include <ctype.h>
#include <algorithm>
#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace helpers {

inline std::vector<std::string> SplitOn(std::string str, char split_on) {
  std::stringstream sstr(str);
  std::string segment;
  std::vector<std::string> tokens;

  while (std::getline(sstr, segment, split_on)) {
    tokens.push_back(segment);
  };

  return tokens;
}

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

inline std::vector<std::pair<std::string, std::string>>
GetSectionAssignmentsFromFile(const char* path) {
  std::ifstream infile(path);
  std::string line;

  std::vector<std::pair<std::string, std::string>> section_assignment_pairs;

  while (std::getline(infile, line)) {
    std::pair<std::string, std::string> assignment_pair;
    const auto tokens = SplitOn(line, ',');

    const auto first_section = tokens.at(0);
    const auto second_section = tokens.at(1);

    assignment_pair = std::make_pair(first_section, second_section);

    section_assignment_pairs.push_back(assignment_pair);
  }

  return section_assignment_pairs;
}

inline std::vector<std::vector<std::string>> GetCargoInputFromFile(
    const char* path) {
  std::ifstream infile(path);
  std::string line;
  std::vector<std::vector<std::string>> cargo_input;
  std::vector<std::string> crate_lines;

  // crates
  while (std::getline(infile, line) && !line.empty()) {
    if (!line.empty() || line != "\n") {
      crate_lines.push_back(line);
    }
  }

  cargo_input.push_back(crate_lines);
  crate_lines.clear();

  // move set
  while (std::getline(infile, line) && !line.empty()) {
    if (!line.empty()) {
      crate_lines.push_back(line);
    }
  }

  cargo_input.push_back(crate_lines);
  crate_lines.clear();

  return cargo_input;
}

inline std::vector<std::stack<char>> GetCrates(
    std::vector<std::string> crate_lines) {
  std::vector<std::stack<char>> crates;

  crates.resize(32);

  const auto crate_indices_str = crate_lines.back();
  std::vector<std::int32_t> crate_indices;

  for (size_t i = 0; i < crate_indices_str.size(); i++) {
    const auto current_element = crate_indices_str[i];
    if (std::isdigit(current_element)) {
      crate_indices.push_back(i);
    }
  }

  crate_lines.pop_back();
  for (auto it = crate_lines.end() - 1; it != crate_lines.begin() - 1; it--) {
    const auto current_element = *it;
    for (size_t i = 0; i < crate_indices.size(); i++) {
      const auto crate_index = crate_indices[i];
      const auto crate_char = current_element[crate_index];
      if (crate_char != ' ') {
        crates.at(i + 1).push(crate_char);
      }
    }
  }

  return crates;
}

inline std::vector<std::vector<std::int32_t>> GetCargoRearrangementProcedure(
    std::vector<std::string> move_lines) {
  std::vector<std::vector<std::int32_t>> procedures;

  for (const auto& move_line : move_lines) {
    std::vector<std::int32_t> procedure;
    const auto tokens = SplitOn(move_line, ' ');
    for (size_t i = 1; i < tokens.size(); i += 2) {
      const auto value = std::stoi(tokens[i]);
      procedure.push_back(value);
    }

    procedures.push_back(procedure);
  }

  return procedures;
}

inline std::string GetPacketFromFile(const char* path) {
  std::ifstream infile(path);
  std::string line;

  std::getline(infile, line);

  return line;
}

inline std::vector<std::string> GetTerminalOutput(const char* path) {
  std::ifstream infile(path);
  std::string line;
  std::vector<std::string> output;

  while (std::getline(infile, line)) {
    output.push_back(line);
  }

  return output;
}

inline std::vector<std::vector<std::int32_t>> GetTreesFromFile(
    const char* path) {
  std::ifstream infile(path);
  std::string line;
  std::vector<std::vector<std::int32_t>> trees;

  trees.resize(256);

  size_t index = 0;
  while (std::getline(infile, line)) {
    for (auto ch : line) {
      const std::int32_t height = static_cast<int>(ch) - 48;
      trees.at(index).push_back(height);
    }
    ++index;
  }

  trees.resize(index);

  return trees;
}

inline std::vector<std::pair<char, std::int32_t>> GetSeriesOfMotionsFromFIle(
    const char* path) {
  std::ifstream infile(path);
  std::string line;
  std::vector<std::pair<char, std::int32_t>> motions;

  while (std::getline(infile, line)) {
    std::pair<char, std::int32_t> motion;
    std::istringstream iss(line);
    std::string direction_str;
    std::string steps_str;

    iss >> direction_str;
    iss >> steps_str;

    const char direction = direction_str[0];
    const std::int32_t steps = std::stoi(steps_str);

    motion = std::make_pair(direction, steps);

    motions.push_back(motion);
  }

  return motions;
}

}  // namespace helpers

#endif  // TEST_CPP_COMMON_H
