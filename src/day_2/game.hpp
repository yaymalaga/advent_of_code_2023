#pragma once

#include <cstdint>
#include <vector>

#include "cubes_set.hpp"

namespace advent_of_code_2023 {
namespace day_2 {
namespace game {

class Game {
 public:
  /*
  @brief Constructor
  @param game_data The game data as a raw string
  @details Example input "Game 1: 3 blue, 4 red; 1 red; 2 green"
  */
  Game(const std::string& game_data);

  ~Game() = default;

  /*
  @brief Gets the id of the game
  */
  uint8_t getId() const { return id_; };

  /*
  @brief Gets the game's cubes sets
  */
  const std::vector<cubes_set::CubesSet>& getData() const { return data_; };

 private:
  // id of the game
  std::uint8_t id_;

  // cubes sets of the game
  std::vector<cubes_set::CubesSet> data_;

  /*
  @brief Parses the id of the game
  @param game_data The game data as a raw string
  @details Example input "Game 1: 3 blue, 4 red; 1 red; 2 green"
  @return The id of the game
  */
  static uint8_t parseGameId(const std::string& game_data);

  /*
  @brief Parses the cubes sets of the game
  @param game_data The game data as a raw string
  @details Example input "Game 1: 3 blue, 4 red; 1 red; 2 green"
  @return The cubes sets of the game
  */
  static std::vector<cubes_set::CubesSet> parseCubesSets(
      const std::string& game_data);
};

}  // namespace game
}  // namespace day_2
}  // namespace advent_of_code_2023
