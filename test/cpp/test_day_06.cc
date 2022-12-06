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
  ASSERT_EQ(aoc2022::day06::Part01("bvwbjplbgvbhsrlpgdmjqwftvncz"), 5);
  ASSERT_EQ(aoc2022::day06::Part01("nppdvjthqldpwncqszvftbrmjlhg"), 6);
  ASSERT_EQ(aoc2022::day06::Part01("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"), 10);
  ASSERT_EQ(aoc2022::day06::Part01("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"), 11);
}

TEST_F(Day06Test, Part01RealExample) {
  const auto input = helpers::GetPacketFromFile("data/06.txt");
  ASSERT_EQ(aoc2022::day06::Part01(input), 1850);
}

TEST_F(Day06Test, Part02TestExample) {
  ASSERT_EQ(aoc2022::day06::Part02("bvwbjplbgvbhsrlpgdmjqwftvncz"), 23);
  ASSERT_EQ(aoc2022::day06::Part02("nppdvjthqldpwncqszvftbrmjlhg"), 23);
  ASSERT_EQ(aoc2022::day06::Part02("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"), 29);
  ASSERT_EQ(aoc2022::day06::Part02("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"), 26);
}

TEST_F(Day06Test, Part02RealExample) {
  const auto input = helpers::GetPacketFromFile("data/06.txt");
  ASSERT_EQ(aoc2022::day06::Part02(input), 2823);
}

}  // namespace
