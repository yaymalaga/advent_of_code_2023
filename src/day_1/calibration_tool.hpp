#pragma once

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace advent_of_code_2023::day_1::calibration_tool {

class CalibrationTool {
 public:
  CalibrationTool(const CalibrationTool&) = default;
  CalibrationTool(CalibrationTool&&) = delete;
  CalibrationTool& operator=(const CalibrationTool&) = default;
  CalibrationTool& operator=(CalibrationTool&&) = delete;

  /*
    @brief Constructor
    @param data The list of strings to process
    */
  explicit CalibrationTool(const std::vector<std::string>& data);

  /*
  @brief Constructor
  @param data_path The path to the input file
  */
  explicit CalibrationTool(const std::filesystem::path& data_path);

  ~CalibrationTool() = default;

  /*
  @brief Iterates through the data and calculates each calibration value
  @return The total calibration value
  */
  int64_t getTotalCalibrationValue() const;

  /*
  @brief Replaces all spelled numbers of the data by their actual digits
  */
  void replaceSpelledNumbers();

 private:
  /*
  @brief The list of strings to process
  */
  std::vector<std::string> data_;

  /*
  @brief Calculates the calibration value of a string
  @details This value is obtained by appending the first and last
  digit found
  @return The calibration value obtained
  */
  static int64_t getCalibrationValue(const std::string& item);
};

}  // namespace advent_of_code_2023::day_1::calibration_tool
