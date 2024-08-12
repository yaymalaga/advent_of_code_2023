#include <iostream>

#include "common/utils.hpp"
#include "day_5/almanac.hpp"

int main() {
  const std::filesystem::path data_path = "data/day_5.txt";
  const std::vector<std::string> input_data =
      advent_of_code_2023::common::utils::readInput(data_path);

  auto almanac = advent_of_code_2023::day_5::almanac::Almanac(input_data);

  // Part 1
  auto seeds_part1 = almanac.getSeedsSimple();
  std::cout << "Part 1 -> Lowest seed location number: "
            << almanac.getMinLocation(seeds_part1) << std::endl;

  // Part 2
  auto seeds_part2 = almanac.getSeedsPair();
  std::cout << "Part 2 -> Lowest seed location number: " << seeds_part2.size()
            << std::endl;
}
