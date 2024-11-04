#pragma once

#include "Point.h"
namespace adas {
/*
方向类
*/
class Direction final {
 public:
  static const Direction& GetDirection(const char heading) noexcept;

 public:
  Direction(const unsigned index, const char heading) noexcept;

 public:
  const Point& Move(void) const noexcept;
  const Direction& LeftOne(void) const noexcept;
  const Direction& RightOne(void) const noexcept;

  const char GetHeading(void) const noexcept;  // 获取方向字符
 private:
  unsigned index;//方向索引
  char heading;//方向字符
};

}  // namespace adas
