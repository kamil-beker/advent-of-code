#include "day_09.h"

#include <array>
#include <cmath>
#include <iostream>
#include <set>

namespace aoc2022 {
namespace day09 {

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
  std::set<std::pair<std::int32_t, std::int32_t>> path;

  std::int64_t x_coordinate = 0;
  std::int64_t y_coordinate = 0;
  std::int64_t x_tail_coordinate = 0;
  std::int64_t y_tail_coordinate = 0;

  const auto update_tail_coordinates = [&]() {
    struct {
      int dx;
      int dy;
    } vertical_directions[] = {{0, -2}, {-2, 0}, {0, 2}, {2, 0}};

    struct {
      int dx;
      int dy;
    } diagonal_directions[] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                               {1, 2},   {2, 1},   {2, -1}, {1, -2}};

    // check vertical
    for (auto i = 0; i < 4; ++i) {
      std::int64_t temp_x = x_tail_coordinate + vertical_directions[i].dx;
      std::int64_t temp_y = y_tail_coordinate + vertical_directions[i].dy;

      if (temp_x == x_coordinate && temp_y == y_coordinate) {
        if (temp_x < x_tail_coordinate) {
          x_tail_coordinate -= 1;
        }
        if (temp_x > x_tail_coordinate) {
          x_tail_coordinate += 1;
        }
        if (temp_y > y_tail_coordinate) {
          y_tail_coordinate += 1;
        }
        if (temp_y < y_tail_coordinate) {
          y_tail_coordinate -= 1;
        }
      }
    }

    // check for diagonal
    for (auto i = 0; i < 8; i++) {
      std::int64_t temp_x = x_tail_coordinate + diagonal_directions[i].dx;
      std::int64_t temp_y = y_tail_coordinate + diagonal_directions[i].dy;
      if (temp_x == x_coordinate && temp_y == y_coordinate) {
        if (temp_x < x_tail_coordinate && temp_y > y_tail_coordinate) {
          x_tail_coordinate -= 1;
          y_tail_coordinate += 1;
        }
        if (temp_x > x_tail_coordinate && temp_y > y_tail_coordinate) {
          x_tail_coordinate += 1;
          y_tail_coordinate += 1;
        }
        if (temp_x > x_tail_coordinate && temp_y < y_tail_coordinate) {
          x_tail_coordinate += 1;
          y_tail_coordinate -= 1;
        }
        if (temp_x < x_tail_coordinate && temp_y < y_tail_coordinate) {
          x_tail_coordinate -= 1;
          y_tail_coordinate -= 1;
        }
      }
    }
  };

  auto it = data.begin();
  while (it != data.end()) {
    const auto direction = it->first;
    const auto steps = it->second;
    const auto move = ConvertDirectionAndSteps(direction, steps);
    const auto move_x = move.second;
    const auto move_y = move.first;

    if (move_x == 0) {
      for (auto i = 0; i < std::abs(move_y); ++i) {
        std::pair<std::int32_t, std::int32_t> move;
        if (!std::signbit(move_y)) {
          y_coordinate += 1;
        } else {
          y_coordinate -= 1;
        }
        update_tail_coordinates();
        move = std::make_pair(x_tail_coordinate, y_tail_coordinate);
        path.insert(move);
      }
    } else {
      for (auto i = 0; i < std::abs(move_x); ++i) {
        std::pair<std::int32_t, std::int32_t> move;
        if (!std::signbit(move_x)) {
          x_coordinate += 1;
        } else {
          x_coordinate -= 1;
        }
        update_tail_coordinates();
        move = std::make_pair(x_tail_coordinate, y_tail_coordinate);
        path.insert(move);
      }
    }

    ++it;
  }

  return path.size();
}

std::int64_t Part02(const std::vector<std::pair<char, std::int32_t>>& data) {
  (void)data;
  return 0;
}

}  // namespace day09
}  // namespace aoc2022
