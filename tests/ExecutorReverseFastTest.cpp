#include <gtest/gtest.h>

#include "Executor.h"
#include "PoseEq.h"

namespace adas {
TEST(
    ExecutorReverseFastTest,
    should_return_x_minus_2_given_status_is_fast_and_reverse_command_is_M_and_facing_is_E) {
  // given
  std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
  // when
  executor->Execute("FBM");  // FM: F状态下Move
  // then
  const Pose target{-2, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}
TEST(
    ExecutorReverseFastTest,
    should_return_S_and_x_minus_1_given_status_is_fast_and_reverse_command_is_L_and_facing_is_E) {
  // given
  std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
  // when
  executor->Execute("FBL");  // FM: F状态下Move
  // then
  const Pose target{-1, 0, 'S'};
  ASSERT_EQ(target, executor->Query());
}
TEST(
    ExecutorReverseFastTest,
    should_return_N_and_x_minus_1_given_status_is_fast_and_reverse_command_is_R_and_facing_is_E) {
  // given
  std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
  // when
  executor->Execute("FBR");  // FM: F状态下Move
  // then
  const Pose target{-1, 0, 'N'};
  ASSERT_EQ(target, executor->Query());
}
}  // namespace adas