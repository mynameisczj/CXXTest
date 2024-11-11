#include "Command.h"

#include "ActionGroup.h"
#include "PoseHandler.h"

namespace adas {
ActionGroup MoveCommand::operator()(PoseHandler &poseHandler) const noexcept {
  ActionGroup actionGroup;
  const auto action = poseHandler.IsReverse()
                          ? ActionType::BACKWARD_1_STEP_ACTION
                          : ActionType::FORWARD_1_STEP_ACTION;
  if (poseHandler.IsFast()) {
    actionGroup.PushAction(action);
  }

  actionGroup.PushAction(action);
  return actionGroup;
}

ActionGroup TurnLeftCommand::operator()(
    PoseHandler &poseHandler) const noexcept {
  ActionGroup actionGroup;
  const auto action1 = poseHandler.IsReverse()
                           ? ActionType::BACKWARD_1_STEP_ACTION
                           : ActionType::FORWARD_1_STEP_ACTION;
  if (poseHandler.IsFast()) {
    actionGroup.PushAction(action1);
  }
  
  const auto action2 = poseHandler.IsReverse()
                           ? ActionType::REVERSE_TURNLEFT_ACTION
                           : ActionType::TURNLEFT_ACTION;
  actionGroup.PushAction(action2);
  return actionGroup;
}

ActionGroup TurnRightCommand::operator()(
    PoseHandler &poseHandler) const noexcept {
  ActionGroup actionGroup;
  const auto action1 = poseHandler.IsReverse()
                           ? ActionType::BACKWARD_1_STEP_ACTION
                           : ActionType::FORWARD_1_STEP_ACTION;
  if (poseHandler.IsFast()) {
    actionGroup.PushAction(action1);
  }
  const auto action2 = poseHandler.IsReverse()
                           ? ActionType::REVERSE_TURNRIGHT_ACTION
                           : ActionType::TURNRIGHT_ACTION;
  actionGroup.PushAction(action2);
  return actionGroup;
}

ActionGroup FastCommand::operator()(PoseHandler &poseHandler) const noexcept {
  ActionGroup actionGroup;
  actionGroup.PushAction(ActionType::BE_FAST_ACTION);
  return actionGroup;
}
ActionGroup ReverseCommand::operator()(
    PoseHandler &poseHandler) const noexcept {
  ActionGroup actionGroup;
  actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
  return actionGroup;
}
}  // namespace adas
