#include <array>
#include <deque>
#include <tuple>

#include "engine_checker.hpp"

namespace advent_of_code_2023 {
namespace day_3 {
namespace engine_checker {

EngineChecker::EngineChecker(
    engine_schematic::EngineSchematic& engine_schematic)
    : engine_schematic_(engine_schematic) {}

std::vector<EngineChecker::Location> EngineChecker::getSymbolsLocation(
    std::optional<char> filter) const {
  std::vector<EngineChecker::Location> symbols_location;

  for (size_t row = 0; row < engine_schematic_.getRowsNumber(); ++row) {
    for (size_t col = 0; col < engine_schematic_.getColsNumber(); ++col) {
      auto item = engine_schematic_.getItem(row, col);

      if (item.has_value() && isSymbol(item.value())) {
        if (filter.has_value() && item.value() != filter.value()) {
          continue;
        }
        symbols_location.push_back({row, col});
      }
    }
  }
  return symbols_location;
}

bool EngineChecker::isSymbol(char item) {
  return !std::isdigit(item) && item != '.';
}

bool EngineChecker::isWithinBounds(int row, int col) const {
  return row >= 0 && col >= 0 &&
         static_cast<size_t>(row) < engine_schematic_.getRowsNumber() &&
         static_cast<size_t>(col) < engine_schematic_.getColsNumber();
}

std::vector<EngineChecker::Location> EngineChecker::getAdjacentDigits(
    Location item_location) const {
  std::vector<EngineChecker::Location> adjacent_digits;

  std::vector<std::array<int, 2>> offsets = {{
      {0, 1},   // left offset
      {0, -1},  // right offset
  }};

  auto isDigit = [this](Location location) -> bool {
    // Check it's between bounds
    if (!isWithinBounds(location.row, location.col)) {
      return false;
    }

    auto item = engine_schematic_.getItem(location.row, location.col);

    return item.has_value() && std::isdigit(item.value());
  };

  // Check for digit in top offset. If empty, check top diagonals too
  Location top_location = {
      item_location.row - 1,
      item_location.col,
  };

  if (isDigit(top_location)) {
    adjacent_digits.push_back(top_location);
  } else {
    offsets.push_back({-1, -1});  // top left diagonal
    offsets.push_back({-1, 1});   // top right diagonal
  }

  // Check for digit in bottom offset. If empty, check bottom diagonals too
  Location bottom_location = {
      item_location.row + 1,
      item_location.col,
  };

  if (isDigit(bottom_location)) {
    adjacent_digits.push_back(bottom_location);
  } else {
    offsets.push_back({1, -1});  // bottom left diagonal
    offsets.push_back({1, 1});   // bottom right diagonal
  }

  // Check extra positions now
  for (const auto& offset : offsets) {
    Location new_location = {
        item_location.row + offset[0],
        item_location.col + offset[1],
    };

    if (isDigit(new_location)) {
      adjacent_digits.push_back(new_location);
    }
  }

  return adjacent_digits;
}

int64_t EngineChecker::findNumberFromDigit(Location digit_location) const {
  std::deque<char> digits = {
      engine_schematic_.getItem(digit_location.row, digit_location.col).value(),
  };

  // Digits can be on the left side or right side. Check every location on the
  // left and right sides until no more digits are found

  const std::array<int, 2> direction = {-1, 1};

  for (const auto& offset : direction) {
    auto new_location = digit_location;

    while (true) {
      new_location.col += offset;

      if (!isWithinBounds(new_location.row, new_location.col)) {
        break;
      }

      auto item = engine_schematic_.getItem(new_location.row, new_location.col);

      if (!item.has_value() || !std::isdigit(item.value())) {
        break;
      }

      if (offset == -1) {
        digits.push_front(item.value());
      } else {
        digits.push_back(item.value());
      }
    }
  }

  return std::stoi(std::string(digits.begin(), digits.end()));
}

int64_t EngineChecker::getPartsNumberSum() const {
  auto symbols_location = getSymbolsLocation({});
  auto sum = 0;

  for (const auto& symbol_location : symbols_location) {
    auto adjacent_digits_location = getAdjacentDigits(symbol_location);

    for (const auto& digit_location : adjacent_digits_location) {
      auto part_number = findNumberFromDigit(digit_location);
      sum += part_number;
    }
  }

  return sum;
}

int64_t EngineChecker::getGearsSum() const {
  auto symbols_location = getSymbolsLocation('*');
  auto sum = 0;

  for (const auto& symbol_location : symbols_location) {
    auto adjacent_digits_location = getAdjacentDigits(symbol_location);

    if (adjacent_digits_location.size() != 2) {
      continue;
    }

    int64_t gear_ratio = 1;

    for (const auto& digit_location : adjacent_digits_location) {
      auto gear_part = findNumberFromDigit(digit_location);
      gear_ratio *= gear_part;
    }

    sum += gear_ratio;
  }

  return sum;
}

}  // namespace engine_checker
}  // namespace day_3
}  // namespace advent_of_code_2023
