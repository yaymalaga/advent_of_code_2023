#pragma once

#include <optional>
#include <string>
#include <vector>

namespace advent_of_code_2023 {
namespace day_3 {
namespace engine_schematic {

class EngineSchematic {
 public:
  /*
  @brief Constructor
  @param data The list of strings that describes the engine schematic
  */
  EngineSchematic(const std::vector<std::string>& data);

  ~EngineSchematic() = default;

  /*
  @brief Get the item at the provided row and column. It is checked that the
  item is in bounds.
  @param row The row of the item
  @param col The column of the item
  @return The item at the provided row and column or empty if out of bounds
  */
  std::optional<char> getItem(size_t row, size_t col) const;

  /*
  @brief Getter for the number of rows in the schematic
  @return The number of rows in the schematic
  */
  size_t getRowsNumber() const { return n_rows_; }

  /*
  @brief Getter for the number of columns in the schematic
  @return The number of columns in the schematic
  */
  size_t getColsNumber() const { return n_cols_; }

 private:
  // The data of the schematic
  const std::vector<std::string> data_;

  // The number of rows of the schematic
  const size_t n_rows_ = 0;

  // The number of columns of the schematic
  const size_t n_cols_ = 0;

  // Check if the provided row and column are in bounds
  bool isInBounds(size_t row, size_t col) const;
};

}  // namespace engine_schematic
}  // namespace day_3
}  // namespace advent_of_code_2023