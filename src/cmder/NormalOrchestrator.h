#pragma once

#include "..\core\PoseHandler.h"
#include "CmderOrchestrator.h"

namespace adas {
class NormalOrchestrator : public CmderOrchestrator {
 public:
  ActionGroup Move(const PoseHandler& poseHandler) const noexcept override {
    ActionGroup actionGroup;
    actionGroup += OnFast(poseHandler);
    actionGroup.PushAction(GetStepAction(poseHandler));
    return actionGroup;
  }

  ActionGroup TurnLeft(const PoseHandler& poseHandler) const noexcept override {
    ActionGroup actionGroup;
    actionGroup += OnFast(poseHandler);
    actionGroup.PushAction(poseHandler.IsReverse()
                               ? ActionType::REVERSE_TURNLEFT_ACTION
                               : ActionType::TURNLEFT_ACTION);
    return actionGroup;
  }
  ActionGroup TurnRight(const PoseHandler& poseHandler) const noexcept override {
    ActionGroup actionGroup;
    actionGroup += OnFast(poseHandler);
    actionGroup.PushAction(poseHandler.IsReverse()
                               ? ActionType::REVERSE_TURNRIGHT_ACTION
                               : ActionType::TURNRIGHT_ACTION);
    return actionGroup;
  }
  ActionGroup TurnRound(const PoseHandler& poseHandler) const noexcept override {
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

 protected:
  ActionType GetStepAction(const PoseHandler& poseHandler) const noexcept {
    return poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION
                                   : ActionType::FORWARD_1_STEP_ACTION;
  }

  ActionGroup OnFast(const PoseHandler& poseHandler) const noexcept {
    if (poseHandler.IsFast()) {
      return ActionGroup({GetStepAction(poseHandler)});
    }
    return ActionGroup();
  }
};
}  // namespace adas
