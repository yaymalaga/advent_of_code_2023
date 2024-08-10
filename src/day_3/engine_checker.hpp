#pragma once

#include <vector>

#include "engine_schematic.hpp"

namespace advent_of_code_2023 {
namespace day_3 {
namespace engine_checker {

class EngineChecker {
 public:
  /*
  @brief Constructor
  @param engine_checker The engine schematic to process
  */
  EngineChecker(engine_schematic::EngineSchematic& engine_schematic);

  ~EngineChecker() = default;

  /*
  @brief Iterates through the engine schematic and calculates the sum of the
  parts numbers
  @return The sum of the parts numbers
  */
  int64_t getPartsNumberSum() const;

  /*
  @brief Simple data structure to store the row and column of an item
  */
  struct Location {
    size_t row;
    size_t col;
  };

  /*
  @brief Iterates through the engine schematic and returns the location of every
  symbol that is not a dot or a number
  @param filter Symbol to filter by. If not provided, all symbols are returned
  @return The list of symbols location
  */
  std::vector<Location> getSymbolsLocation(
      std::optional<char> filter = {}) const;

  /*
  @brief Gets the adjacent digits of an item. If the item on the top or bottom
  are symbols, then diagonals are check too.
  @details The diagonal case is handled this way to ensure a number is not
  duplicated. For instance, is a digit is found in the top right and top, they
  would be treated as two number while they are actually just one.
  @param item_location The location of the item
  @return The list of adjacent digits found
  */
  std::vector<Location> getAdjacentDigits(Location item_location) const;

  /*
  @brief Starting from a digit location, performs a search in both directions to
  parse a full number
  @param digit_location The location of the digit
  @return The number found
  */
  int64_t findNumberFromDigit(Location digit_location) const;

  /*
  @brief Iterates through the engine schematic and calculates the sum of the
  gears ratio.
  @details The gears ratio is the product of the two adjacent gears ratios found
  on every symbol '*' that only contains two adjacent numbers.
  @return The sum of the gears
  */
  int64_t getGearsSum() const;

 private:
  // Internal data to store the engine schematic
  const engine_schematic::EngineSchematic engine_schematic_;

  /*
  @brief Checks whether an item is a symbol or not
  @param item The item to check
  @return True if the item is a symbol
  */
  static bool isSymbol(char item);

  /*
  @brief Checks whether a location is within the bounds of the engine
  schematic
  @param row The row to check
  @param col The column to check
  @return True if the location is within the bounds
  */
  bool isWithinBounds(int row, int col) const;
};

}  // namespace engine_checker
}  // namespace day_3
}  // namespace advent_of_code_2023
