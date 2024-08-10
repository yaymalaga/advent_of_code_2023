#include <iostream>

#include "common/utils.hpp"
#include "engine_checker.hpp"
#include "engine_schematic.hpp"

int main() {
  const std::filesystem::path data_path = "data/day_3.txt";
  const std::vector<std::string> input_data =
      advent_of_code_2023::common::utils::readInput(data_path);

  auto engine_schematic =
      advent_of_code_2023::day_3::engine_schematic::EngineSchematic(input_data);

  auto engine_checker =
      advent_of_code_2023::day_3::engine_checker::EngineChecker(
          engine_schematic);

  // Part 1
  std::cout << "Part 1 -> Total sum of parts number: "
            << engine_checker.getPartsNumberSum() << std::endl;

  // Part 2
  std::cout << "Part 2 -> Total sum of gears ratio: "
            << engine_checker.getGearsSum() << std::endl;
}
