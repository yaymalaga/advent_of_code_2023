#include <iostream>
#include <optional>

#include "calibration_tool.hpp"
#include "common/utils.hpp"
#include "utils.hpp"

namespace advent_of_code_2023::day_1::calibration_tool {

CalibrationTool::CalibrationTool(const std::vector<std::string>& data)
    : data_(data) {}

CalibrationTool::CalibrationTool(const std::filesystem::path& data_path)
    : CalibrationTool(common::utils::readInput(data_path)) {}

int64_t CalibrationTool::getCalibrationValue(const std::string& item) {
  std::optional<char> first;
  std::optional<char> last;

  for (auto character : item) {
    // We are only interested in processing numbers
    if (std::isdigit(character) == 0) {
      continue;
    }

    // Save the number into the right place
    if (!first.has_value()) {
      first = character;
    } else {
      last = character;
    }
  }

  // If we haven't found a single number just return 0
  if (!first.has_value()) {
    std::cout << "Invalid input? -> " << item << std::endl;
    return 0;
  }

  // It's possible a single number appears, in which case the first and last
  // digits would be the same ones
  if (!last.has_value()) {
    last = first;
  }

  // The result is the two numbers together, thus to keep it simple we can
  // multiply the first by 10 and add the second one
  const auto ten = 10;
  return utils::charToInt(first.value()) * ten + utils::charToInt(last.value());
}

int64_t CalibrationTool::getTotalCalibrationValue() const {
  // Just iterates through every item and sums up the values
  int64_t total = 0;

  for (const auto& item : data_) {
    total += getCalibrationValue(item);
  }

  return total;
}

void CalibrationTool::replaceSpelledNumbers() {
  for (auto& item : data_) {
    utils::replaceSpelledNumbers(item);
  }
}

}  // namespace advent_of_code_2023::day_1::calibration_tool
