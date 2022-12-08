#include "day_08.h"

#include <functional>
#include <numeric>
#include <vector>

namespace aoc2022 {
namespace day08 {

std::int64_t Part01(const std::vector<std::vector<std::int32_t>>& data) {
  std::int64_t result = 0;

  const std::int32_t rows_size = data.size();
  const std::int32_t columns_size = data.at(0).size();

  for (auto i = 1; i < rows_size - 1; ++i) {
    for (auto j = 1; j < columns_size - 1; ++j) {
      const auto current_tree = data[i][j];

      const auto horizontal_visibility = [&](std::int32_t from, std::int32_t to,
                                             std::int32_t modifier) {
        bool is_visible = false;
        while (from != to) {
          from += modifier;
          is_visible = current_tree > data[i][from];
          if (!is_visible) {
            break;
          }
        }
        return is_visible;
      };

      const auto vertical_visibility = [&](std::int32_t from, std::int32_t to,
                                           std::int32_t modifier) {
        bool is_visible = false;
        while (from != to) {
          from += modifier;
          is_visible = current_tree > data[from][j];
          if (!is_visible) {
            break;
          }
        }
        return is_visible;
      };

      const bool is_visible_from_left = horizontal_visibility(j, 0, -1);
      const bool is_visible_from_right =
          horizontal_visibility(j, columns_size - 1, 1);
      const bool is_visible_from_top = vertical_visibility(i, 0, -1);
      const bool is_visible_from_bottom =
          vertical_visibility(i, rows_size - 1, 1);

      result += (is_visible_from_left || is_visible_from_right ||
                 is_visible_from_top || is_visible_from_bottom);
    }
  }

  result += (2 * rows_size + 2 * columns_size) - 4;

  return result;
}

std::int64_t Part02(const std::vector<std::vector<std::int32_t>>& data) {
  std::vector<std::int64_t> scenic_scores;

  const std::int32_t rows_size = data.size();
  const std::int32_t columns_size = data.at(0).size();

  for (auto i = 1; i < rows_size - 1; ++i) {
    for (auto j = 1; j < columns_size - 1; ++j) {
      const auto current_tree = data[i][j];

      const auto horizontal_distance = [&](std::int32_t from, std::int32_t to,
                                           std::int32_t modifier) {
        std::int32_t distance = 0;
        while (from != to) {
          from += modifier;
          if (current_tree > data[i][from]) {
            distance += 1;
          } else {
            distance += 1;
            break;
          }
        }
        return distance;
      };

      const auto vertical_distance = [&](std::int32_t from, std::int32_t to,
                                         std::int32_t modifier) {
        std::int32_t distance = 0;
        while (from != to) {
          from += modifier;
          if (current_tree > data[from][j]) {
            distance += 1;
          } else {
            distance += 1;
            break;
          }
        }
        return distance;
      };

      // go left
      const auto left_distance = horizontal_distance(j, 0, -1);
      const auto right_distance = horizontal_distance(j, columns_size - 1, 1);
      const auto up_distance = vertical_distance(i, 0, -1);
      const auto down_distance = vertical_distance(i, rows_size - 1, 1);

      scenic_scores.push_back(left_distance * right_distance * up_distance *
                              down_distance);
    }

    std::nth_element(scenic_scores.begin(), scenic_scores.begin() + 1,
                     scenic_scores.end(), std::greater<int>());
  }

  return scenic_scores.at(0);
}

}  // namespace day08
}  // namespace aoc2022
