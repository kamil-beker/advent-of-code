#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_04.h"

using ::testing::Test;

namespace {
struct Day04Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day04Test, Part01TestExample) {
  const auto input = helpers::GetSectionAssignmentsFromFile("data/04-test.txt");
  ASSERT_EQ(aoc2022::day04::Part01(input), 2);
}

TEST_F(Day04Test, Part01RealExample) {
  const auto input = helpers::GetSectionAssignmentsFromFile("data/04.txt");
  ASSERT_EQ(aoc2022::day04::Part01(input), 571);
}

TEST_F(Day04Test, Part02TestExample) {
  const auto input = helpers::GetSectionAssignmentsFromFile("data/04-test.txt");
  ASSERT_EQ(aoc2022::day04::Part02(input), 4);
}

TEST_F(Day04Test, Part02RealExample) {
  const auto input = helpers::GetSectionAssignmentsFromFile("data/04.txt");
  ASSERT_EQ(aoc2022::day04::Part02(input), 917);
}

}  // namespace
