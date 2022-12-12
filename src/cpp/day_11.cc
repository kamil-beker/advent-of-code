#include "day_11.h"

#include <algorithm>
#include <cctype>
#include <functional>
#include <regex>

namespace aoc2022 {
namespace day11 {

namespace {
typedef struct node {
  std::int64_t index = 0;
  std::int64_t modifier = 0;
  char operation = '\0';
  std::deque<std::int64_t> items;
  std::int64_t test_divisible_by = 0;
  std::int64_t inspection_count = 0;
  node* left = nullptr;
  node* right = nullptr;
} node;

const std::regex kMonkeyNameRegex("Monkey\\s(\\d+):");
const std::regex kStartingItemsRegex(
    "Starting\\sitems:\\s(\\d+((,\\s\\d+)+|))");
const std::regex kOperationRegex("new\\s=\\s(.*)");
const std::regex kDivisibleByRegex("divisible\\sby\\s(\\d+)");
const std::regex kLeftRegex("If\\strue:\\sthrow\\sto\\smonkey\\s(\\d+)");
const std::regex kRightRegex("If\\sfalse:\\sthrow\\sto\\smonkey\\s(\\d+)");
}  // namespace

std::vector<node*> GetNodes(const std::vector<std::string>& data) {
  std::vector<node*> nodes;
  std::smatch matches;

  for (size_t i = 0; i < data.size(); ++i) {
    node* current_node = new node();
    current_node->index = i;
    nodes.push_back(current_node);
  }

  for (const auto& monkey : data) {
    std::int64_t monkey_index = 0;
    std::deque<std::int64_t> starting_items;
    char modifier = '\0';
    std::int64_t operation = 0;
    std::int64_t test_divisible_by = 0;
    std::int64_t left_node_index = 0;
    std::int64_t right_node_index = 0;

    if (std::regex_search(monkey, matches, kMonkeyNameRegex)) {
      monkey_index = std::stoi(matches[1]);
    }

    if (std::regex_search(monkey, matches, kStartingItemsRegex)) {
      size_t pos = 0;
      std::string delimeter = ", ";
      std::string match = matches[1];

      std::string token;

      while ((pos = match.find(delimeter)) != std::string::npos) {
        token = match.substr(0, pos);
        starting_items.push_back(std::stoi(token));
        match.erase(0, pos + delimeter.length());
      }
      std::int64_t x = std::stoi(match);
      starting_items.push_back(x);
    }

    if (std::regex_search(monkey, matches, kOperationRegex)) {
      size_t pos = 0;
      std::string delimeter = " ";
      std::string match = matches[1];
      std::vector<std::string> ops;

      std::string token;
      while ((pos = match.find(delimeter)) != std::string::npos) {
        token = match.substr(0, pos);
        ops.push_back(token);
        match.erase(0, pos + delimeter.length());
      }
      ops.push_back(match);

      operation = ops[1][0];

      if (ops[2] != "old") {
        modifier = std::stoi(ops[2]);
      } else {
        modifier = 0;
      }
    }

    if (std::regex_search(monkey, matches, kDivisibleByRegex)) {
      test_divisible_by = std::stoi(matches[1]);
    }

    if (std::regex_search(monkey, matches, kLeftRegex)) {
      left_node_index = std::stoi(matches[1]);
    }

    if (std::regex_search(monkey, matches, kRightRegex)) {
      right_node_index = std::stoi(matches[1]);
    }

    node* current_node = nodes[monkey_index];
    current_node->items = starting_items;
    current_node->operation = operation;
    current_node->modifier = modifier;
    current_node->test_divisible_by = test_divisible_by;
    current_node->left = nodes[left_node_index];
    current_node->right = nodes[right_node_index];
  }

  return nodes;
}

std::int64_t Part01(const std::vector<std::string>& data, std::int64_t rounds) {
  std::int64_t result = 0;
  std::vector<std::int64_t> monkey_business;
  const auto nodes = GetNodes(data);

  for (auto round = 0; round < rounds; ++round) {
    for (auto it : nodes) {
      for (auto item : it->items) {
        it->inspection_count += 1;

        std::int64_t worry_level = 0;

        switch (it->operation) {
          case '*':
            if (it->modifier == 0) {
              worry_level = item * item;
            } else {
              worry_level = item * it->modifier;
            }
            break;
          case '+':
            if (it->modifier == 0) {
              worry_level = item + item;
            } else {
              worry_level = item + it->modifier;
            }
            break;
          default:
            break;
        }

        worry_level /= 3;

        if ((worry_level % it->test_divisible_by) == 0) {
          it->left->items.push_back(worry_level);
          it->items.pop_front();
        } else {
          it->right->items.push_back(worry_level);
          it->items.pop_front();
        }
      }
    }
  }

  for (auto it : nodes) {
    monkey_business.push_back(it->inspection_count);
  }

  std::nth_element(monkey_business.begin(), monkey_business.begin() + 2,
                   monkey_business.end(), std::greater<std::int64_t>());

  result = monkey_business[0] * monkey_business[1];

  return result;
}

std::int64_t Part02(const std::vector<std::string>& data, std::int64_t rounds) {
  std::int64_t result = 0;
  std::int64_t lcm = 1;
  std::vector<std::int64_t> monkey_business;
  const auto nodes = GetNodes(data);

  for (auto it : nodes) {
    lcm *= it->test_divisible_by;
  }

  for (auto round = 0; round < rounds; ++round) {
    for (auto it : nodes) {
      for (auto item : it->items) {
        it->inspection_count += 1;

        std::int64_t worry_level = 0;
        item %= lcm;
        switch (it->operation) {
          case '*':
            if (it->modifier == 0) {
              worry_level = item * item;
            } else {
              worry_level = item * it->modifier;
            }
            break;
          case '+':
            if (it->modifier == 0) {
              worry_level = item + item;
            } else {
              worry_level = item + it->modifier;
            }
            break;
          default:
            break;
        }

        if ((worry_level % it->test_divisible_by) == 0) {
          it->left->items.push_back(worry_level);
          it->items.pop_front();
        } else {
          it->right->items.push_back(worry_level);
          it->items.pop_front();
        }
      }
    }
  }

  for (auto it : nodes) {
    monkey_business.push_back(it->inspection_count);
  }

  std::nth_element(monkey_business.begin(), monkey_business.begin() + 2,
                   monkey_business.end(), std::greater<std::int64_t>());

  result = monkey_business[0] * monkey_business[1];

  return result;
}

}  // namespace day11
}  // namespace aoc2022
