#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_06.h"

using ::testing::Test;

namespace {
struct Day06Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day06Test, Part01TestExample) {
  std::vector<std::string> input;
  ASSERT_EQ(aoc2022::day06::Part01(input), 0);
}

TEST_F(Day06Test, Part01RealExample) {
  std::vector<std::string> input;
  ASSERT_EQ(aoc2022::day06::Part01(input), 0);
}

TEST_F(Day06Test, Part02TestExample) {
  std::vector<std::string> input;
  ASSERT_EQ(aoc2022::day06::Part02(input), 0);
}

TEST_F(Day06Test, Part02RealExample) {
  std::vector<std::string> input;
  ASSERT_EQ(aoc2022::day06::Part02(input), 0);
}

}  // namespace
