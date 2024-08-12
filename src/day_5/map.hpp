
#include <cstdint>
#include <vector>

namespace advent_of_code_2023 {
namespace day_5 {
namespace map {

class Map {
 public:
  Map();

  void addData(uint32_t source, uint32_t destination, uint32_t range);

  uint32_t getDestination(uint32_t source) const;

 private:
  struct Pair {
    uint32_t source;
    uint32_t destination;
    uint32_t range;
  };

  std::vector<Pair> map_;
};
}  // namespace map
}  // namespace day_5
}  // namespace advent_of_code_2023
