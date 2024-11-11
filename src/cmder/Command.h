#pragma once

#include "..\core\PoseHandler.h"
#include "ActionGroup.h"

namespace adas {
// 执行Move动作（M指令）
class MoveCommand final {
 public:
  ActionGroup operator()(PoseHandler &poseHandler) const noexcept;
};
// 执行TurnLeft动作（L指令）
class TurnLeftCommand final {
 public:
  ActionGroup operator()(PoseHandler &poseHandler) const noexcept;
};
// 执行TurnRight动作（R指令）
class TurnRightCommand final {
 public:
  ActionGroup operator()(PoseHandler &poseHandler) const noexcept;
};
// 执行Fast动作（F指令）
class FastCommand final {
 public:
  ActionGroup operator()(PoseHandler &poseHandler) const noexcept;
};

// 执行Back动作（B指令）
class ReverseCommand final {
 public:
  ActionGroup operator()(PoseHandler &poseHandler) const noexcept;
};
class TurnRoundCommand final {
 public:
  ActionGroup operator()(PoseHandler &poseHandler) const noexcept;
};
}  // namespace adas
