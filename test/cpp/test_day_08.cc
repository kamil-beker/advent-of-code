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
  ASSERT_EQ(aoc2022::day08::Part01(), 0);
}

TEST_F(Day08Test, Part01RealExample) {
  ASSERT_EQ(aoc2022::day08::Part01(), 0);
}

TEST_F(Day08Test, Part02TestExample) {
  ASSERT_EQ(aoc2022::day08::Part02(), 0);
}

TEST_F(Day08Test, Part02RealExample) {
  ASSERT_EQ(aoc2022::day08::Part02(), 0);
}

}  // namespace
