#include "ExecutorImpl.h"

#include <memory>
#include <new>
namespace adas {
ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {}
Pose ExecutorImpl::Query(void) const noexcept { return pose; }
Executor *Executor::NewExecutor(const Pose &pose) noexcept {
  return new (std::nothrow) ExecutorImpl(pose);  // C++17下有效
}
void ExecutorImpl::Execute(const std::string &commands) noexcept {
  for (const auto cmd : commands) {
    std::unique_ptr<ICommand> cmder;
    // 指令判断
    if (cmd == 'M') {
      cmder = std::make_unique<MoveCommand>();
    } else if (cmd == 'L') {
      cmder = std::make_unique<TurnLeftCommand>();
    } else if (cmd == 'R') {
      cmder = std::make_unique<TurnRightCommand>();
    } else if (cmd == 'F') {
      cmder = std::make_unique<FastCommand>();
    }
    // 指令执行
    if (cmder) {
      cmder->DoOperate(*this);
    }
  }
}
void ExecutorImpl::MoveCommand::DoOperate(
    ExecutorImpl &executor) const noexcept {
  if (executor.fast) {
    executor.Move();
  }
    executor.Move();
}
void ExecutorImpl::TurnLeftCommand::DoOperate(
    ExecutorImpl &executor) const noexcept {
  if (executor.fast) {
    executor.Move();
  }
  executor.TurnLeft();
}
void ExecutorImpl::TurnRightCommand::DoOperate(
    ExecutorImpl &executor) const noexcept {
  if (executor.fast) {
    executor.Move();
  }
  executor.TurnRight();
}
void ExecutorImpl::FastCommand::DoOperate(
    ExecutorImpl &executor) const noexcept {
  executor.Fast();
}

void ExecutorImpl::Move() noexcept {
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
void ExecutorImpl::TurnLeft() noexcept {
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
