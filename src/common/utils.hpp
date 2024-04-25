#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

namespace advent_of_code_2023 {
namespace common {
namespace utils {

/*
  @brief Read the input file and returns a vector of strings
  @param file_path The path to the input file
  @return A vector of strings
  */
std::vector<std::string> readInput(const std::string& file_path);

}  // namespace utils
}  // namespace common
}  // namespace advent_of_code_2023