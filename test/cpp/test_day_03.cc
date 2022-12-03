#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_03.h"

using ::testing::Test;

namespace {
struct Day03Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day03Test, Part01TestExample) {
  const auto input = helpers::GetRucksacksFromFile("data/03-test.txt");
  ASSERT_EQ(aoc2022::day03::Part01(input), 157);
}

TEST_F(Day03Test, Part01RealExample) {
  const auto input = helpers::GetRucksacksFromFile("data/03.txt");
  ASSERT_EQ(aoc2022::day03::Part01(input), 7737);
}

TEST_F(Day03Test, Part02TestExample) {
  const auto input = helpers::GetRucksackGroupsFromFile("data/03-test.txt");
  ASSERT_EQ(aoc2022::day03::Part02(input), 70);
}

TEST_F(Day03Test, Part02RealExample) {
  const auto input = helpers::GetRucksackGroupsFromFile("data/03.txt");
  ASSERT_EQ(aoc2022::day03::Part02(input), 2697);
}

}  // namespace
