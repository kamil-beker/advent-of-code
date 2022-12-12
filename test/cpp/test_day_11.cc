#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_11.h"

using ::testing::Test;

namespace {
struct Day11Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day11Test, Part01TestExample) {
  const auto input = helpers::GetMonkeyRawDataFromFile("data/11-test.txt");
  ASSERT_EQ(aoc2022::day11::Part01(input, 20), 10605);
}

TEST_F(Day11Test, Part01RealExample) {
  const auto input = helpers::GetMonkeyRawDataFromFile("data/11.txt");
  ASSERT_EQ(aoc2022::day11::Part01(input, 10000), 14396280220);
}

TEST_F(Day11Test, Part02TestExample) {
  const auto input = helpers::GetMonkeyRawDataFromFile("data/11-test.txt");
  ASSERT_EQ(aoc2022::day11::Part02(input, 10000), 2713310158);
}

TEST_F(Day11Test, Part02RealExample) {
  const auto input = helpers::GetMonkeyRawDataFromFile("data/11.txt");
  ASSERT_EQ(aoc2022::day11::Part02(input, 10000), 11741456163);
}

}  // namespace
