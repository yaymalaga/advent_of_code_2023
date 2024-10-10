#include <iostream>
#include <string>
#include <vector>

#include "common/utils.hpp"
#include "cubes_set.hpp"

namespace advent_of_code_2023::day_2::cubes_set {

CubesSet::CubesSet(const CubesData& cubes_data) : cubes_data_(cubes_data) {}

CubesSet::CubesSet(const std::string& cubes_raw_data)
    : cubes_data_(parseInput(cubes_raw_data)) {}

CubesSet::CubesData CubesSet::parseInput(const std::string& cubes_raw_data) {
  CubesData cubes_data{};

  // Cubes are separated by a comma
  std::vector<std::string> data =
      common::utils::splitString(cubes_raw_data, ",");

  if (data.size() > 3) {
    std::cout << "Invalid size? -> " << cubes_raw_data << std::endl;
  }

  for (auto& item : data) {
    // First, remove initial whitespace if any
    if (item[0] == ' ') {
      item = item.substr(1);
    };

    // Item should be a number and a color separated by a whitespace
    std::vector<std::string> data = common::utils::splitString(item, " ");

    if (data.size() != 2) {
      std::cout << "Invalid item size -> " << item << std::endl;
      continue;
    }

    int quantity = 0;
    try {
      // First get the cube quantity
      quantity = std::stoi(data[0]);
    } catch (std::exception& e) {
      std::cout << "Invalid quantity -> " << item << std::endl;
      continue;
    }

    // Add the cubes to the corresponding color
    if (data[1] == "green") {
      cubes_data.green_number = quantity;
    } else if (data[1] == "red") {
      cubes_data.red_number = quantity;
    } else if (data[1] == "blue") {
      cubes_data.blue_number = quantity;
    } else {
      std::cout << "Invalid color -> " << item << std::endl;
    }
  }

  return cubes_data;
}

}  // namespace advent_of_code_2023::day_2::cubes_set
