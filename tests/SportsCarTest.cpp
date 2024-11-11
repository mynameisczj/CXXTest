#include <gtest/gtest.h>

#include "Executor.h"
#include "PoseEq.h"

namespace adas {

class SportsCarTest : public ::testing::Test {
 protected:
  void SetUp() override {
    executor.reset(
        Executor::NewExecutor({0, 0, 'E'}, ExecutorType::SPORTS_CAR));
  }
  void TearDown() override {}

 protected:
  std::unique_ptr<Executor> executor;
};

TEST_F(SportsCarTest,
       should_return_x_plus_2_given_command_is_M_and_facing_is_E) {
  // given
  // when
  executor->Execute("M");  // FM: F状态下Move
  // then
  const Pose target{2, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}

TEST_F(SportsCarTest,
       should_return_x_minus_2_given_command_is_BM_and_facing_is_E) {
  // given
  // when
  executor->Execute("BM");  // FM: F状态下Move
  // then
  const Pose target{-2, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(SportsCarTest,
       should_return_x_plus_4_given_command_is_FM_and_facing_is_E) {
  // given
  // when
  executor->Execute("FM");  // FM: F状态下Move
  // then
  const Pose target{4, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(SportsCarTest,
       should_return_x_minus_4_given_command_is_FBM_and_facing_is_E) {
  // given
  // when
  executor->Execute("FBM");  // FM: F状态下Move
  // then
  const Pose target{-4, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(SportsCarTest,
       should_return_y_plus_1_and_facing_N_given_command_is_L_and_facing_is_E) {
  // given
  // when
  executor->Execute("L");  // FM: F状态下Move
  // then
  const Pose target{0, 1, 'N'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    SportsCarTest,
    should_return_y_plus_1_and_facing_S_given_command_is_BL_and_facing_is_E) {
  // given
  // when
  executor->Execute("BL");  // FM: F状态下Move
  // then
  const Pose target{0, 1, 'S'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    SportsCarTest,
    should_return_x_plus_1_y_plus_1_and_facing_N_given_command_is_FL_and_facing_is_E) {
  // given
  // when
  executor->Execute("FL");  // FM: F状态下Move
  // then
  const Pose target{1, 1, 'N'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    SportsCarTest,
    should_return_x_minus_1_y_plus_1_and_facing_S_given_command_is_FBL_and_facing_is_E) {
  // given
  // when
  executor->Execute("FBL");  // FM: F状态下Move
  // then
  const Pose target{-1, 1, 'S'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    SportsCarTest,
    should_return_y_minus_1_and_facing_S_given_command_is_R_and_facing_is_E) {
  // given
  // when
  executor->Execute("R");  // FM: F状态下Move
  // then
  const Pose target{0, -1, 'S'};
  ASSERT_EQ(target, executor->Query());
}

TEST_F(
    SportsCarTest,
    should_return_y_minus_1_and_facing_N_given_command_is_BR_and_facing_is_E) {
  // given
  // when
  executor->Execute("BR");  // FM: F状态下Move
  // then
  const Pose target{0, -1, 'N'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    SportsCarTest,
    should_return_x_plus_1_y_minus_1_and_facing_S_given_command_is_FR_and_facing_is_E) {
  // given
  // when
  executor->Execute("FR");  // FM: F状态下Move
  // then
  const Pose target{1, -1, 'S'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    SportsCarTest,
    should_return_x_minus_1_y_minus_1_and_facing_N_given_command_is_FBR_and_facing_is_E) {
  // given
  // when
  executor->Execute("FBR");  // FM: F状态下Move
  // then
  const Pose target{-1, -1, 'N'};
  ASSERT_EQ(target, executor->Query());
}
}  // namespace adas
