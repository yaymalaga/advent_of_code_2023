#include <array>
#include <vector>

#include "utils.hpp"

namespace advent_of_code_2023::day_1::utils {

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

  // List of written numbers and their corresponding digits
  static const std::array<std::pair<std::string, uint64_t>, 9> spelled_numbers =
      {{{"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}}};

  for (const auto& [written_number, number] : spelled_numbers) {
    auto pos = item.find(written_number);

    while (pos != std::string::npos) {
      replacements.emplace_back(pos, number);
      pos = item.find(written_number, pos + 1);
    }
  }

  // Now that we have the positions, we can replace them. To keep it simple and
  // avoid resizing the string, we just replace the first letter with the number
  for (const auto& replacement : replacements) {
    item[replacement.first] = intToChar(replacement.second);
  }
}

}  // namespace advent_of_code_2023::day_1::utils
