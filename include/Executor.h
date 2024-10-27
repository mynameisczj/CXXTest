#pragma once
#include <string>
namespace adas {
// 汽车数据
struct Pose {
  int x, y;      //[x,y]坐标
  char heading;  //[N,S,E,W]四个方向
};
// 驾驶动作执行接口
class Executor {
 public:
  static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;

 public:
  Executor(void) = default;
  virtual ~Executor(void) = default;
  Executor(const Executor &) = delete;
  Executor &operator=(const Executor &) = delete;

 public:
  // 查询当前汽车姿态(接口)
  virtual Pose Query(void) const noexcept = 0;
  // 执行指令方法(接口)
  virtual void Execute(const std::string &commands) noexcept = 0;
};
}  // namespace adas
