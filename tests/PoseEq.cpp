#include "PoseEq.h"

#include <gtest/gtest.h>
namespace adas {
// 重载Pose的==,用于比较两个姿态对象是否相对
bool operator==(const Pose &lhs, const Pose &rhs) {
  return std::tie(lhs.x, lhs.y, lhs.heading) ==
         std::tie(rhs.x, rhs.y, rhs.heading);
}
}  // namespace adas
