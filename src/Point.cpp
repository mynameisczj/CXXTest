#include "Point.h"

namespace adas {
Point::Point(const int x, const int y) noexcept : x(x), y(y) {}
Point::Point(const Point& rhs) noexcept {
  this->x = rhs.x;
  this->y = rhs.y;
}
Point& Point::operator=(const Point& rhs) noexcept {
  this->x = rhs.x;
  this->y = rhs.y;
  return *this;
}
Point& Point::operator+=(const Point& rhs) noexcept {
  this->x += rhs.x;
  this->y += rhs.y;
  return *this;
}
int Point::GetX(void) const noexcept { return this->x; }
int Point::GetY(void) const noexcept { return this->y; }
}  // namespace adas
