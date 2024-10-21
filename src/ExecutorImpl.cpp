#include "ExecutorImpl.h"
#include <new>
#include<memory>
namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return pose;
    }
    /*
        std::nothrow std::nothrow_t 类型实例,
        当内存分配失败时返回空指针而不是 std::bad_alloc 异常
    */
    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose); // C++17下有效
    }
    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            // 指令是M指令
            if (cmd == 'M')
            {
                std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
                cmder->DoOperate(*this); //执行MoveCommand的DoOperate，即Move
            }
            // 指令是L指令
            if (cmd == 'L')
            {
                std::unique_ptr<TurnLeftCommand> cmder = std::make_unique<TurnLeftCommand>();
                cmder->DoOperate(*this); //执行TurnLeftCommand的DoOperate，即TurnLeft
            }
            // 指令是R指令
            if (cmd == 'R')
            {
                TurnRight();
            }
            // end
        }
    }
    void ExecutorImpl::Move() noexcept{
        if (pose.heading == 'E'){
            ++pose.x;
        }
        else if (pose.heading == 'W'){
            --pose.x;
        }
        else if (pose.heading == 'N'){
            ++pose.y;
        }
        else if (pose.heading == 'S'){
            --pose.y;
        }
    }
    void ExecutorImpl::TurnLeft() noexcept{
        if (pose.heading == 'E'){
            pose.heading = 'N';
        }
        else if (pose.heading == 'W'){
            pose.heading = 'S';
        }
        else if (pose.heading == 'N'){
            pose.heading = 'W';
        }
        else if (pose.heading == 'S'){
            pose.heading = 'E';
        }
    }
    void ExecutorImpl::TurnRight() noexcept{
        if (pose.heading == 'E'){
            pose.heading = 'S';
        }
        else if (pose.heading == 'W'){
            pose.heading = 'N';
        }
        else if (pose.heading == 'N'){
            pose.heading = 'E';
        }
        else if (pose.heading == 'S'){
            pose.heading = 'W';
        }
    }
} // namespace adas
