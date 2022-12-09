#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_09.h"

using ::testing::Test;

namespace {
struct Day09Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day09Test, Part01TestExample) {
  const auto input = helpers::GetSeriesOfMotionsFromFIle("data/09-test.txt");
  ASSERT_EQ(aoc2022::day09::Part01(input), 13);
}

TEST_F(Day09Test, Part01RealExample) {
  const auto input = helpers::GetSeriesOfMotionsFromFIle("data/09.txt");
  ASSERT_EQ(aoc2022::day09::Part01(input), 6098);
}

TEST_F(Day09Test, Part02TestExample) {
  const auto input = helpers::GetSeriesOfMotionsFromFIle("data/09-test.txt");
  ASSERT_EQ(aoc2022::day09::Part02(input), 0);
}

TEST_F(Day09Test, Part02RealExample) {
  const auto input = helpers::GetSeriesOfMotionsFromFIle("data/09-test.txt");
  ASSERT_EQ(aoc2022::day09::Part02(input), 0);
}

}  // namespace
