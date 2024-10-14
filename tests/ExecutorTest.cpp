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

    // 方向测试
    //  测试用例3
    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 无初始
        // when
        executor->Execute("M");
        // then
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试用例4
    TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'})); // 无初始
        // when
        executor->Execute("M");
        // then
        const Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试用例5
    TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'})); // 无初始
        // when
        executor->Execute("M");
        // then
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试用例6
    TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'})); // 无初始
        // when
        executor->Execute("M");
        // then
        const Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }

    // 左转指令
    //  测试用例7
    TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 无初始
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    //  测试用例8
    TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'})); // 无初始
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    //  测试用例9
    TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'})); // 无初始
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    //  测试用例10
    TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'})); // 无初始
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // 右转指令
    //   测试用例11
    TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 无初始
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    //  测试用例12
    TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'})); // 无初始
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    //  测试用例13
    TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'})); // 无初始
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    //  测试用例14
    TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'})); // 无初始
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
}