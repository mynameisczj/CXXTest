#pragma once

#include "ActionGroup.h"

namespace adas {
class CmderOrchestrator {
 public:
  virtual ~CmderOrchestrator() = default;

 public:
  virtual ActionGroup Move(const PoseHandler&) const noexcept = 0;
  virtual ActionGroup TurnLeft(const PoseHandler&) const noexcept = 0;
  virtual ActionGroup TurnRight(const PoseHandler&) const noexcept = 0;
  virtual ActionGroup TurnRound(const PoseHandler&) const noexcept = 0;
};
}  // namespace adas
