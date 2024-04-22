#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace advent_of_code_2023 {
namespace day_1 {
namespace calibration_tool {

class CalibrationTool {
 public:
  /*
  @brief Constructor
  @param data The list of strings to process
  */
  CalibrationTool(std::vector<std::string>& data);

  /*
  @brief Constructor
  @param data_path The path to the input file
  */
  CalibrationTool(const std::string& data_path);

  ~CalibrationTool() = default;

  /*
  @brief Iterates through the data and calculates each calibration value
  @return The total calibration value
  */
  int64_t getTotalCalibrationValue();

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
  int64_t getCalibrationValue(const std::string& item);
};

}  // namespace calibration_tool
}  // namespace day_1
}  // namespace advent_of_code_2023