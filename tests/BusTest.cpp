#include <gtest/gtest.h>

#include "Executor.h"
#include "PoseEq.h"

namespace adas {

class BusTest : public ::testing::Test {
 protected:
  void SetUp() override {
    executor.reset(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
  }
  void TearDown() override {}

 protected:
  std::unique_ptr<Executor> executor;
};

TEST_F(BusTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E) {
  // given
  // when
  executor->Execute("M");  // FM: F状态下Move
  // then
  const Pose target{1, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}

TEST_F(BusTest, should_return_x_minus_1_given_command_is_BM_and_facing_is_E) {
  // given
  // when
  executor->Execute("BM");  // FM: F状态下Move
  // then
  const Pose target{-1, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(BusTest, should_return_x_plus_2_given_command_is_FM_and_facing_is_E) {
  // given
  // when
  executor->Execute("FM");  // FM: F状态下Move
  // then
  const Pose target{2, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(BusTest, should_return_x_minus_2_given_command_is_FBM_and_facing_is_E) {
  // given
  // when
  executor->Execute("FBM");  // FM: F状态下Move
  // then
  const Pose target{-2, 0, 'E'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(BusTest,
       should_return_x_plus_1_and_facing_N_given_command_is_L_and_facing_is_E) {
  // given
  // when
  executor->Execute("L");  // FM: F状态下Move
  // then
  const Pose target{1, 0, 'N'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    BusTest,
    should_return_x_minus_1_and_facing_S_given_command_is_BL_and_facing_is_E) {
  // given
  // when
  executor->Execute("BL");  // FM: F状态下Move
  // then
  const Pose target{-1, 0, 'S'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    BusTest,
    should_return_x_plus_2_and_facing_N_given_command_is_FL_and_facing_is_E) {
  // given
  // when
  executor->Execute("FL");  // FM: F状态下Move
  // then
  const Pose target{2, 0, 'N'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    BusTest,
    should_return_x_minus_2_and_facing_S_given_command_is_FBL_and_facing_is_E) {
  // given
  // when
  executor->Execute("FBL");  // FM: F状态下Move
  // then
  const Pose target{-2, 0, 'S'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    BusTest,
    should_return_x_plus_1_and_facing_S_given_command_is_R_and_facing_is_E) {
  // given
  // when
  executor->Execute("R");  // FM: F状态下Move
  // then
  const Pose target{1, 0, 'S'};
  ASSERT_EQ(target, executor->Query());
}

TEST_F(
    BusTest,
    should_return_x_minus_1_and_facing_N_given_command_is_BR_and_facing_is_E) {
  // given
  // when
  executor->Execute("BR");  // FM: F状态下Move
  // then
  const Pose target{-1, 0, 'N'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    BusTest,
    should_return_x_plus_2_and_facing_S_given_command_is_FR_and_facing_is_E) {
  // given
  // when
  executor->Execute("FR");  // FM: F状态下Move
  // then
  const Pose target{2, 0, 'S'};
  ASSERT_EQ(target, executor->Query());
}
TEST_F(
    BusTest,
    should_return_x_minus_2_and_facing_N_given_command_is_FBR_and_facing_is_E) {
  // given
  // when
  executor->Execute("FBR");  // FM: F状态下Move
  // then
  const Pose target{-2, 0, 'N'};
  ASSERT_EQ(target, executor->Query());
}
}  // namespace adas
