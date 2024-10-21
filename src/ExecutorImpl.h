#pragma once
#include "Executor.h"
#include <string>
namespace adas
{
    /*
    Executor具体实现
    */
    class ExecutorImpl final: public Executor
    {
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
    private:
        class MoveCommand final //定义一个嵌套类MoveCommand，完成Move动作（M指令）
        {
            public:
            //执行Move动作，需要委托ExecutorImp&执行器来完成动作
            void DoOperate(ExecutorImpl&executor) const noexcept
            {
                executor.Move();
            }
        };
        class TurnLeftCommand final //定义一个嵌套类TurnLeftCommand，完成TurnLeft动作（L指令）
        {
            public:
            //执行TurnLeft动作，需要委托ExecutorImp&执行器来完成动作
            void DoOperate(ExecutorImpl&executor) const noexcept
            {
                executor.TurnLeft();
            }
        };
        class TurnRightCommand final //定义一个嵌套类TurnRightCommand，完成TurnRight动作（R指令）
        {
            public:
            //执行TurnRight动作，需要委托ExecutorImp&执行器来完成动作
            void DoOperate(ExecutorImpl&executor) const noexcept
            {
                executor.TurnRight();
            }
        };

    private:
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
    };

} // namespace adas/
