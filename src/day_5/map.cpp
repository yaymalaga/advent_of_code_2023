#include "map.hpp"

namespace advent_of_code_2023 {
namespace day_5 {
namespace map {

Map::Map() : map_{} {};

void Map::addData(uint32_t destination, uint32_t source, uint32_t range) {
  map_.push_back({source, destination, range});
}

uint32_t Map::getDestination(uint32_t source) const {
  for (const auto& pair : map_) {
    // Range is not inclusive, so source 10 and range 2 will be {10, 11}.
    if (pair.source <= source && source <= pair.source + (pair.range - 1)) {
      auto offset = source - pair.source;
      return pair.destination + offset;
    }
  }

  return source;
}

}  // namespace map
}  // namespace day_5
}  // namespace advent_of_code_2023
