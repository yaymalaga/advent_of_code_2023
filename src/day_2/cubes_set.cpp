#include <iostream>
#include <string>
#include <vector>

#include "common/utils.hpp"
#include "cubes_set.hpp"

namespace advent_of_code_2023 {
namespace day_2 {
namespace cubes_set {

CubesSet::CubesSet(const std::uint8_t green_cubes,
                   const std::uint8_t red_cubes,
                   const std::uint8_t blue_cubes)
    : green_cubes_(green_cubes),
      red_cubes_(red_cubes),
      blue_cubes_(blue_cubes) {}

CubesSet::CubesSet(const std::string& cubes_data) {
  std::tie(green_cubes_, red_cubes_, blue_cubes_) = parseInput(cubes_data);
}

std::tuple<uint8_t, uint8_t, uint8_t> CubesSet::parseInput(
    const std::string& cubes_data) const {
  uint8_t green_cubes = 0;
  uint8_t red_cubes = 0;
  uint8_t blue_cubes = 0;

  // Cubes are separated by a comma
  std::vector<std::string> data = common::utils::splitString(cubes_data, ",");

  if (data.size() > 3) {
    std::cout << "Invalid size? -> " << cubes_data << std::endl;
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
      green_cubes = quantity;
    } else if (data[1] == "red") {
      red_cubes = quantity;
    } else if (data[1] == "blue") {
      blue_cubes = quantity;
    } else {
      std::cout << "Invalid color -> " << item << std::endl;
    }
  }

  return std::tuple{green_cubes, red_cubes, blue_cubes};
}

}  // namespace cubes_set
}  // namespace day_2
}  // namespace advent_of_code_2023