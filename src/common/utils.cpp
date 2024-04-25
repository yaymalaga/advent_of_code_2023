#include <fstream>

#include "utils.hpp"

namespace advent_of_code_2023 {
namespace common {
namespace utils {

std::vector<std::string> readInput(const std::string& file_path) {
  std::ifstream input(file_path);
  std::string line;
  std::vector<std::string> data;

  while (std::getline(input, line)) {
    data.push_back(line);
  }
  input.close();

  return data;
}

}  // namespace utils
}  // namespace common
}  // namespace advent_of_code_2023
