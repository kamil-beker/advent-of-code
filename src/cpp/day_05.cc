#include "day_05.h"

#include <queue>
#include <string>

namespace aoc2022 {
namespace day05 {

std::string Part01(std::vector<std::stack<char>> crate_data,
                   std::vector<std::vector<std::int32_t>> move_data) {
  std::string result;

  for (const auto& crate_move : move_data) {
    auto move_count = crate_move.at(0);

    const auto move_from = crate_move.at(1);
    const auto move_to = crate_move.at(2);

    while (move_count != 0) {
      const auto crate_to_move = crate_data.at(move_from).top();
      crate_data.at(move_from).pop();
      crate_data.at(move_to).push(crate_to_move);
      move_count--;
    }
  }

  for (const auto& crate : crate_data) {
    if (!crate.empty()) {
      result += crate.top();
    }
  }

  return result;
}

std::string Part02(std::vector<std::stack<char>> crate_data,
                   std::vector<std::vector<std::int32_t>> move_data) {
  std::string result;

  for (const auto& crate_move : move_data) {
    std::stack<char> char_stack;
    auto move_count = crate_move.at(0);

    const auto move_from = crate_move.at(1);
    const auto move_to = crate_move.at(2);

    while (move_count != 0) {
      const auto crate_to_move = crate_data.at(move_from).top();

      crate_data.at(move_from).pop();
      char_stack.push(crate_to_move);
      move_count--;
    }

    while (!char_stack.empty()) {
      const auto crate_to_move = char_stack.top();

      char_stack.pop();
      crate_data.at(move_to).push(crate_to_move);
    }
  }

  for (const auto& crate : crate_data) {
    if (!crate.empty()) {
      result += crate.top();
    }
  }

  return result;
}

}  // namespace day05
}  // namespace aoc2022
