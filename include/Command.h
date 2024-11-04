#pragma once

#include "PoseHandler.h"

namespace adas {
class ICommand {
 public:
  virtual ~ICommand() = default;
  virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
};
// 执行Move动作（M指令）
class MoveCommand final : public ICommand {
 public:
  void DoOperate(PoseHandler &poseHandler) const noexcept;
};
// 执行TurnLeft动作（L指令）
class TurnLeftCommand final : public ICommand {
 public:
  void DoOperate(PoseHandler &poseHandler) const noexcept;
};
// 执行TurnRight动作（R指令）
class TurnRightCommand final : public ICommand {
 public:
  void DoOperate(PoseHandler &poseHandler) const noexcept;
};
// 执行Fast动作（F指令）
class FastCommand final : public ICommand {
 public:
  void DoOperate(PoseHandler &poseHandler) const noexcept;
};
}  // namespace adas
