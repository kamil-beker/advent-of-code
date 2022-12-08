#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_08.h"

using ::testing::Test;

namespace {
struct Day08Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day08Test, Part01TestExample) {
  const auto input = helpers::GetTreesFromFile("data/08-test.txt");
  ASSERT_EQ(aoc2022::day08::Part01(input), 21);
}

TEST_F(Day08Test, Part01RealExample) {
  const auto input = helpers::GetTreesFromFile("data/08.txt");
  ASSERT_EQ(aoc2022::day08::Part01(input), 1679);
}

TEST_F(Day08Test, Part02TestExample) {
  const auto input = helpers::GetTreesFromFile("data/08-test.txt");
  ASSERT_EQ(aoc2022::day08::Part02(input), 8);
}

TEST_F(Day08Test, Part02RealExample) {
  const auto input = helpers::GetTreesFromFile("data/08.txt");
  ASSERT_EQ(aoc2022::day08::Part02(input), 536625);
}

}  // namespace
