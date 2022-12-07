#include "day_07.h"

#include <algorithm>
#include <cctype>
#include <functional>
#include <numeric>
#include <regex>

namespace aoc2022 {
namespace day07 {

namespace {
const std::regex kCommandRegex("\\$\\s(cd)\\s{0,1}(.*)");
const std::regex kFileEntryRegex("^(\\d*|dir)\\s([a-z]*\\.{0,1}[a-z]*)$");

constexpr auto kTotalDiskSpace = 70000000;
constexpr auto kUpdateSize = 30000000;
}  // namespace

typedef struct node {
  std::string name = "";
  std::int64_t size = 0;
  struct node* parent = nullptr;
  std::vector<struct node*> childrens;
} node;

std::vector<node*> FileSystem(const std::vector<std::string>& data) {
  std::vector<node*> file_system;

  node* root = new node({"/", 0, nullptr, {}});
  file_system.push_back(root);

  node* current_dir = root;
  for (auto it = data.begin() + 1; it != data.end(); it++) {
    std::smatch matches;

    if (std::regex_search(*it, matches, kCommandRegex)) {
      const std::string command = matches[1];
      const std::string dir_name = matches[2];

      if (command == "cd" && dir_name != "..") {
        auto find_result = std::find_if(
            current_dir->childrens.begin(), current_dir->childrens.end(),
            [&dir_name](node* child) { return child->name == dir_name; });

        if (find_result != current_dir->childrens.end()) {
          current_dir = *find_result;
        }
      }

      if (command == "cd" && dir_name == "..") {
        if (current_dir->parent != nullptr) {
          current_dir = current_dir->parent;
        }
      }
    }

    if (std::regex_search(*it, matches, kFileEntryRegex)) {
      const std::string type = matches[1];
      const std::string name = matches[2];

      if (type == "dir") {
        node* dir_node = new node({name, 0, current_dir, {}});
        file_system.push_back(dir_node);
        current_dir->childrens.push_back(dir_node);
      } else {
        node* file_node = new node({name, std::stoi(type), current_dir, {}});

        current_dir->size += file_node->size;
        current_dir->childrens.push_back(file_node);

        node* temp_ptr = current_dir;
        while (temp_ptr->parent != nullptr) {
          temp_ptr->parent->size += file_node->size;
          temp_ptr = temp_ptr->parent;
        }
      }
    }
  }

  return file_system;
}

std::int64_t Part01(const std::vector<std::string>& data) {
  std::int64_t result = 0;

  const auto directories = FileSystem(data);

  result = std::accumulate(directories.begin(), directories.end(), 0,
                           [](int64_t acc, struct node* n) {
                             if (n->size <= 100000) {
                               return acc + n->size;
                             } else
                               return acc;
                           });

  return result;
}

std::int64_t Part02(const std::vector<std::string>& data) {
  const auto directories = FileSystem(data);
  const auto root = *(std::find_if(directories.begin(), directories.end(),
                                   [](node* n) { return n->name == "/"; }));
  const auto total_used_space = root->size;
  const auto total_disk_space = kTotalDiskSpace;
  const auto space_to_free =
      kUpdateSize - (total_disk_space - total_used_space);

  std::vector<std::int64_t> sizes;
  for (const auto dir : directories) {
    if (dir->size > space_to_free) {
      sizes.push_back(dir->size);
    }
  }

  std::nth_element(sizes.begin(), sizes.begin() + 1, sizes.end());

  return sizes[0];
}

}  // namespace day07
}  // namespace aoc2022
