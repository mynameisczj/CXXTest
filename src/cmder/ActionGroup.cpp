#include "ActionGroup.h"

#include <algorithm>
#include <vector>

#include "..\core\PoseHandler.h"
#include "CmderFactory.h"

namespace adas {

class ForwardAction final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.Forward();
  }
};
class BackwardAction final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.Backward();
  }
};
class TurnLeftAction final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.TurnLeft();
  }
};
class TurnRightAction final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.TurnRight();
  }
};
class ReverseTurnLeftAction final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.TurnRight();
  }
};
class ReverseTurnRightAction final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.TurnLeft();
  }
};

class BeReverseAction final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.Reverse();
  }
};
class BeFastAction final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.Fast();
  }
};

ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept
    : actions(actions) {}
void ActionGroup::PushAction(const ActionType actionType) noexcept {
  actions.push_back(actionType);
}
void ActionGroup::DoOperate(PoseHandler& poseHandler) const noexcept {
  static std::vector<std::function<void(PoseHandler&)>> actionVec{
      ForwardAction(),         BackwardAction(),  TurnLeftAction(),
      ReverseTurnLeftAction(), TurnRightAction(), ReverseTurnRightAction(),
      BeReverseAction(),       BeFastAction(),
  };

  std::for_each(actions.begin(), actions.end(),
                [&poseHandler](const ActionType actionType) mutable noexcept {
                  actionVec[static_cast<uint16_t>(actionType)](poseHandler);
                });
}

}  // namespace adas
