#include "day_3/engine_checker.hpp"
#include "day_3/engine_schematic.hpp"
#include "gtest/gtest.h"

TEST(EngineSchematic, Basic) {
  std::vector<std::string> data = {
      "467..114..",
      "...*......",
  };

  auto engine_schematic =
      advent_of_code_2023::day_3::engine_schematic::EngineSchematic(data);

  EXPECT_EQ(engine_schematic.getColsNumber(), 10);
  EXPECT_EQ(engine_schematic.getRowsNumber(), 2);
  EXPECT_EQ(engine_schematic.getItem(1, 3).value_or('0'), '*');
  EXPECT_FALSE(engine_schematic.getItem(54, 1).has_value());
}

TEST(EngineChecker, SymbolsLocation) {
  std::vector<std::string> data = {
      "467..114..",
      "...*......",
      "#.35..633.",
  };

  auto engine_schematic =
      advent_of_code_2023::day_3::engine_schematic::EngineSchematic(data);

  auto engine_checker =
      advent_of_code_2023::day_3::engine_checker::EngineChecker(
          engine_schematic);

  auto symbols_location = engine_checker.getSymbolsLocation();

  EXPECT_EQ(symbols_location.size(), 2);
  EXPECT_EQ(symbols_location[0].row, 1);
  EXPECT_EQ(symbols_location[0].col, 3);
  EXPECT_EQ(symbols_location[1].row, 2);
  EXPECT_EQ(symbols_location[1].col, 0);
}

TEST(EngineChecker, SymbolsLocationFilter) {
  std::vector<std::string> data = {
      "467..114.*",
      "...*...&..",
      "#.35..633.",
  };

  auto engine_schematic =
      advent_of_code_2023::day_3::engine_schematic::EngineSchematic(data);

  auto engine_checker =
      advent_of_code_2023::day_3::engine_checker::EngineChecker(
          engine_schematic);

  auto symbols_location = engine_checker.getSymbolsLocation({'*'});

  EXPECT_EQ(symbols_location.size(), 2);
  EXPECT_EQ(symbols_location[0].row, 0);
  EXPECT_EQ(symbols_location[0].col, 9);
  EXPECT_EQ(symbols_location[1].row, 1);
  EXPECT_EQ(symbols_location[1].col, 3);
}

TEST(EngineChecker, AdjacentDigits) {
  std::vector<std::string> data = {
      "467..114..",
      "...*......",
      "..35..633.",
  };

  auto engine_schematic =
      advent_of_code_2023::day_3::engine_schematic::EngineSchematic(data);

  auto engine_checker =
      advent_of_code_2023::day_3::engine_checker::EngineChecker(
          engine_schematic);

  auto symbols_location = engine_checker.getSymbolsLocation();

  auto digits_location = engine_checker.getAdjacentDigits(symbols_location[0]);

  EXPECT_EQ(digits_location.size(), 2);
  EXPECT_EQ(digits_location[0].row, 2);
  EXPECT_EQ(digits_location[0].col, 3);
  EXPECT_EQ(digits_location[1].row, 0);
  EXPECT_EQ(digits_location[1].col, 2);
}

TEST(EngineChecker, NumberFromDigit) {
  std::vector<std::string> data = {
      "467..114..",
      "...*......",
      "..351.633.",
  };

  auto engine_schematic =
      advent_of_code_2023::day_3::engine_schematic::EngineSchematic(data);

  auto engine_checker =
      advent_of_code_2023::day_3::engine_checker::EngineChecker(
          engine_schematic);

  auto adjacent_number_1 = engine_checker.findNumberFromDigit({0, 2});

  EXPECT_EQ(adjacent_number_1, 467);

  auto adjacent_number_2 = engine_checker.findNumberFromDigit({2, 3});

  EXPECT_EQ(adjacent_number_2, 351);
}

TEST(Day3Part1, GetPartsSum) {
  std::vector<std::string> data = {
      "467..114..", "...*......", "..35..633.", "......#...", "617*......",
      ".....+.58.", "..592.....", "......755.", "...$.*....", ".664.598..",
  };

  auto engine_schematic =
      advent_of_code_2023::day_3::engine_schematic::EngineSchematic(data);

  auto engine_checker =
      advent_of_code_2023::day_3::engine_checker::EngineChecker(
          engine_schematic);

  EXPECT_EQ(engine_checker.getPartsNumberSum(), 4361);
}

TEST(Day3Part2, GetGearsSum) {
  std::vector<std::string> data = {
      "467..114..", "...*......", "..35..633.", "......#...", "617*......",
      ".....+.58.", "..592.....", "......755.", "...$.*....", ".664.598..",
  };

  auto engine_schematic =
      advent_of_code_2023::day_3::engine_schematic::EngineSchematic(data);

  auto engine_checker =
      advent_of_code_2023::day_3::engine_checker::EngineChecker(
          engine_schematic);

  EXPECT_EQ(engine_checker.getGearsSum(), 467835);
}
