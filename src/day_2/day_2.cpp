#include <iostream>

#include "cubes_set.hpp"
#include "game_helper.hpp"

int main() {
  const std::filesystem::path data_path = "data/day_2.txt";

  // Part 1
  auto game_helper =
      advent_of_code_2023::day_2::game_helper::GameHelper(data_path);

  auto bag_content =
      advent_of_code_2023::day_2::cubes_set::CubesSet(13, 12, 14);

  std::cout << "Part 1 -> Total ids sum of valid games: "
            << game_helper.getPossibleGamesValue(bag_content) << std::endl;

  // Part 2
  std::cout << "Part 2 -> Total power of the games minimum cubes needed: "
            << game_helper.getMinBagsPower() << std::endl;

  return 0;
}
