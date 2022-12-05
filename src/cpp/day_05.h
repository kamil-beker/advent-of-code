#ifndef SRC_CPP_DAY_05_H
#define SRC_CPP_DAY_05_H

#include <cstdint>
#include <stack>
#include <vector>

namespace aoc2022 {
namespace day05 {

std::string Part01(std::vector<std::stack<char>> crate_data,
                   std::vector<std::vector<std::int32_t>> move_data);
std::string Part02(std::vector<std::stack<char>> crate_data,
                   std::vector<std::vector<std::int32_t>> move_data);

}  // namespace day05
}  // namespace aoc2022

#endif  // SRC_CPP_DAY_05_H
