#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

namespace advent_of_code_2023 {
namespace day_1 {
namespace utils {

/*
@brief Simple util to convert a character to an integer
@param character The character to convert
@return The result integer
*/
int64_t charToInt(char character);

/*
@brief Simple util to convert an integer to a character
@param digit The integer to convert
@return The result character
*/
char intToChar(int64_t digit);

/*
@brief Replaces all spelled numbers by their actual digits
@param item The string to process
*/
void replaceSpelledNumbers(std::string& item);

/*
@brief The list of written numbers and their corresponding digits
*/
constexpr std::pair<const char*, uint64_t> SPELLED_NUMBERS[] = {
    {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

}  // namespace utils
}  // namespace day_1
}  // namespace advent_of_code_2023