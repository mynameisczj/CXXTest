#include "ExecutorImpl.h"
#include <new>
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
                if (pose.heading == 'E') {++pose.x;}
                else if(pose.heading =='W'){--pose.x;}
                else if(pose.heading =='N'){++pose.y;}
                else if(pose.heading =='S'){--pose.y;}
            }
            
        }
    }
} // namespace adas
