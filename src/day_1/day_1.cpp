#include <iostream>

#include "calibration_tool.hpp"

int main() {
  const std::filesystem::path data_path = "data/day_1.txt";

  // Part 1
  auto calibration_tool =
      advent_of_code_2023::day_1::calibration_tool::CalibrationTool(data_path);

  std::cout << "Part 1 -> Total calibration value: "
            << calibration_tool.getTotalCalibrationValue() << std::endl;

  // Part 2
  calibration_tool.replaceSpelledNumbers();

  std::cout << "Part 2 -> Total calibration value: "
            << calibration_tool.getTotalCalibrationValue() << std::endl;

  return 0;
}
