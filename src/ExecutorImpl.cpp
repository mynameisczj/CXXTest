#include "ExecutorImpl.h"

#include <algorithm>
#include <functional>
#include <memory>
#include <unordered_map>

#include ".\cmder\BusOrchestrator.h"
#include ".\cmder\CmderFactory.h"
#include ".\cmder\CmderOrchestrator.h"
#include ".\cmder\NormalOrchestrator.h"
#include ".\cmder\SportsOrchestrator.h"
#include ".\core\Singleton.h"

namespace adas {
Executor *Executor::NewExecutor(const Pose &pose,
                                const ExecutorType executorType) noexcept {
  CmderOrchestrator *orchestrator = nullptr;
  switch (executorType) {
    case ExecutorType::NORMAL: {
      orchestrator = new (std::nothrow) NormalOrchestrator();
      break;
    }
    case ExecutorType::SPORTS_CAR: {
      orchestrator = new (std::nothrow) SportsOrchestrator();
      break;
    }
    case ExecutorType::BUS: {
      orchestrator = new (std::nothrow) BusOrchestrator();
      break;
    }
  }
  return new (std::nothrow) ExecutorImpl(pose, orchestrator);
}

ExecutorImpl::ExecutorImpl(const Pose &pose,
                           CmderOrchestrator *orchestrator) noexcept
    : poseHandler(pose), orchestrator(orchestrator) {}
Pose ExecutorImpl::Query(void) const noexcept { return poseHandler.Query(); }

void ExecutorImpl::Execute(const std::string &commands) noexcept {
  const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
  std::for_each(cmders.begin(), cmders.end(),
                [this](const Cmder &cmder) noexcept {
                  cmder(poseHandler, *orchestrator).DoOperate(poseHandler);
                });
}

}  // namespace adas
