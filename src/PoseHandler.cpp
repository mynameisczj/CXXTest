#include "PoseHandler.h"

namespace adas {
PoseHandler::PoseHandler(const Pose& pose) noexcept
    : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)) {}
void PoseHandler::Move() noexcept { point += facing->Move(); }
void PoseHandler::TurnLeft() noexcept { facing = &(facing->LeftOne()); }
void PoseHandler::TurnRight() noexcept { facing = &(facing->RightOne()); }
void PoseHandler::Fast() noexcept { fast = !fast; }
bool PoseHandler::IsFast() noexcept { return this->fast; }
Pose PoseHandler::Query(void) const noexcept {
  return {point.GetX(),point.GetY(),facing->GetHeading()};
}
}  // namespace adas
