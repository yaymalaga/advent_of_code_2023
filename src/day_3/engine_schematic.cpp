#include "engine_schematic.hpp"

namespace advent_of_code_2023 {
namespace day_3 {
namespace engine_schematic {

EngineSchematic::EngineSchematic(const std::vector<std::string>& data)
    : data_(data),
      n_rows_(data.size()),
      n_cols_(n_rows_ > 0 ? data[0].size() : 0){};

bool EngineSchematic::isInBounds(size_t row, size_t col) const {
  return row < n_rows_ && col < n_cols_;
}

std::optional<char> EngineSchematic::getItem(size_t row, size_t col) const {
  if (!isInBounds(row, col)) {
    return {};
  }
  return data_[row][col];
}

}  // namespace engine_schematic
}  // namespace day_3
}  // namespace advent_of_code_2023