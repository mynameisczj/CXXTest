#include "Command.h"

#include "PoseHandler.h"
namespace adas {
void MoveCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
  if (poseHandler.IsFast()) {
    poseHandler.Move();
  }
  poseHandler.Move();
}
void TurnLeftCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
  if (poseHandler.IsFast()) {
    poseHandler.Move();
  }
  poseHandler.TurnLeft();
}
void TurnRightCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
  if (poseHandler.IsFast()) {
    poseHandler.Move();
  }
  poseHandler.TurnRight();
}
void FastCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
  poseHandler.Fast();
}
}  // namespace adas
