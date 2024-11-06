#pragma once

#include "PoseHandler.h"
namespace adas {
// 执行Move动作（M指令）
class MoveCommand final {
 public:
  void operator()(PoseHandler &poseHandler) const noexcept {
    if (poseHandler.IsFast()) {
      poseHandler.Move();
    }
    poseHandler.Move();
  };
};
// 执行TurnLeft动作（L指令）
class TurnLeftCommand final {
 public:
  void operator()(PoseHandler &poseHandler) const noexcept {
    if (poseHandler.IsFast()) {
      poseHandler.Move();
    }
    poseHandler.TurnLeft();
  };
};
// 执行TurnRight动作（R指令）
class TurnRightCommand final {
 public:
  void operator()(PoseHandler &poseHandler) const noexcept {
    if (poseHandler.IsFast()) {
      poseHandler.Move();
    }
    poseHandler.TurnRight();
  };
};
// 执行Fast动作（F指令）
class FastCommand final {
 public:
  void operator()(PoseHandler &poseHandler) const noexcept {
    poseHandler.Fast();
  };
};
}  // namespace adas
