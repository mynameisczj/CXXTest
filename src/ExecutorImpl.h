#pragma once
#include <string>

#include "Executor.h"
namespace adas {
/*
Executor具体实现
*/
class ExecutorImpl final : public Executor {
 public:
  // 构造函数
  explicit ExecutorImpl(const Pose &pose) noexcept;
  // 析构函数
  ~ExecutorImpl() noexcept = default;
  // 禁止拷贝
  ExecutorImpl(const ExecutorImpl &) = delete;
  // 禁止赋值
  ExecutorImpl &operator=(const ExecutorImpl &) = delete;

 public:
  // 查询车辆状态,抽象方法具体实现
  Pose Query(void) const noexcept override;
  // 汽车执行指令,抽象方法具体实现
  void Execute(const std::string &commands) noexcept override;

 private:
  // 私有数据成员
  Pose pose;
  bool fast{false};

 private:
  class ICommand {
   public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
  };

  // 定义一个嵌套类MoveCommand，完成Move动作（M指令）
  class MoveCommand final : public ICommand {
   public:
    // 执行Move动作，需要委托ExecutorImp&执行器来完成动作
    void DoOperate(ExecutorImpl &executor) const noexcept { executor.Move(); }
  };

  // 定义一个嵌套类TurnLeftCommand，完成TurnLeft动作（L指令）
  class TurnLeftCommand final : public ICommand {
   public:
    // 执行TurnLeft动作，需要委托ExecutorImp&执行器来完成动作
    void DoOperate(ExecutorImpl &executor) const noexcept {
      executor.TurnLeft();
    }
  };

  // 定义一个嵌套类TurnRightCommand，完成TurnRight动作（R指令）
  class TurnRightCommand final : public ICommand {
   public:
    // 执行TurnRight动作，需要委托ExecutorImp&执行器来完成动作
    void DoOperate(ExecutorImpl &executor) const noexcept {
      executor.TurnRight();
    }
  };

  // 定义一个嵌套类FastCommand，完成Fast动作（F指令）
  class FastCommand final : public ICommand {
   public:
    // 执行Fast动作，需要委托ExecutorImp&执行器来完成动作
    void DoOperate(ExecutorImpl &executor) const noexcept { executor.Fast(); }
  };

 private:
  void Move(void) noexcept; //移动指令
  void TurnLeft(void) noexcept; //左转指令
  void TurnRight(void) noexcept; //右转指令

  void Fast(void) noexcept;    // 切换加速状态
  bool IsFast(void) noexcept;  // 查询是否
};

}  // namespace adas
