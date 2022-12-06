#include <gtest/gtest.h>

#include "common.h"
#include "src/cpp/day_template.h"

using ::testing::Test;

namespace {
struct DayTemplateTest : Test {
  // void SetUp() override {};
  // void TearDown() override {};
};

TEST_F(DayTemplateTest, Part01TestExample) {
  ASSERT_EQ(aoc2022::day_template::Part01(), 0);
}

TEST_F(DayTemplateTest, Part01RealExample) {
  ASSERT_EQ(aoc2022::day_template::Part01(), 0);
}

TEST_F(DayTemplateTest, Part02TestExample) {
  ASSERT_EQ(aoc2022::day_template::Part02(), 0);
}

TEST_F(DayTemplateTest, Part02RealExample) {
  ASSERT_EQ(aoc2022::day_template::Part02(), 0);
}

}  // namespace
