#include "day_1/calibration_tool.hpp"
#include "gtest/gtest.h"

TEST(Day1Part1, Basic) {
  std::vector<std::string> data = {
      "1abc2",
      "pqr3stu8vwx",
      "a1b2c3d4e5f",
      "treb7uchet",
  };
  auto calibration_tool =
      advent_of_code_2023::day_1::calibration_tool::CalibrationTool(data);

  EXPECT_EQ(calibration_tool.getTotalCalibrationValue(), 142);
}

TEST(Day1Part2, SpelledNumbers) {
  std::vector<std::string> data = {
      "two1nine",         "eightwothree", "abcone2threexyz", "xtwone3four",
      "4nineeightseven2", "zoneight234",  "7pqrstsixteen",
  };

  auto calibration_tool =
      advent_of_code_2023::day_1::calibration_tool::CalibrationTool(data);

  EXPECT_NE(calibration_tool.getTotalCalibrationValue(), 281);

  calibration_tool.replaceSpelledNumbers();

  EXPECT_EQ(calibration_tool.getTotalCalibrationValue(), 281);
}

TEST(Day1Part2, SpelledNumbersRepeated) {
  std::vector<std::string> data = {
      "4nineeightseven2nine",
  };

  auto calibration_tool =
      advent_of_code_2023::day_1::calibration_tool::CalibrationTool(data);

  EXPECT_EQ(calibration_tool.getTotalCalibrationValue(), 42);

  calibration_tool.replaceSpelledNumbers();

  EXPECT_EQ(calibration_tool.getTotalCalibrationValue(), 49);
}
