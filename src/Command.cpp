#include "Command.h"

#include "PoseHandler.h"
namespace adas {
void MoveCommand::operator()(PoseHandler &poseHandler) const noexcept {
  if (poseHandler.IsFast()) {
    if (poseHandler.IsReverse()) {
      poseHandler.Backward();
    } else {
      poseHandler.Forward();
    }
  }

  if (poseHandler.IsReverse()) {
    poseHandler.Backward();
  } else {
    poseHandler.Forward();
  }
}

void TurnLeftCommand::operator()(PoseHandler &poseHandler) const noexcept {
  if (poseHandler.IsFast()) {
    if (poseHandler.IsReverse()) {
      poseHandler.Backward();
    } else {
      poseHandler.Forward();
    }
  }

  if (poseHandler.IsReverse()) {
    poseHandler.TurnRight();
  } else {
    poseHandler.TurnLeft();
  }
}

void TurnRightCommand::operator()(PoseHandler &poseHandler) const noexcept {
  if (poseHandler.IsFast()) {
    if (poseHandler.IsReverse()) {
      poseHandler.Backward();
    } else {
      poseHandler.Forward();
    }
  }

  if (poseHandler.IsReverse()) {
    poseHandler.TurnLeft();
  } else {
    poseHandler.TurnRight();
  }
}

void FastCommand::operator()(PoseHandler &poseHandler) const noexcept {
  poseHandler.Fast();
}
void ReverseCommand::operator()(PoseHandler &poseHandler) const noexcept {
  poseHandler.Reverse();
}
}  // namespace adas
