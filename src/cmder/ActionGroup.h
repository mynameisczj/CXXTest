#pragma once

#include <list>

#include "..\core\PoseHandler.h"
namespace adas {

enum class ActionType : uint16_t {
  FORWARD_1_STEP_ACTION = 0,
  BACKWARD_1_STEP_ACTION,
  TURNLEFT_ACTION,
  REVERSE_TURNLEFT_ACTION,
  TURNRIGHT_ACTION,
  REVERSE_TURNRIGHT_ACTION,
  BE_REVERSE_ACTION,
  BE_FAST_ACTION
};

class ActionGroup final {
 public:
  ActionGroup() = default;
  ~ActionGroup() = default;
  explicit ActionGroup(const std::list<ActionType> &actions) noexcept;

  ActionGroup &operator+=(const ActionGroup &rhs) noexcept;

 public:
  void PushAction(const ActionType) noexcept;
  void DoOperate(PoseHandler &) const noexcept;

 private:
  std::list<ActionType> actions;
};

}  // namespace adas
