#pragma once

#include <string>
#include <vector>

#include "scratch_card.hpp"

namespace advent_of_code_2023 {
namespace day_4 {
namespace utils {

using ScratchCard = advent_of_code_2023::day_4::scratch_card::ScratchCard;

/*
 * @brief Parses the list of scratch cards
 * @param scratch_cards_data The raw data of the scratch cards
 * @return The list of scratch cards
 */
std::vector<ScratchCard> parseScratchCards(
    const std::vector<std::string>& scratch_cards_data);

}  // namespace utils
}  // namespace day_4
}  // namespace advent_of_code_2023
