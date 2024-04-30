#include <algorithm>

#include "day_4/prize_checker.hpp"
#include "day_4/scratch_card.hpp"
#include "day_4/utils.hpp"
#include "gtest/gtest.h"

TEST(ScratchCard, Basic) {
  auto data = "Card  50:  8 19 40  4 | 82 98 23 31 83  6";

  auto scratch_card =
      advent_of_code_2023::day_4::scratch_card::ScratchCard(data);

  EXPECT_EQ(scratch_card.card_id_, 50);

  std::vector<int64_t> expected_winning_numbers{8, 19, 40, 4};
  EXPECT_EQ(scratch_card.winning_numbers_, expected_winning_numbers);

  std::vector<int64_t> expected_card_numbers{82, 98, 23, 31, 83, 6};
  EXPECT_EQ(scratch_card.card_numbers_, expected_card_numbers);
}

TEST(PrizeChecker, CalculatePoints) {
  auto data = "Card  50:  6 19 23 82 4 | 82 98 23 31 83  6";

  auto scratch_card =
      advent_of_code_2023::day_4::scratch_card::ScratchCard(data);

  auto prize_checker =
      advent_of_code_2023::day_4::prize_checker::PrizeChecker(scratch_card);

  EXPECT_EQ(prize_checker.calculateTotalPoints(), 4);
}

TEST(PrizeChecker, CalculatePrize) {
  std::vector<std::string> data = {
      "Card 1: 41 49 83 17 15 | 83 86  6 31 17  9 48 53",
      "Card 2: 13 32 20 16 60 | 61 30 68 82 17 32 24 19",
      "Card 3:  0 22 53 59 44 | 69 82 63 72 16 21 14  1",
  };

  auto scratch_cards =
      advent_of_code_2023::day_4::utils::parseScratchCards(data);

  auto prize_checker =
      advent_of_code_2023::day_4::prize_checker::PrizeChecker(scratch_cards);

  // Card 1 has two matches, we get Cards 2 and 3 -> 3 cards total
  // Card 2 has one match, we get Card 3 -> 5 cards total
  // Card 3 has no matches, no prizes -> 6 cards total
  // Prize card 2 has one match, so we get Card 3 -> 7 cards total
  // Prize card 3 has no matches, no prizes -> 7 cards total
  // Prize card 3 has no matches, no prizes -> 7 cards total
  EXPECT_EQ(prize_checker.calculateTotalPrize(), 7);
}

TEST(Day4Part1, CalculatePoints) {
  std::vector<std::string> data = {
      "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
      "Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
      "Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
      "Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
      "Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
      "Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11",
  };

  auto scratch_cards =
      advent_of_code_2023::day_4::utils::parseScratchCards(data);

  auto prize_checker =
      advent_of_code_2023::day_4::prize_checker::PrizeChecker(scratch_cards);

  EXPECT_EQ(prize_checker.calculateTotalPoints(), 13);
}

TEST(Day4Part2, CalculatePrize) {
  std::vector<std::string> data = {
      "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
      "Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
      "Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
      "Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
      "Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
      "Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11",
  };

  auto scratch_cards =
      advent_of_code_2023::day_4::utils::parseScratchCards(data);

  auto prize_checker =
      advent_of_code_2023::day_4::prize_checker::PrizeChecker(scratch_cards);

  EXPECT_EQ(prize_checker.calculateTotalPrize(), 30);
}
