#include "day_02.h"

#include <map>
#include <numeric>
#include <string>
#include <vector>

namespace aoc2022 {
namespace day02 {

namespace {
constexpr auto kWinValue = 6;
constexpr auto kDrawValue = 3;
constexpr auto kLooseValue = 0;
constexpr auto kRockValue = 1;
constexpr auto kPaperValue = 2;
constexpr auto kScissorsValue = 3;

const std::map<std::string, std::string> win_map = {
    {"A", "Y"},
    {"B", "Z"},
    {"C", "X"},
};

const std::map<std::string, std::string> draw_map = {
    {"A", "X"},
    {"B", "Y"},
    {"C", "Z"},
};

const std::map<std::string, std::int32_t> figure_value_map = {
    {{"X", kRockValue}, {"Y", kPaperValue}, {"Z", kScissorsValue}}};

}  // namespace

std::int64_t EvaluateStrategy(std::string player_a, std::string player_b) {
  std::int64_t value = kLooseValue;

  if (win_map.at(player_a) == player_b) {
    value = kWinValue;
  }

  if (draw_map.at(player_a) == player_b) {
    value = kDrawValue;
  }

  return value;
}

std::int64_t EvaluateStrategyAsIndicated(std::string player_a,
                                         std::string player_b) {
  const std::vector<std::string> player_move_set = {"X", "Y", "Z"};
  std::int64_t value = 0;

  const auto find_indicated_value =
      [&](std::int64_t indicated_value) -> std::int64_t {
    std::int64_t result = 0;

    for (const auto& player_move : player_move_set) {
      auto evaluated_value = EvaluateStrategy(player_a, player_move);

      if (evaluated_value == indicated_value) {
        result = indicated_value + figure_value_map.at(player_move);
        break;
      }
    }

    return result;
  };

  if (player_b == "X" /* loose */) {
    value = find_indicated_value(kLooseValue);
  }

  if (player_b == "Y" /* draw */) {
    value = find_indicated_value(kDrawValue);
  }

  if (player_b == "Z" /* win */) {
    value = find_indicated_value(kWinValue);
  }

  return value;
}

std::int64_t Part01(
    const std::vector<std::pair<std::string, std::string>>& data) {
  const auto total_points = std::accumulate(
      data.begin(), data.end(), 0,
      [](std::int64_t acc, std::pair<std::string, std::string> strategy) {
        const auto strategy_value =
            EvaluateStrategy(strategy.first, strategy.second);
        const auto shape_value = figure_value_map.at(strategy.second);
        return acc + strategy_value + shape_value;
      });

  return total_points;
}
std::int64_t Part02(
    const std::vector<std::pair<std::string, std::string>>& data) {
  const auto total_points = std::accumulate(
      data.begin(), data.end(), 0,
      [](std::int64_t acc, std::pair<std::string, std::string> strategy) {
        const auto strategy_value =
            EvaluateStrategyAsIndicated(strategy.first, strategy.second);
        return acc + strategy_value;
      });

  return total_points;
}

}  // namespace day02
}  // namespace aoc2022
