#include "utils.hpp"

namespace advent_of_code_2023 {
namespace day_4 {
namespace utils {

std::vector<ScratchCard> parseScratchCards(
    const std::vector<std::string>& scratch_cards_data) {
  std::vector<ScratchCard> scratch_cards;
  scratch_cards.reserve(scratch_cards_data.size());

  for (auto& item : scratch_cards_data) {
    auto scratch_card = ScratchCard(item);
    scratch_cards.push_back(scratch_card);
  }

  return scratch_cards;
}

}  // namespace utils
}  // namespace day_4
}  // namespace advent_of_code_2023