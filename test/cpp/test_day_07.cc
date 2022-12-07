#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_07.h"

using ::testing::Test;

namespace {
struct Day07Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day07Test, Part01TestExample) {
  const auto input = helpers::GetTerminalOutput("data/07-test.txt");
  ASSERT_EQ(aoc2022::day07::Part01(input), 95437);
}

TEST_F(Day07Test, Part01RealExample) {
  const auto input = helpers::GetTerminalOutput("data/07.txt");
  ASSERT_EQ(aoc2022::day07::Part01(input), 1778099);
}

TEST_F(Day07Test, Part02TestExample) {
  const auto input = helpers::GetTerminalOutput("data/07-test.txt");
  ASSERT_EQ(aoc2022::day07::Part02(input), 24933642);
}

TEST_F(Day07Test, Part02RealExample) {
  const auto input = helpers::GetTerminalOutput("data/07.txt");
  ASSERT_EQ(aoc2022::day07::Part02(input), 1623571);
}

}  // namespace
