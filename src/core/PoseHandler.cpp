#include "PoseHandler.h"

#include "Direction.h"

namespace adas {
PoseHandler::PoseHandler(const Pose& pose) noexcept
    : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)) {}
void PoseHandler::Forward() noexcept { point += facing->Move(); }
void PoseHandler::Backward() noexcept { point -= facing->Move(); }
void PoseHandler::TurnLeft() noexcept { facing = &(facing->LeftOne()); }
void PoseHandler::TurnRight() noexcept { facing = &(facing->RightOne()); }
void PoseHandler::Fast() noexcept { fast = !fast; }
void PoseHandler::Reverse() noexcept { reverse = !reverse; }
bool PoseHandler::IsFast() noexcept { return this->fast; }
bool PoseHandler::IsReverse() noexcept { return this->reverse; }
Pose PoseHandler::Query(void) const noexcept {
  return {point.GetX(), point.GetY(), facing->GetHeading()};
}
}  // namespace adas
