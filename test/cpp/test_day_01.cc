#include <gtest/gtest.h>

#include "src/cpp/day_01.h"
#include <spdlog/spdlog.h>

using ::testing::Test;

namespace {

struct Day01Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day01Test, ReturnsTrue) {
  std::vector<std::int32_t> data{};

  spdlog::debug("hello from {}", __func__);

  ASSERT_EQ(aoc2022::day01::part_01(data), 0);
  ASSERT_EQ(aoc2022::day01::part_02(data), 0);
}

} // namespace