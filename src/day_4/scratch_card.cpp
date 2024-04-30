#include "scratch_card.hpp"
#include "common/utils.hpp"

namespace advent_of_code_2023 {
namespace day_4 {
namespace scratch_card {

ScratchCard::ScratchCard(const std::string& data)
    : card_id_{parseCardId(data)},
      winning_numbers_{parseNumbers(data, NumbersType::WinningNumbers)},
      card_numbers_{parseNumbers(data, NumbersType::CardNumbers)} {}

int64_t ScratchCard::parseCardId(const std::string& data) {
  auto id_data = common::utils::splitString(data, ": ")[0];
  auto id_number = common::utils::splitString(id_data, "Card ")[1];

  return std::stoi(id_number);
}

std::vector<int64_t> ScratchCard::parseNumbers(const std::string& data,
                                               const NumbersType numbers_type) {
  auto numbers_data = common::utils::splitString(data, ": ")[1];

  auto group = numbers_type == NumbersType::WinningNumbers ? 0 : 1;
  auto numbers_group = common::utils::splitString(numbers_data, " | ")[group];

  std::vector<int64_t> numbers;

  // Numbers are 1 or 2 digits long separated by spaces. Thus, we iterate 3
  // chars at the time, converting the first two to an int and skipping the last
  // one which is the whitespace
  for (size_t i = 0; i < numbers_group.size(); i += 3) {
    auto number = std::stoi(numbers_group.substr(i, 2));
    numbers.push_back(number);
  }

  return numbers;
}

}  // namespace scratch_card
}  // namespace day_4
}  // namespace advent_of_code_2023