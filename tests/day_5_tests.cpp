#include "day_5/almanac.hpp"
#include "gtest/gtest.h"

advent_of_code_2023::day_5::almanac::Almanac createTestAlmanac() {
  std::vector<std::string> raw_data = {
      "seeds: 79 14 55 13",
      "",
      "seed-to-soil map:",
      "50 98 2",
      "52 50 48",
      "",
      "soil-to-fertilizer map:",
      "0 15 37",
      "37 52 2",
      "39 0 15",
      "",
      "fertilizer-to-water map:",
      "49 53 8",
      "0 11 42",
      "42 0 7",
      "57 7 4",
      "",
      "water-to-light map:",
      "88 18 7",
      "18 25 70",
      "",
      "light-to-temperature map:",
      "45 77 23",
      "81 45 19",
      "68 64 13",
      "",
      "temperature-to-humidity map:",
      "0 69 1",
      "1 0 69",
      "",
      "humidity-to-location map:",
      "60 56 37",
      "56 93 4",
  };

  auto almanac = advent_of_code_2023::day_5::almanac::Almanac(raw_data);

  return almanac;
}

TEST(Map, Basic) {
  auto map = advent_of_code_2023::day_5::map::Map();

  // Swap all the values below
  map.addData(50, 98, 2);
  map.addData(52, 50, 48);

  EXPECT_EQ(map.getDestination(98), 50);
  EXPECT_EQ(map.getDestination(99), 51);
  EXPECT_EQ(map.getDestination(51), 53);
  EXPECT_EQ(map.getDestination(52), 54);
  EXPECT_EQ(map.getDestination(55), 57);
  EXPECT_EQ(map.getDestination(79), 81);
  EXPECT_EQ(map.getDestination(97), 99);

  EXPECT_EQ(map.getDestination(13), 13);
  EXPECT_EQ(map.getDestination(14), 14);
  EXPECT_EQ(map.getDestination(100), 100);
  EXPECT_EQ(map.getDestination(320), 320);
}

TEST(Almanac, Basic) {
  auto seeds = std::vector<uint32_t>{79, 14, 55, 13};

  auto seed_soil_data = std::vector<std::array<uint32_t, 3>>{
      {50, 98, 2},
      {52, 50, 48},
  };

  auto soil_fertilizer_data = std::vector<std::array<uint32_t, 3>>{
      {0, 15, 37},
      {37, 52, 2},
      {39, 0, 15},
  };

  auto fertilizer_water_data = std::vector<std::array<uint32_t, 3>>{
      {49, 53, 8},
      {0, 11, 42},
      {42, 0, 7},
      {57, 7, 4},
  };

  auto water_light_data = std::vector<std::array<uint32_t, 3>>{
      {88, 18, 7},
      {18, 25, 70},
  };

  auto light_temperature_data = std::vector<std::array<uint32_t, 3>>{
      {45, 77, 23},
      {81, 45, 19},
      {68, 64, 13},
  };

  auto temperature_humedity_data = std::vector<std::array<uint32_t, 3>>{
      {0, 69, 1},
      {1, 0, 69},
  };

  auto humedity_location_data = std::vector<std::array<uint32_t, 3>>{
      {60, 56, 37},
      {56, 93, 4},
  };

  auto almanac = advent_of_code_2023::day_5::almanac::Almanac(
      seeds, seed_soil_data, soil_fertilizer_data, fertilizer_water_data,
      water_light_data, light_temperature_data, temperature_humedity_data,
      humedity_location_data);

  // Seed 79
  EXPECT_EQ(almanac.getSoilFromSeed(79), 81);
  EXPECT_EQ(almanac.getFertilizerFromSoil(81), 81);
  EXPECT_EQ(almanac.getWaterFromFertilizer(81), 81);
  EXPECT_EQ(almanac.getLightFromWater(81), 74);
  EXPECT_EQ(almanac.getTemperatureFromLight(74), 78);
  EXPECT_EQ(almanac.getHumedityFromTemperature(78), 78);
  EXPECT_EQ(almanac.getLocationFromHumedity(78), 82);

  // Seed 14
  EXPECT_EQ(almanac.getSoilFromSeed(14), 14);
  EXPECT_EQ(almanac.getFertilizerFromSoil(14), 53);
  EXPECT_EQ(almanac.getWaterFromFertilizer(53), 49);
  EXPECT_EQ(almanac.getLightFromWater(49), 42);
  EXPECT_EQ(almanac.getTemperatureFromLight(42), 42);
  EXPECT_EQ(almanac.getHumedityFromTemperature(42), 43);
  EXPECT_EQ(almanac.getLocationFromHumedity(43), 43);

  // Seed 55
  EXPECT_EQ(almanac.getSoilFromSeed(55), 57);
  EXPECT_EQ(almanac.getFertilizerFromSoil(57), 57);
  EXPECT_EQ(almanac.getWaterFromFertilizer(57), 53);
  EXPECT_EQ(almanac.getLightFromWater(53), 46);
  EXPECT_EQ(almanac.getTemperatureFromLight(46), 82);
  EXPECT_EQ(almanac.getHumedityFromTemperature(82), 82);
  EXPECT_EQ(almanac.getLocationFromHumedity(82), 86);

  // Seed 13
  EXPECT_EQ(almanac.getSoilFromSeed(13), 13);
  EXPECT_EQ(almanac.getFertilizerFromSoil(13), 52);
  EXPECT_EQ(almanac.getWaterFromFertilizer(52), 41);
  EXPECT_EQ(almanac.getLightFromWater(41), 34);
  EXPECT_EQ(almanac.getTemperatureFromLight(34), 34);
  EXPECT_EQ(almanac.getHumedityFromTemperature(34), 35);
  EXPECT_EQ(almanac.getLocationFromHumedity(35), 35);
}

TEST(Almanac, Parsing) {
  auto almanac = createTestAlmanac();

  // All seeds location
  EXPECT_EQ(almanac.getLocationFromSeed(79), 82);
  EXPECT_EQ(almanac.getLocationFromSeed(14), 43);
  EXPECT_EQ(almanac.getLocationFromSeed(55), 86);
  EXPECT_EQ(almanac.getLocationFromSeed(13), 35);
}

TEST(Almanac, Part1) {
  auto almanac = createTestAlmanac();
  auto seeds = almanac.getSeedsSimple();

  EXPECT_EQ(seeds.size(), 4);
  EXPECT_EQ(almanac.getMinLocation(seeds), 35);
}

TEST(Almanac, Part2) {
  auto almanac = createTestAlmanac();
  auto seeds = almanac.getSeedsPair();

  EXPECT_EQ(seeds.size(), 27);
  EXPECT_EQ(almanac.getMinLocation(seeds), 46);
}
