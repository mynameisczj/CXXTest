#pragma once

#include <memory>
#include <string>

#include ".\cmder\CmderOrchestrator.h"
#include ".\core\PoseHandler.h"
#include "Executor.h"

namespace adas {
/*
Executor具体实现
*/
class ExecutorImpl final : public Executor {
 public:
  explicit ExecutorImpl(const Pose &pose, CmderOrchestrator *) noexcept;
  ~ExecutorImpl() noexcept = default;
  ExecutorImpl(const ExecutorImpl &) = delete;
  ExecutorImpl &operator=(const ExecutorImpl &) = delete;

 public:
  Pose Query(void) const noexcept;                              // 查询汽车状态
  void Execute(const std::string &commands) noexcept override;  // 汽车执行指令

 private:
  PoseHandler poseHandler;
  std::unique_ptr<CmderOrchestrator> orchestrator;
};
}  // namespace adas
