#pragma once

#include <cstdint>
#include <string>

namespace advent_of_code_2023::day_1::utils {

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

}  // namespace advent_of_code_2023::day_1::utils
