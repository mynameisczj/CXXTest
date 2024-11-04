#pragma once

namespace adas {
class Point final {
 public:
  Point(const int x, const int y) noexcept;      // 带参构造
  Point(const Point& rhs) noexcept;              // 拷贝构造
  Point& operator=(const Point& rhs) noexcept;   // 拷贝赋值
  Point& operator+=(const Point& rhs) noexcept;  // 移动
 public:
  int GetX(void) const noexcept;  // 获取X坐标
  int GetY(void) const noexcept;  // 获取Y坐标
 private:
  int x;
  int y;
};
}  // namespace adas
