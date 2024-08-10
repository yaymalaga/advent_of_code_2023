#pragma once

#include <cstdint>
#include <string>

namespace advent_of_code_2023 {
namespace day_2 {
namespace cubes_set {

class CubesSet {
 public:
  /*
 @brief Constructor
 @param green_cubes The number of green cubes
 @param red_cubes The number of red cubes
 @param blue_cubes The number of blue cubes
 */
  CubesSet(const std::uint8_t green_cubes,
           const std::uint8_t red_cubes,
           const std::uint8_t blue_cubes);

  /*
  @brief Constructor
  @param cubes_data The cubes set as a raw string.
  @details Example input: "10 green, 5 blue, 1 red"
  */
  CubesSet(const std::string& cubes_data);

  ~CubesSet() = default;

  /*
  @brief Gets the number of green cubes
  */
  std::uint8_t getGreenCubes() const { return green_cubes_; }

  /*
  @brief Gets the number of red cubes
  */
  std::uint8_t getRedCubes() const { return red_cubes_; }

  /*
  @brief Gets the number of blue cubes
  */
  std::uint8_t getBlueCubes() const { return blue_cubes_; }

 private:
  // The number of cubes of each color
  std::uint8_t green_cubes_;
  std::uint8_t red_cubes_;
  std::uint8_t blue_cubes_;

  /*
  @brief Parses the input string and returns the number of cubes of each color
  @details When parsing, unknown colors or quantities are ignored. In case of
  repeting a color, its quantity will be overwritten.
  @param cubes_data The string data to parse. Example input: "10 green, 5 blue,
  1 red"
  @return A tuple with the number of cubes of each color. First element is green
  cubes, second red ones and the third blue ones
  */
  std::tuple<uint8_t, uint8_t, uint8_t> parseInput(
      const std::string& cubes_data) const;
};

}  // namespace cubes_set
}  // namespace day_2
}  // namespace advent_of_code_2023
