#pragma once
#include "Executor.h"
#include <string>
namespace adas
{
    /*
    Executor具体实现
    */
    class ExecutorImpl : public Executor
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
    };

} // namespace adas/
