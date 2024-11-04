#pragma once

#include "Executor.h"

namespace adas {
class PoseHandler final {
 public:
  PoseHandler(const Pose& pose) noexcept;
  PoseHandler(const PoseHandler&) = delete;
  Pose& operator=(const PoseHandler&) = delete;

 public:
  void Move(void) noexcept;         // 移动指令（M指令）
  void TurnLeft(void) noexcept;     // 左转指令（L指令）
  void TurnRight(void) noexcept;    // 右转指令（R指令）
  void Fast(void) noexcept;         // 切换加速状态指令（F指令）
  bool IsFast(void) noexcept;       // 查询是否处于高速状态
  Pose Query(void) const noexcept;  // 查询当前位置
 private:
  Pose pose;         // 汽车当前位置
  bool fast{false};  // 汽车是否处于加速状态
};
}  // namespace adas
