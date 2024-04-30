#include <iostream>

#include "common/utils.hpp"
#include "game.hpp"

namespace advent_of_code_2023 {
namespace day_2 {
namespace game {

Game::Game(const std::string& game_data)
    : id_{parseGameId(game_data)}, data_{parseCubesSets(game_data)} {}

uint8_t Game::parseGameId(const std::string& game_data) {
  std::string game_substring = common::utils::splitString(game_data, ":")[0];
  std::string id_substring = common::utils::splitString(game_substring, " ")[1];

  // Try to parse game_id as a number. Default to 0 if it fails.
  try {
    return std::stoi(id_substring);
  } catch (std::exception& e) {
    std::cout << "Invalid id -> " << game_data << std::endl;
    return 0;
  }
}

std::vector<cubes_set::CubesSet> Game::parseCubesSets(
    const std::string& game_data) {
  std::string cube_sets_substring =
      common::utils::splitString(game_data, ":")[1];
  std::vector<std::string> raw_cubes_sets =
      common::utils::splitString(cube_sets_substring, ";");

  std::vector<cubes_set::CubesSet> cubes_sets;
  for (auto& cubes_set : raw_cubes_sets) {
    cubes_sets.push_back(cubes_set::CubesSet(cubes_set));
  }

  return cubes_sets;
}

}  // namespace game
}  // namespace day_2
}  // namespace advent_of_code_2023
