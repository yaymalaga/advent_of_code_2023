#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace advent_of_code_2023 {
namespace common {
namespace utils {

/*
  @brief Read the input file and returns a vector of strings
  @param file_path The path to the input file
  @return A vector of strings
  */
std::vector<std::string> readInput(const std::filesystem::path& file_path);

/*
@brief Splits a string by a delimiter, which can appear multiple times
@param str The string to split
@param delimiter The delimiter
@return A vector of strings
*/
std::vector<std::string> splitString(const std::string& str,
                                     const std::string& delimiter);

}  // namespace utils
}  // namespace common
}  // namespace advent_of_code_2023
