#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_01.h"

using ::testing::Test;

namespace {

struct Day01Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day01Test, Part01TestExample) {
  const auto input = helpers::ProcessInput("data/01-01-test.txt");
  ASSERT_EQ(aoc2022::day01::Part01(input), 24000);
}

TEST_F(Day01Test, Part01RealExample) {
  const auto input = helpers::ProcessInput("data/01-01.txt");
  ASSERT_EQ(aoc2022::day01::Part01(input), 69836);
}

TEST_F(Day01Test, Part02TestExample) {
  const auto input = helpers::ProcessInput("data/01-01-test.txt");
  ASSERT_EQ(aoc2022::day01::Part02(input), 45000);
}

TEST_F(Day01Test, Part02RealExample) {
  const auto input = helpers::ProcessInput("data/01-01.txt");
  ASSERT_EQ(aoc2022::day01::Part02(input), 207968);
}

}  // namespace
