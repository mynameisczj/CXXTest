#include "ExecutorImpl.h"

#include <algorithm>
#include <functional>
#include <memory>
#include <unordered_map>

#include "CmderFactory.h"
#include "Singleton.h"

namespace adas {
ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {}
Pose ExecutorImpl::Query(void) const noexcept { return poseHandler.Query(); }
Executor *Executor::NewExecutor(const Pose &pose) noexcept {
  return new (std::nothrow) ExecutorImpl(pose);  // C++17下有效
}
void ExecutorImpl::Execute(const std::string &commands) noexcept {
  const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
  std::for_each(cmders.begin(), cmders.end(),
                [this](const Cmder &cmder) noexcept {
                  cmder(poseHandler).DoOperate(poseHandler);
                });
}

}  // namespace adas
