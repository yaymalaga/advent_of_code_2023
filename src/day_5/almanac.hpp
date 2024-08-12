#include <array>
#include <cstdint>
#include <string>
#include <vector>

#include "day_5/map.hpp"

namespace advent_of_code_2023 {
namespace day_5 {
namespace almanac {

class Almanac {
 public:
  Almanac(std::vector<std::string> raw_data);

  Almanac(std::vector<uint32_t> seeds,
          std::vector<std::array<uint32_t, 3>> seed_soil_data,
          std::vector<std::array<uint32_t, 3>> soil_fertilizer_data,
          std::vector<std::array<uint32_t, 3>> fertilizer_water_data,
          std::vector<std::array<uint32_t, 3>> water_light_data,
          std::vector<std::array<uint32_t, 3>> light_temperature_data,
          std::vector<std::array<uint32_t, 3>> temperature_humedity_data,
          std::vector<std::array<uint32_t, 3>> humedity_location_data);

  std::vector<uint32_t> getSeedsSimple() const;
  std::vector<uint32_t> getSeedsPair() const;

  uint32_t getSoilFromSeed(uint32_t seed) const;
  uint32_t getFertilizerFromSoil(uint32_t soil) const;
  uint32_t getWaterFromFertilizer(uint32_t fertilizer) const;
  uint32_t getLightFromWater(uint32_t water) const;
  uint32_t getTemperatureFromLight(uint32_t light) const;
  uint32_t getHumedityFromTemperature(uint32_t temperature) const;
  uint32_t getLocationFromHumedity(uint32_t humedity) const;

  uint32_t getLocationFromSeed(uint32_t seed) const;

  uint32_t getMinLocation(std::vector<uint32_t> seeds) const;

 private:
  std::vector<uint32_t> seeds_;

  map::Map seed_soil_map_;
  map::Map soil_fertilizer_map_;
  map::Map fertilizer_water_map_;
  map::Map water_light_map_;
  map::Map light_temperature_map_;
  map::Map temperature_humedity_map_;
  map::Map humedity_location_map_;
};
}  // namespace almanac
}  // namespace day_5
}  // namespace advent_of_code_2023
