#include "utils.hpp"

namespace advent_of_code_2023 {
namespace day_2 {
namespace utils {

std::vector<std::string> splitString(const std::string& str, char delimiter) {
  std::vector<std::string> substrings;
  size_t start = 0;
  size_t pos = str.find(delimiter, start);

  while (pos != std::string::npos) {
    substrings.push_back(str.substr(start, pos - start));
    start = pos + 1;
    pos = str.find(delimiter, start);
  }

  // Add the last token (after the last delimiter)
  substrings.push_back(str.substr(start));

  return substrings;
}

}  // namespace utils
}  // namespace day_2
}  // namespace advent_of_code_2023
