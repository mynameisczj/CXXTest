#include "Command.h"

#include "..\core\PoseHandler.h"
#include "CmderOrchestrator.h"

namespace adas {
ActionGroup MoveCommand::operator()(
    PoseHandler &poseHandler,
    const CmderOrchestrator &orchestrator) const noexcept {
  return orchestrator.Move(poseHandler);
}

ActionGroup TurnLeftCommand::operator()(
    PoseHandler &poseHandler,
    const CmderOrchestrator &orchestrator) const noexcept {
  return orchestrator.TurnLeft(poseHandler);
}

ActionGroup TurnRightCommand::operator()(
    PoseHandler &poseHandler,
    const CmderOrchestrator &orchestrator) const noexcept {
  return orchestrator.TurnRight(poseHandler);
}

ActionGroup FastCommand::operator()(PoseHandler &poseHandler,
                                    const CmderOrchestrator &) const noexcept {
  ActionGroup actionGroup;
  actionGroup.PushAction(ActionType::BE_FAST_ACTION);
  return actionGroup;
}
ActionGroup ReverseCommand::operator()(
    PoseHandler &poseHandler, const CmderOrchestrator &) const noexcept {
  ActionGroup actionGroup;
  actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
  return actionGroup;
}

ActionGroup TurnRoundCommand::operator()(
    PoseHandler &poseHandler, const CmderOrchestrator &) const noexcept {
  if (poseHandler.IsReverse()) {
    return ActionGroup();
  }
  if (poseHandler.IsFast()) {
    return ActionGroup({
        ActionType::FORWARD_1_STEP_ACTION,
        ActionType::TURNLEFT_ACTION,
        ActionType::FORWARD_1_STEP_ACTION,
        ActionType::TURNLEFT_ACTION,
    });
  }
  return ActionGroup({
      ActionType::TURNLEFT_ACTION,
      ActionType::FORWARD_1_STEP_ACTION,
      ActionType::TURNLEFT_ACTION,
  });
}
}  // namespace adas
