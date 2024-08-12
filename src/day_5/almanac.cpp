#include "almanac.hpp"
#include "common/utils.hpp"

namespace advent_of_code_2023 {
namespace day_5 {
namespace almanac {

Almanac::Almanac(std::vector<std::string> raw_data)
    : seeds_{},
      seed_soil_map_{},
      soil_fertilizer_map_{},
      fertilizer_water_map_{},
      water_light_map_{},
      light_temperature_map_{},
      temperature_humedity_map_{},
      humedity_location_map_{} {
  std::string group = "";

  for (auto& line : raw_data) {
    if (line.find("seeds:") != std::string::npos) {
      auto seeds_data = common::utils::splitString(line, ": ")[1];
      for (auto& seed : common::utils::splitString(seeds_data, " ")) {
        seeds_.push_back(std::stol(seed));
      }

      continue;
    } else if (line.find("seed-to-soil map:") != std::string::npos) {
      group = "seed-to-soil";
      continue;
    } else if (line.find("soil-to-fertilizer map:") != std::string::npos) {
      group = "soil-to-fertilizer";
      continue;
    } else if (line.find("fertilizer-to-water map:") != std::string::npos) {
      group = "fertilizer-to-water";
      continue;
    } else if (line.find("water-to-light map:") != std::string::npos) {
      group = "water-to-light";
      continue;
    } else if (line.find("light-to-temperature map:") != std::string::npos) {
      group = "light-to-temperature";
      continue;
    } else if (line.find("temperature-to-humidity map:") != std::string::npos) {
      group = "temperature-to-humidity";
      continue;
    } else if (line.find("humidity-to-location map:") != std::string::npos) {
      group = "humidity-to-location";
      continue;
    } else if (line.empty()) {
      group = "";
      continue;
    }

    auto range_raw_data = common::utils::splitString(line, " ");
    auto range_data = std::array<uint32_t, 3>{
        static_cast<uint32_t>(std::stol(range_raw_data.at(0))),
        static_cast<uint32_t>(std::stol(range_raw_data.at(1))),
        static_cast<uint32_t>(std::stol(range_raw_data.at(2))),
    };

    if (group == "seed-to-soil") {
      seed_soil_map_.addData(range_data.at(0), range_data.at(1),
                             range_data.at(2));
    } else if (group == "soil-to-fertilizer") {
      soil_fertilizer_map_.addData(range_data.at(0), range_data.at(1),
                                   range_data.at(2));
    } else if (group == "fertilizer-to-water") {
      fertilizer_water_map_.addData(range_data.at(0), range_data.at(1),
                                    range_data.at(2));
    } else if (group == "water-to-light") {
      water_light_map_.addData(range_data.at(0), range_data.at(1),
                               range_data.at(2));
    } else if (group == "light-to-temperature") {
      light_temperature_map_.addData(range_data.at(0), range_data.at(1),
                                     range_data.at(2));
    } else if (group == "temperature-to-humidity") {
      temperature_humedity_map_.addData(range_data.at(0), range_data.at(1),
                                        range_data.at(2));
    } else if (group == "humidity-to-location") {
      humedity_location_map_.addData(range_data.at(0), range_data.at(1),
                                     range_data.at(2));
    }
  };
}

Almanac::Almanac(std::vector<uint32_t> seeds,
                 std::vector<std::array<uint32_t, 3>> seed_soil_data,
                 std::vector<std::array<uint32_t, 3>> soil_fertilizer_data,
                 std::vector<std::array<uint32_t, 3>> fertilizer_water_data,
                 std::vector<std::array<uint32_t, 3>> water_light_data,
                 std::vector<std::array<uint32_t, 3>> light_temperature_data,
                 std::vector<std::array<uint32_t, 3>> temperature_humedity_data,
                 std::vector<std::array<uint32_t, 3>> humedity_location_data)
    : seeds_{seeds},
      seed_soil_map_{},
      soil_fertilizer_map_{},
      fertilizer_water_map_{},
      water_light_map_{},
      light_temperature_map_{},
      temperature_humedity_map_{},
      humedity_location_map_{} {
  auto fill_map = [](const std::vector<std::array<uint32_t, 3>>& data,
                     map::Map& map) {
    for (const auto& item : data) {
      map.addData(item.at(0), item.at(1), item.at(2));
    }
  };

  fill_map(seed_soil_data, seed_soil_map_);
  fill_map(soil_fertilizer_data, soil_fertilizer_map_);
  fill_map(fertilizer_water_data, fertilizer_water_map_);
  fill_map(water_light_data, water_light_map_);
  fill_map(light_temperature_data, light_temperature_map_);
  fill_map(temperature_humedity_data, temperature_humedity_map_);
  fill_map(humedity_location_data, humedity_location_map_);
}

uint32_t Almanac::getSoilFromSeed(uint32_t seed) const {
  return seed_soil_map_.getDestination(seed);
}

uint32_t Almanac::getFertilizerFromSoil(uint32_t soil) const {
  return soil_fertilizer_map_.getDestination(soil);
}

uint32_t Almanac::getWaterFromFertilizer(uint32_t fertilizer) const {
  return fertilizer_water_map_.getDestination(fertilizer);
}

uint32_t Almanac::getLightFromWater(uint32_t water) const {
  return water_light_map_.getDestination(water);
}

uint32_t Almanac::getTemperatureFromLight(uint32_t light) const {
  return light_temperature_map_.getDestination(light);
}

uint32_t Almanac::getHumedityFromTemperature(uint32_t temperature) const {
  return temperature_humedity_map_.getDestination(temperature);
}

uint32_t Almanac::getLocationFromHumedity(uint32_t humedity) const {
  return humedity_location_map_.getDestination(humedity);
}

uint32_t Almanac::getLocationFromSeed(uint32_t seed) const {
  auto soil = getSoilFromSeed(seed);
  auto fertilizer = getFertilizerFromSoil(soil);
  auto water = getWaterFromFertilizer(fertilizer);
  auto light = getLightFromWater(water);
  auto temperature = getTemperatureFromLight(light);
  auto humedity = getHumedityFromTemperature(temperature);
  auto location = getLocationFromHumedity(humedity);

  return location;
}

std::vector<uint32_t> Almanac::getSeedsSimple() const {
  return seeds_;
}

std::vector<uint32_t> Almanac::getSeedsPair() const {
  std::vector<uint32_t> seeds{};

  for (uint32_t i = 0; i < seeds_.size(); i += 2) {
    uint32_t seed_source = seeds_.at(i);
    uint32_t seed_destination = seeds_.at(i + 1);

    for (uint32_t offset = 0; offset < seed_destination; offset++) {
      seeds.push_back(seed_source + offset);
    }
  }

  return seeds;
}

uint32_t Almanac::getMinLocation(std::vector<uint32_t> seeds) const {
  auto min_location = std::numeric_limits<uint32_t>::max();

  for (auto& seed : seeds) {
    auto location = getLocationFromSeed(seed);

    if (location < min_location) {
      min_location = location;
    }
  }

  return min_location;
}

}  // namespace almanac
}  // namespace day_5
}  // namespace advent_of_code_2023
