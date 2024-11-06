#include "ExecutorImpl.h"

#include <functional>
#include <memory>
#include <new>
#include <unordered_map>

#include "Command.h"
namespace adas {
ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {}
Pose ExecutorImpl::Query(void) const noexcept { return poseHandler.Query(); }
Executor *Executor::NewExecutor(const Pose &pose) noexcept {
  return new (std::nothrow) ExecutorImpl(pose);  // C++17下有效
}
void ExecutorImpl::Execute(const std::string &commands) noexcept {
  std::unordered_map<char, std::function<void(PoseHandler&)>> cmderMap;
  cmderMap.emplace('M', MoveCommand());
  cmderMap.emplace('L', TurnLeftCommand());
  cmderMap.emplace('R', TurnRightCommand());
  cmderMap.emplace('F', FastCommand());

  for (const auto cmd : commands) {
    const auto it = cmderMap.find(cmd);
    if (it != cmderMap.end()) {
      it->second(poseHandler);
    }
  }
}

}  // namespace adas
