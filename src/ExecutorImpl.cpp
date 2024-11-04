#include "ExecutorImpl.h"

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
  std::unique_ptr<ICommand> cmder;
  std::unordered_map<char, std::unique_ptr<ICommand>> cmderMap;
  cmderMap.emplace('M', std::make_unique<MoveCommand>());
  cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
  cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
  cmderMap.emplace('F', std::make_unique<FastCommand>());
  for (const auto cmd : commands) {
    const auto it = cmderMap.find(cmd);
    if (it != cmderMap.end()) {
      it->second->DoOperate(poseHandler);
    }
  }
}

}  // namespace adas
