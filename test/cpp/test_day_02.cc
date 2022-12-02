#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_02.h"

using ::testing::Test;

namespace {
struct Day02Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day02Test, Part01TestExample) {
  const auto input = helpers::GetStrategyGuideFromFile("data/02-test.txt");
  ASSERT_EQ(aoc2022::day02::Part01(input), 15);
}

TEST_F(Day02Test, Part01RealExample) {
  const auto input = helpers::GetStrategyGuideFromFile("data/02.txt");
  ASSERT_EQ(aoc2022::day02::Part01(input), 10404);
}

TEST_F(Day02Test, Part02TestExample) {
  const auto input = helpers::GetStrategyGuideFromFile("data/02-test.txt");
  ASSERT_EQ(aoc2022::day02::Part02(input), 12);
}

TEST_F(Day02Test, Part02RealExample) {
  const auto input = helpers::GetStrategyGuideFromFile("data/02.txt");
  ASSERT_EQ(aoc2022::day02::Part02(input), 10334);
}
}  // namespace
