#include <iostream>

#include "common/utils.hpp"
#include "prize_checker.hpp"
#include "scratch_card.hpp"
#include "utils.hpp"

int main() {
  const std::string data_path = "data/day_4.txt";
  const std::vector<std::string> input_data =
      advent_of_code_2023::common::utils::readInput(data_path);

  auto scratch_cards =
      advent_of_code_2023::day_4::utils::parseScratchCards(input_data);

  auto prize_checker =
      advent_of_code_2023::day_4::prize_checker::PrizeChecker(scratch_cards);

  // Part 1
  std::cout << "Part 1 -> Scratch cards total points: "
            << prize_checker.calculateTotalPoints() << std::endl;

  // Part 2
  std::cout << "Part 2 -> Total cards including prizes: "
            << prize_checker.calculateTotalPrize() << std::endl;
}