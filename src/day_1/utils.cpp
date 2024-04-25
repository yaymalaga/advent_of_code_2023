#include <fstream>

#include "utils.hpp"

namespace advent_of_code_2023 {
namespace day_1 {
namespace utils {

int64_t charToInt(char character) {
  return static_cast<int64_t>(character - '0');
}

char intToChar(int64_t digit) {
  return static_cast<char>('0' + digit);
}

void replaceSpelledNumbers(std::string& item) {
  // Some of the spelled numbers can appear more than once and even share a
  // letter, for instance "twone" which should be treated as 2 and 1. Thus,
  // instead of directly replacing the substring, we create a list of all.

  // key is substring first letter pos and the value the number it represents
  std::vector<std::pair<size_t, int8_t>> replacements;

  for (const auto& [written_number, number] : SPELLED_NUMBERS) {
    auto pos = item.find(written_number);

    while (pos != std::string::npos) {
      replacements.push_back({pos, number});
      pos = item.find(written_number, pos + 1);
    }
  }

  // Now that we have the positions, we can replace them. To keep it simple and
  // avoid resizing the string, we just replace the first letter with the number
  for (const auto& replacement : replacements) {
    item[replacement.first] = intToChar(replacement.second);
  }
}

}  // namespace utils
}  // namespace day_1
}  // namespace advent_of_code_2023
