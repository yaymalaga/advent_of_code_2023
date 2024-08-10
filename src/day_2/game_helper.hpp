#pragma once

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

#include "cubes_set.hpp"
#include "game.hpp"

namespace advent_of_code_2023 {
namespace day_2 {
namespace game_helper {

class GameHelper {
 public:
  /*
  @brief Constructor
  @param data The list of raw game strings to process
  */
  GameHelper(const std::vector<std::string>& data);

  /*
  @brief Constructor
  @param data_path The path to the input file with the game raw data
  */
  GameHelper(const std::filesystem::path& data_path);

  ~GameHelper() = default;

  /*
  @brief Iterates through the data and calculates the ids sum of valid games
  @return The ids sum value
  */
  int64_t getPossibleGamesValue(const cubes_set::CubesSet& bag_content) const;

  /*
  @brief Calculates the total cubes power from the games needed minimum bag
  @return The total cubes power
  */
  int64_t getMinBagsPower() const;

 private:
  // The list of games to process
  std::vector<game::Game> games_data_;

  /*
  @brief Parses the data of the games
  @param games_data The list of raw game strings to process
  @return The list of games
  */
  static std::vector<game::Game> parseGamesData(
      const std::vector<std::string>& games_data);

  /*
  @brief Checks if a game is possible
  @details The number of cubes of each color cannot exceed the ones in the bag
  @param game The game to check
  @param bag_content The cubes set in the bag
  @return Whether the game is possible
  */
  bool isGamePossible(const game::Game& game,
                      const cubes_set::CubesSet& bag_content) const;

  /*
  @brief Calculates the cubes set needed in the bag to make a game valid
  @param game The game to calculate
  @return The cubes set needed in the bag
  */
  cubes_set::CubesSet calculateBagContent(const game::Game& game) const;

  /*
  @brief Calculates the power of a cubes set
  @details This is obtained by multipling the cubes number of each color
  @param cubes_set The cubes set to calculate
  @return The cubes power
  */
  uint64_t getCubesPower(const cubes_set::CubesSet& cubes_set) const;
};

}  // namespace game_helper
}  // namespace day_2
}  // namespace advent_of_code_2023
