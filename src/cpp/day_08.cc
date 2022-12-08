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
      std::vector<bool> visibility;
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

      visibility.push_back(is_visible_from_left);
      visibility.push_back(is_visible_from_right);
      visibility.push_back(is_visible_from_top);
      visibility.push_back(is_visible_from_bottom);

      const bool check = std::any_of(visibility.begin(), visibility.end(),
                                     [](const bool b) { return b; });

      result += check;
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
      std::vector<std::int32_t> distances;
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

      distances.push_back(left_distance);
      distances.push_back(right_distance);
      distances.push_back(up_distance);
      distances.push_back(down_distance);

      distances.erase(std::remove(distances.begin(), distances.end(), 0),
                      distances.end());

      const auto scenic_score = std::accumulate(
          distances.begin(), distances.end(), 1,
          [](std::int32_t acc, std::int32_t score) { return acc * score; });

      scenic_scores.push_back(scenic_score);
    }

    std::nth_element(scenic_scores.begin(), scenic_scores.begin() + 1,
                     scenic_scores.end(), std::greater<int>());
  }

  return scenic_scores.at(0);
}

}  // namespace day08
}  // namespace aoc2022
