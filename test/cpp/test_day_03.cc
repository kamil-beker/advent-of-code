#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_03.h"

using ::testing::Test;

namespace {
struct Day03Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day03Test, Day03Ready) {
  ASSERT_EQ(aoc2022::day03::Part01(), 0);
  ASSERT_EQ(aoc2022::day03::Part02(), 0);
}

}  // namespace
