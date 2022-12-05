#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_05.h"

using ::testing::Test;

namespace {
struct Day05Test : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(Day05Test, Part01TestExample) {
  const auto splitted_input =
      helpers::GetSplittedCargoInputFromFile("data/05-test.txt");

  const auto crate_input = helpers::GetCrates(splitted_input.at(0));
  const auto cargo_move_input =
      helpers::GetCargoRearrangementProcedure(splitted_input.at(1));

  ASSERT_EQ(aoc2022::day05::Part01(crate_input, cargo_move_input), "CMZ");
}

TEST_F(Day05Test, Part01RealExample) {
  const auto splitted_input =
      helpers::GetSplittedCargoInputFromFile("data/05.txt");

  const auto crate_input = helpers::GetCrates(splitted_input.at(0));
  const auto cargo_move_input =
      helpers::GetCargoRearrangementProcedure(splitted_input.at(1));

  ASSERT_EQ(aoc2022::day05::Part01(crate_input, cargo_move_input), "ZRLJGSCTR");
}

TEST_F(Day05Test, Part02TestExample) {
  const auto splitted_input =
      helpers::GetSplittedCargoInputFromFile("data/05-test.txt");

  const auto crate_input = helpers::GetCrates(splitted_input.at(0));
  const auto cargo_move_input =
      helpers::GetCargoRearrangementProcedure(splitted_input.at(1));

  ASSERT_EQ(aoc2022::day05::Part02(crate_input, cargo_move_input), "MCD");
}

TEST_F(Day05Test, Part02RealExample) {
  const auto splitted_input =
      helpers::GetSplittedCargoInputFromFile("data/05.txt");

  const auto crate_input = helpers::GetCrates(splitted_input.at(0));
  const auto cargo_move_input =
      helpers::GetCargoRearrangementProcedure(splitted_input.at(1));

  ASSERT_EQ(aoc2022::day05::Part02(crate_input, cargo_move_input), "PRTTGRFPB");
}

}  // namespace
