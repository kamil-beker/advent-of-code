#include <gtest/gtest.h>
#include <vector>

#include "common.h"
#include "src/cpp/day_02.h"

using ::testing::Test;

namespace {
struct Day02Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day02Test, Day2Prepared) {
  std::vector<std::vector<std::int32_t>> dummy_data{};

  ASSERT_EQ(aoc2022::day02::Part01(dummy_data), 0);
  ASSERT_EQ(aoc2022::day02::Part02(dummy_data), 0);
}
}  // namespace
