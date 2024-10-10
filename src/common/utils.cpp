#include "utils.hpp"

#include <filesystem>
#include <fstream>

namespace advent_of_code_2023::common::utils {

std::vector<std::string> readInput(const std::filesystem::path& file_path) {
  std::ifstream input(file_path);
  std::string line;
  std::vector<std::string> data;

  while (std::getline(input, line)) {
    data.push_back(line);
  }
  input.close();

  return data;
}

std::vector<std::string> splitString(const std::string& str,
                                     const std::string& delimiter) {
  std::vector<std::string> substrings;
  size_t start = 0;
  size_t pos = str.find(delimiter, start);

  while (pos != std::string::npos) {
    substrings.push_back(str.substr(start, pos - start));
    start = pos + delimiter.length();
    pos = str.find(delimiter, start);
  }

  // Add the last token (after the last delimiter)
  substrings.push_back(str.substr(start));

  return substrings;
}

}  // namespace advent_of_code_2023::common::utils
