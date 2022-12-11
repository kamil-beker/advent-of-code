#include "day_10.h"

#include <array>
#include <iostream>
#include <map>

namespace aoc2022 {
namespace day10 {

std::int64_t Part01(
    const std::vector<std::pair<std::string, std::int32_t>>& data) {
  std::map<char, std::int32_t> cpu = {{'X', 1}};
  std::vector<std::int32_t> signal_strenght_history;

  std::int32_t cycle = 0;
  signal_strenght_history.push_back(cycle * cpu['X']);

  for (const auto& instruction_pair : data) {
    const auto instruction = instruction_pair.first;
    const auto instruction_value = instruction_pair.second;

    if (instruction != "noop") {
      std::int32_t addx_cycle_count = 2;

      while (addx_cycle_count != 1) {
        --addx_cycle_count;
        cycle++;
        signal_strenght_history.push_back(cycle * cpu['X']);
      }
      cycle++;
      signal_strenght_history.push_back(cycle * cpu['X']);
      cpu['X'] += instruction_value;

    } else {
      cycle++;
      signal_strenght_history.push_back(cycle * cpu['X']);
    }
  }

  const std::vector<std::int32_t> cycle_indexes = {20, 60, 100, 140, 180, 220};

  std::int32_t result = 0;
  for (const auto cycle_index : cycle_indexes) {
    result += signal_strenght_history[cycle_index];
  }

  return result;
}

std::int64_t Part02(
    const std::vector<std::pair<std::string, std::int32_t>>& data) {
  std::map<char, std::int32_t> cpu = {{'X', 1}};
  std::array<std::string, 7> crt;
  std::string sprite_position(40, '.');
  std::int32_t cycle = 0;

  for (auto i = 0; i < 6; ++i) {
    crt[i] = std::string(40, '.');
  }

  const auto update_sprite_position = [&]() {
    std::int32_t x = cpu['X'];
    std::string new_sprite_position(40, '.');

    for (auto i = x - 1; i <= x + 1; ++i) {
      new_sprite_position[i] = '#';
    }

    sprite_position = new_sprite_position;
  };

  const auto update_crt = [&]() {
    std::int32_t row = cycle / 40;
    std::int32_t column = cycle % 40;

    crt[row][column] = sprite_position[column];
  };

  for (const auto& instruction_pair : data) {
    const auto instruction = instruction_pair.first;
    const auto instruction_value = instruction_pair.second;

    update_sprite_position();
    update_crt();
    if (instruction != "noop") {
      std::int32_t addx_cycle_count = 2;

      while (addx_cycle_count != 1) {
        --addx_cycle_count;
        cycle++;
        update_sprite_position();
        update_crt();
      }
      cycle++;
      cpu['X'] += instruction_value;
      update_sprite_position();
      update_crt();

    } else {
      cycle++;
      update_sprite_position();
      update_crt();
    }
  }

  for (const auto& it : crt) {
    std::cout << it << std::endl;
  }

  return 0;
}

}  // namespace day10
}  // namespace aoc2022
