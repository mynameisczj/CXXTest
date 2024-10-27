#pragma once
#include <string>

#include "Executor.h"
namespace adas {
/*
Executor具体实现
*/
class ExecutorImpl final : public Executor {
 private:
  Pose pose;         // 汽车当前位置
  bool fast{false};  // 汽车是否处于加速状态

 private:
  class ICommand {
   public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
  };
  // 执行Move动作（M指令）
  class MoveCommand final : public ICommand {
   public:
    void DoOperate(ExecutorImpl &executor) const noexcept;
  };
  // 执行TurnLeft动作（L指令）
  class TurnLeftCommand final : public ICommand {
   public:
    void DoOperate(ExecutorImpl &executor) const noexcept;
  };
  // 执行TurnRight动作（R指令）
  class TurnRightCommand final : public ICommand {
   public:
    void DoOperate(ExecutorImpl &executor) const noexcept;
  };
  // 执行Fast动作（F指令）
  class FastCommand final : public ICommand {
   public:
    void DoOperate(ExecutorImpl &executor) const noexcept;
  };

 private:
  void Move(void) noexcept;       // 移动指令（M指令）
  void TurnLeft(void) noexcept;   // 左转指令（L指令）
  void TurnRight(void) noexcept;  // 右转指令（R指令）
  void Fast(void) noexcept;       // 切换加速状态指令（F指令）
  bool IsFast(void) noexcept;     // 查询是否处于高速状态

 public:
  explicit ExecutorImpl(const Pose &pose) noexcept;
  ~ExecutorImpl() noexcept = default;
  ExecutorImpl(const ExecutorImpl &) = delete;
  ExecutorImpl &operator=(const ExecutorImpl &) = delete;

 public:
  Pose Query(void) const noexcept override;                     // 获得汽车状态
  void Execute(const std::string &commands) noexcept override;  // 汽车执行指令
};
}  // namespace adas
