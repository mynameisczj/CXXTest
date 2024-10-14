#include "Executor.h"
#include <gtest/gtest.h>
#include <memory>
#include <tuple>

namespace adas
{
    // 重载Pose的==,用于比较两个姿态对象是否相对
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
    // 测试静态方法Executor::NewExecutor
    // 测试用例1
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 有初始
        // when

        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试用例2
    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor()); // 无初始
        // when

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
}