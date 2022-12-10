#include "day_09.h"

#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <set>

namespace aoc2022 {
namespace day09 {

namespace {

typedef struct node {
  std::pair<std::int32_t, std::int32_t> data{0, 0};
  size_t index = 0;
  struct node* prev = nullptr;
  struct node* next = nullptr;
  void add(std::pair<std::int32_t, std::int32_t> p) {
    std::pair<std::int32_t, std::int32_t> new_data{
        this->data.first + p.first, this->data.second + p.second};

    this->data = new_data;
  }
  bool operator<(const node& n) const { return index < n.index; }
} node;

int sgn(int val) {
  return (val > 0) - (val < 0);
}

const std::map<char, std::pair<std::int32_t, std::int32_t>> dir_map = {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'L', {-1, 0}},
    {'R', {1, 0}},
};

}  // namespace

std::int32_t count_tail_positions_for_n_nodes(
    const std::vector<std::pair<char, std::int32_t>>& data,
    std::int32_t number_of_nodes) {
  node* head = new node();

  auto index = 1;

  node* current_node = head;

  while (index != number_of_nodes) {
    node* new_node = new node();
    new_node->next = current_node;
    new_node->index = index;
    current_node->prev = new_node;
    current_node = new_node;
    ++index;
  }

  std::map<node, std::set<std::pair<std::int32_t, std::int32_t>>>
      visited_positions_by_node;

  while (current_node->next != nullptr) {
    visited_positions_by_node[*current_node].insert(current_node->data);
    current_node = current_node->next;
  }

  for (auto it = data.begin(); it != data.end(); ++it) {
    const auto direction = it->first;
    const auto steps = it->second;

    auto x = dir_map.at(direction);
    for (auto i = 0; i < steps; i++) {
      head->add(x);
      node* current_node = head;

      while (current_node->prev != nullptr) {
        current_node = current_node->prev;
        const auto dx =
            current_node->next->data.first - current_node->data.first;
        const auto dy =
            current_node->next->data.second - current_node->data.second;

        if (std::abs(dx) > 1 || std::abs(dy) > 1) {
          std::pair<std::int32_t, std::int32_t> dxy_1{sgn(dx), sgn(dy)};
          current_node->add(dxy_1);
          visited_positions_by_node[*current_node].insert(current_node->data);
        }
      }
    }
  }

  auto last_element = std::prev(visited_positions_by_node.end());

  return last_element->second.size();
}
std::int64_t Part01(const std::vector<std::pair<char, std::int32_t>>& data) {
  return count_tail_positions_for_n_nodes(data, 2);
}

std::int64_t Part02(const std::vector<std::pair<char, std::int32_t>>& data) {
  return count_tail_positions_for_n_nodes(data, 10);
}

}  // namespace day09
}  // namespace aoc2022
