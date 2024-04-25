#include "day_2/cubes_set.hpp"
#include "day_2/game.hpp"
#include "day_2/game_helper.hpp"
#include "gtest/gtest.h"

TEST(CubesSet, Basic) {
  auto cubesSet = advent_of_code_2023::day_2::cubes_set::CubesSet(10, 5, 1);

  // test each color
  EXPECT_EQ(cubesSet.getGreenCubes(), 10);
  EXPECT_EQ(cubesSet.getRedCubes(), 5);
  EXPECT_EQ(cubesSet.getBlueCubes(), 1);
}

TEST(CubesSet, Parsing) {
  auto cubesSet = advent_of_code_2023::day_2::cubes_set::CubesSet(
      "10 green, 5 blue, 1 red");

  // test each color
  EXPECT_EQ(cubesSet.getGreenCubes(), 10);
  EXPECT_EQ(cubesSet.getRedCubes(), 1);
  EXPECT_EQ(cubesSet.getBlueCubes(), 5);
}

TEST(CubesSet, ParsingWrongInput) {
  auto cubesSet = advent_of_code_2023::day_2::cubes_set::CubesSet(
      " green, 1 yellow, 2 red, 3 red");

  // test each color
  EXPECT_EQ(cubesSet.getGreenCubes(), 0);
  EXPECT_EQ(cubesSet.getRedCubes(), 3);
  EXPECT_EQ(cubesSet.getBlueCubes(), 0);
}

TEST(Game, Parsing) {
  auto game = advent_of_code_2023::day_2::game::Game(
      "Game 10: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green");

  // test each color
  EXPECT_EQ(game.getId(), 10);
  EXPECT_EQ(game.getData().size(), 3);
  EXPECT_EQ(game.getData()[2].getGreenCubes(), 2);
  EXPECT_EQ(game.getData()[2].getBlueCubes(), 0);
  EXPECT_EQ(game.getData()[2].getRedCubes(), 0);
}

TEST(Game, ParsingWrongInput) {
  auto game = advent_of_code_2023::day_2::game::Game("Game a: 3 yellow, 4 red");

  // test each color
  EXPECT_EQ(game.getId(), 0);
  EXPECT_EQ(game.getData().size(), 1);
  EXPECT_EQ(game.getData()[0].getGreenCubes(), 0);
  EXPECT_EQ(game.getData()[0].getBlueCubes(), 0);
  EXPECT_EQ(game.getData()[0].getRedCubes(), 4);
}

TEST(Day1Part1, CheckGames) {
  std::vector<std::string> data = {
      "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
      "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
      "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 "
      "red",
      "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 "
      "red",
      "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green",
  };

  auto game_helper = advent_of_code_2023::day_2::game_helper::GameHelper(data);

  auto bag_content =
      advent_of_code_2023::day_2::cubes_set::CubesSet(13, 12, 14);

  EXPECT_EQ(game_helper.getPossibleGamesValue(bag_content), 8);
}
TEST(Day1Part2, CheckBagsPower) {
  std::vector<std::string> data = {
      "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
      "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
      "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 "
      "red",
      "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 "
      "red",
      "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green",
  };

  auto game_helper = advent_of_code_2023::day_2::game_helper::GameHelper(data);

  EXPECT_EQ(game_helper.getMinBagsPower(), 2286);
}