#include "game_helper.hpp"
#include "common/utils.hpp"

namespace advent_of_code_2023 {
namespace day_2 {
namespace game_helper {

GameHelper::GameHelper(const std::vector<std::string>& data)
    : games_data_(parseGamesData(data)) {}

GameHelper::GameHelper(const std::filesystem::path& data_path)
    : GameHelper(common::utils::readInput(data_path)) {}

int64_t GameHelper::getPossibleGamesValue(
    const cubes_set::CubesSet& bag_content) const {
  int64_t sum = 0;

  for (const auto& item : games_data_) {
    if (isGamePossible(item, bag_content)) {
      sum += item.getId();
    }
  }

  return sum;
}

int64_t GameHelper::getMinBagsPower() const {
  int64_t sum = 0;

  for (const auto& game : games_data_) {
    auto needed_bag = calculateBagContent(game);
    sum += getCubesPower(needed_bag);
  }

  return sum;
}

std::vector<game::Game> GameHelper::parseGamesData(
    const std::vector<std::string>& games_data) {
  std::vector<game::Game> games;

  for (const auto& item : games_data) {
    games.push_back(game::Game(item));
  }

  return games;
}

bool GameHelper::isGamePossible(const game::Game& game,
                                const cubes_set::CubesSet& bag_content) const {
  for (const auto& cubes_set : game.getData()) {
    if (cubes_set.getBlueCubes() > bag_content.getBlueCubes() ||
        cubes_set.getRedCubes() > bag_content.getRedCubes() ||
        cubes_set.getGreenCubes() > bag_content.getGreenCubes()) {
      return false;
    }
  }
  return true;
}

cubes_set::CubesSet GameHelper::calculateBagContent(
    const game::Game& game) const {
  uint8_t green_cubes = 0;
  uint8_t red_cubes = 0;
  uint8_t blue_cubes = 0;

  for (const auto& cubes_set : game.getData()) {
    green_cubes = std::max(cubes_set.getGreenCubes(), green_cubes);
    red_cubes = std::max(cubes_set.getRedCubes(), red_cubes);
    blue_cubes = std::max(cubes_set.getBlueCubes(), blue_cubes);
  }

  return cubes_set::CubesSet(green_cubes, red_cubes, blue_cubes);
}

uint64_t GameHelper::getCubesPower(const cubes_set::CubesSet& cubes_set) const {
  return cubes_set.getGreenCubes() * cubes_set.getRedCubes() *
         cubes_set.getBlueCubes();
}

}  // namespace game_helper
}  // namespace day_2
}  // namespace advent_of_code_2023
