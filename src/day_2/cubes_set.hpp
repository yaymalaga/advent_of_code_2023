#pragma once

#include <cstdint>
#include <string>

namespace advent_of_code_2023::day_2::cubes_set {

class CubesSet {
 public:
  CubesSet(const CubesSet&) = default;
  CubesSet(CubesSet&&) = delete;
  CubesSet& operator=(const CubesSet&) = default;
  CubesSet& operator=(CubesSet&&) = delete;
  ~CubesSet() = default;

  /*
  @brief Internal struct to store the cubes count and make the constructor more
  // readable
  */
  struct CubesData {
    uint8_t green_number;
    uint8_t red_number;
    uint8_t blue_number;
  };

  /*
   @brief Constructor
   @param green_cubes The number of green cubes
   @param red_cubes The number of red cubes
   @param blue_cubes The number of blue cubes
   */
  explicit CubesSet(const CubesData& cubes_data);

  /*
  @brief Constructor
  @param cubes_data The cubes set as a raw string.
  @details Example input: "10 green, 5 blue, 1 red"
  */
  explicit CubesSet(const std::string& cubes_raw_data);

  /*
  @brief Gets the number of green cubes
  */
  [[nodiscard]] uint8_t getGreenCubes() const {
    return cubes_data_.green_number;
  }

  /*
  @brief Gets the number of red cubes
  */
  [[nodiscard]] uint8_t getRedCubes() const { return cubes_data_.red_number; }

  /*
  @brief Gets the number of blue cubes
  */
  [[nodiscard]] uint8_t getBlueCubes() const { return cubes_data_.blue_number; }

 private:
  // The number of cubes of each color
  CubesData cubes_data_;

  /*
  @brief Parses the input string and returns the number of cubes of each
  color
  @details When parsing, unknown colors or quantities are ignored. In case
  of repeting a color, its quantity will be overwritten.
  @param cubes_data The string data to parse. Example input: "10 green, 5
  blue, 1 red"
  @return A tuple with the number of cubes of each color. First element is
  green cubes, second red ones and the third blue ones
  */
  static CubesData parseInput(const std::string& cubes_raw_data);
};

}  // namespace advent_of_code_2023::day_2::cubes_set
