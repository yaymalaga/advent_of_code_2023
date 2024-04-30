#pragma once

#include <vector>

#include "scratch_card.hpp"

namespace advent_of_code_2023 {
namespace day_4 {
namespace prize_checker {

class PrizeChecker {
 public:
  /*
  @brief Constructor
  @param scratch_cards The list of scratch cards
  */
  PrizeChecker(const std::vector<scratch_card::ScratchCard>& scratch_cards);

  /*
  @brief Constructor
  @param scratch_card The scratch card
  */
  PrizeChecker(const scratch_card::ScratchCard& scratch_card);

  ~PrizeChecker() = default;

  /*
  @brief Calculate the total points
  @details Total points are obtained by summing the points earned by each card
  @return The total points
  */
  int64_t calculateTotalPoints() const;

  /*
  @brief Calculate the total prize
  @details Total prize is given by the number of cards including their prizes
  @return The total prize
  */
  int64_t calculateTotalPrize() const;

 private:
  // The list of scratch cards
  const std::vector<scratch_card::ScratchCard> scratch_cards_;

  /*
@brief Get the number of matches between the card numbers and winning numbers
@param scratch_card The scratch card to check
@return The number of matches
*/
  static size_t getMatchesNumber(const scratch_card::ScratchCard& scratch_card);

  /*
  @brief Get the points for the current card
  @param scratch_card The scratch card to check
  @details The points are obtained by calculating 2 to the power of the number
  of correct matches between the cards numbers and winning numbers. In case of
  only 1 match, the card is considered only counts as 1 point.
  @return The points of the card
  */
  static int64_t calculatePoints(const scratch_card::ScratchCard& scratch_card);

  /*
  @brief Get the prizes for the current card
  @details The prize is obtained by summing the number of total cards, taking
  into account the prize for each card are new cards with the consecutives
  numbers of the original cards, as many as matching numbers.
  @param scratch_card The scratch card to check
  @return The prizes of the card
  */
  std::vector<scratch_card::ScratchCard> getPrize(
      const scratch_card::ScratchCard& scratch_card) const;
};

}  // namespace prize_checker
}  // namespace day_4
}  // namespace advent_of_code_2023