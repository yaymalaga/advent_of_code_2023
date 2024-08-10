#pragma once

#include <string>
#include <vector>

namespace advent_of_code_2023 {
namespace day_4 {
namespace scratch_card {

class ScratchCard {
 public:
  /*
   * @brief Constructor
   * @param data The raw data of the scratch card
   */
  ScratchCard(const std::string& data);

  /// Card id
  const int64_t card_id_;
  /// List of winning numbers
  const std::vector<int64_t> winning_numbers_;
  /// List of card numbers
  const std::vector<int64_t> card_numbers_;

 private:
  /*
   * @brief Parses the id of the card
   * @param data The raw data of the scratch card
   * @return The id of the card
   */
  static int64_t parseCardId(const std::string& data);

  /*
   * @brief Internal data type to select the numbers to parse
   */
  enum class NumbersType {
    WinningNumbers,
    CardNumbers,
  };

  /*
   * @brief Parses the list of numbers
   * @param data The raw data of the scratch card
   * @param numbers_type The type of numbers to parse
   * @return The list of numbers
   */
  static std::vector<int64_t> parseNumbers(const std::string& data,
                                           const NumbersType numbers_type);
};

}  // namespace scratch_card
}  // namespace day_4
}  // namespace advent_of_code_2023
