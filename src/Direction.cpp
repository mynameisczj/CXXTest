#include "Direction.h"

#include "Point.h"

namespace adas {
static const Direction direction[4] = {{0, 'E'}, {1, 'S'}, {2, 'W'}, {3, 'N'}};
static const Point point[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};  // ESWN

const Direction& Direction::GetDirection(const char heading) noexcept {
  for (const auto& it : direction) {
    if (it.heading == heading) return it;
  }
  return direction[3];
}
Direction::Direction(const unsigned index, const char heading) noexcept
    : index(index), heading(heading) {}

const Point& Direction::Move(void) const noexcept {
  return point[GetDirection(this->heading).index];
}
const Direction& Direction::LeftOne(void) const noexcept {
  return direction[(GetDirection(this->heading).index - 1 + 4) % 4];
}
const Direction& Direction::RightOne(void) const noexcept {
  return direction[(GetDirection(this->heading).index + 1) % 4];
}

const char Direction::GetHeading(void) const noexcept { return this->heading; }
}  // namespace adas
