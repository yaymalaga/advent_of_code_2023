#include <iostream>

#include "cubes_set.hpp"
#include "game_helper.hpp"

int main() {
  const std::filesystem::path data_path = "data/day_2.txt";

  // Part 1
  auto game_helper =
      advent_of_code_2023::day_2::game_helper::GameHelper(data_path);

  const int green_cubes = 13;
  const int red_cubes = 12;
  const int blue_cubes = 14;

  const auto cubes_data =
      advent_of_code_2023::day_2::cubes_set::CubesSet::CubesData(
          {green_cubes, red_cubes, blue_cubes});

  const auto bag_content =
      advent_of_code_2023::day_2::cubes_set::CubesSet(cubes_data);

  std::cout << "Part 1 -> Total ids sum of valid games: "
            << game_helper.getPossibleGamesValue(bag_content) << std::endl;

  // Part 2
  std::cout << "Part 2 -> Total power of the games minimum cubes needed: "
            << game_helper.getMinBagsPower() << std::endl;

  return 0;
}
