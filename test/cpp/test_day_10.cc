#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_10.h"

using ::testing::Test;

namespace {
struct Day10Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day10Test, Part01TestExample) {
  const auto input = helpers::GetProgramDataFromFile("data/10-test.txt");
  ASSERT_EQ(aoc2022::day10::Part01(input), 13140);
}

TEST_F(Day10Test, Part01RealExample) {
  const auto input = helpers::GetProgramDataFromFile("data/10.txt");
  ASSERT_EQ(aoc2022::day10::Part01(input), 15260);
}

TEST_F(Day10Test, Part02TestExample) {
  const auto input = helpers::GetProgramDataFromFile("data/10-test.txt");
  ASSERT_EQ(aoc2022::day10::Part02(input), 0);
}

TEST_F(Day10Test, Part02RealExample) {
  const auto input = helpers::GetProgramDataFromFile("data/10.txt");
  ASSERT_EQ(aoc2022::day10::Part02(input), 0);
}

}  // namespace
