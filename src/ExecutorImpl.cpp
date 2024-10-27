#include "ExecutorImpl.h"
void ExecutorImpl::Move() noexcept {
  for (auto i = 0; i <= fast; i++) {
    if (pose.heading == 'E') {
      ++pose.x;
    } else if (pose.heading == 'W') {
      --pose.x;
    } else if (pose.heading == 'N') {
      ++pose.y;
    } else if (pose.heading == 'S') {
      --pose.y;
    }
  }
}
void ExecutorImpl::TurnLeft() noexcept {
  if (fast) {
    Fast();
    Move();
    Fast();
  }
  if (pose.heading == 'E') {
    pose.heading = 'N';
  } else if (pose.heading == 'W') {
    pose.heading = 'S';
  } else if (pose.heading == 'N') {
    pose.heading = 'W';
  } else if (pose.heading == 'S') {
    pose.heading = 'E';
  }
}
void ExecutorImpl::TurnRight() noexcept {
  if (fast) {
    Fast();
    Move();
    Fast();
  }
  if (pose.heading == 'E') {
    pose.heading = 'S';
  } else if (pose.heading == 'W') {
    pose.heading = 'N';
  } else if (pose.heading == 'N') {
    pose.heading = 'E';
  } else if (pose.heading == 'S') {
    pose.heading = 'W';
  }
}
void ExecutorImpl::Fast() noexcept { fast = !fast; }
bool ExecutorImpl::IsFast() noexcept { return this->fast; }
}  // namespace adas
