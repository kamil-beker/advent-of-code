#ifndef TEST_CPP_COMMON_H
#define TEST_CPP_COMMON_H

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

namespace helpers {

inline std::vector<std::vector<int32_t>> ProcessInput(const char* path) {
  std::ifstream infile(path);
  std::string line;

  std::vector<std::vector<std::int32_t>> values_container;
  std::vector<std::int32_t> values;

  while (std::getline(infile, line)) {
    if (!line.empty()) {
      std::int32_t val = std::stoi(line);
      values.push_back(val);
    } else {
      values_container.push_back(values);
      values.clear();
    }
  }

  // push leftovers
  if (!values.empty()) {
    values_container.push_back(values);
  }
  return values_container;
}

}  // namespace helpers

#endif  // TEST_CPP_COMMON_H
