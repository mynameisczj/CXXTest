#pragma once

#include "Direction.h"
#include "Executor.h"
#include "point.h"

namespace adas {
class PoseHandler final {
 public:
  PoseHandler(const Pose& pose) noexcept;
  PoseHandler(const PoseHandler&) = delete;
  Pose& operator=(const PoseHandler&) = delete;

 public:
  void Forward(void) noexcept;      // 向前移动指令（M指令）
  void Backward(void) noexcept;     // 向后移动指令（B状态M指令）
  void TurnLeft(void) noexcept;     // 左转指令（L指令）
  void TurnRight(void) noexcept;    // 右转指令（R指令）
  void Fast(void) noexcept;         // 切换加速状态指令（F指令）
  void Reverse(void) noexcept;      // 切换倒车状态指令（B指令）
  bool IsFast(void) const noexcept;       // 查询是否处于高速状态
  bool IsReverse(void) const noexcept;    // 查询是否处于倒车状态
  Pose Query(void) const noexcept;  // 查询当前位置
 private:
  Point point;
  const Direction* facing;
  bool fast{false};  // 汽车是否处于加速状态
  bool reverse{false};  // 汽车是否处于倒车状态
};
}  // namespace adas
