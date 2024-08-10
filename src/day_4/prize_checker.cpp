#include <algorithm>
#include <cmath>

#include "prize_checker.hpp"

namespace advent_of_code_2023 {
namespace day_4 {
namespace prize_checker {

PrizeChecker::PrizeChecker(
    const std::vector<scratch_card::ScratchCard>& scratch_cards)
    : scratch_cards_{scratch_cards} {};

PrizeChecker::PrizeChecker(const scratch_card::ScratchCard& scratch_card)
    : scratch_cards_{scratch_card} {};

int64_t PrizeChecker::calculateTotalPoints() const {
  int64_t total_prize = 0;

  for (const auto& scratch_card : scratch_cards_) {
    total_prize += calculatePoints(scratch_card);
  }

  return total_prize;
}

int64_t PrizeChecker::calculatePoints(
    const scratch_card::ScratchCard& scratch_card) {
  auto matching_numbers = getMatchesNumber(scratch_card);

  if (matching_numbers > 1) {
    return pow(2, matching_numbers - 1);
  }

  return matching_numbers;
}

size_t PrizeChecker::getMatchesNumber(
    const scratch_card::ScratchCard& scratch_card) {
  size_t number_matches = 0;

  for (const auto& winning_number : scratch_card.winning_numbers_) {
    auto search = std::find(scratch_card.card_numbers_.begin(),
                            scratch_card.card_numbers_.end(), winning_number);

    if (search != scratch_card.card_numbers_.end()) {
      number_matches++;
    }
  }

  return number_matches;
}

std::vector<scratch_card::ScratchCard> PrizeChecker::getPrize(
    const scratch_card::ScratchCard& scratch_card) const {
  std::vector<scratch_card::ScratchCard> prizes;

  auto matches_number = getMatchesNumber(scratch_card);

  // Generate cards' id based on the number of matches by appling an offset to
  // the current cards' id
  for (size_t i = 1; i <= matches_number; i++) {
    auto card_number = scratch_card.card_id_ + i;
    // Cards id starts at 1 while the array at 0
    auto card = scratch_cards_[card_number - 1];

    prizes.push_back(card);
  }

  return prizes;
}

// TODO: This approach is actually quite slow as we need to recalculate the
// matches and prizes for each card, turning it into a huge recursive function.
// Ideally, we would cache the results to avoid recomputing them
int64_t PrizeChecker::calculateTotalPrize() const {
  std::vector<scratch_card::ScratchCard> processed_cards;

  std::vector<scratch_card::ScratchCard> cards_queue = scratch_cards_;

  while (!cards_queue.empty()) {
    // Take the latest card from the queue
    auto scratch_card = cards_queue.back();
    cards_queue.pop_back();

    // Get the prize for the current card
    auto prize = getPrize(scratch_card);
    for (const auto& card : prize) {
      cards_queue.push_back(card);
    }

    // Add the card taken to the processed cards list
    processed_cards.push_back(scratch_card);
  }

  return processed_cards.size();
}

}  // namespace prize_checker
}  // namespace day_4
}  // namespace advent_of_code_2023
