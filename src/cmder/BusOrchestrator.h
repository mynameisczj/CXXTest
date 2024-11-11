#pragma once

#include "..\core\PoseHandler.h"
#include "NormalOrchestrator.h"

namespace adas {
class BusOrchestrator : public NormalOrchestrator {
 public:
  ActionGroup TurnLeft(const PoseHandler& poseHandler) const noexcept override {
    ActionGroup actionGroup;
    actionGroup += OnFast(poseHandler);
    actionGroup.PushAction(GetStepAction(poseHandler));
    actionGroup.PushAction(poseHandler.IsReverse()
                               ? ActionType::REVERSE_TURNLEFT_ACTION
                               : ActionType::TURNLEFT_ACTION);

    return actionGroup;
  }
  ActionGroup TurnRight(
      const PoseHandler& poseHandler) const noexcept override {
    ActionGroup actionGroup;
    actionGroup += OnFast(poseHandler);
    actionGroup.PushAction(GetStepAction(poseHandler));
    actionGroup.PushAction(poseHandler.IsReverse()
                               ? ActionType::REVERSE_TURNRIGHT_ACTION
                               : ActionType::TURNRIGHT_ACTION);

    return actionGroup;
  }
};
}  // namespace adas
