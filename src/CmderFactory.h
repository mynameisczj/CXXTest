#pragma once

#include <functional>
#include <list>
#include <unordered_map>

#include "ActionGroup.h"
#include "Command.h"

namespace adas {
using Cmder = std::function<ActionGroup(PoseHandler&)>;
using CmderList = std::list<Cmder>;

class CmderFactory final {
 public:
  CmderFactory(void) = default;
  ~CmderFactory(void) = default;

  CmderFactory(const CmderFactory&) = delete;
  CmderFactory& operator=(const CmderFactory&) = delete;

 public:
  CmderList GetCmders(const std::string& commands) const noexcept;

 private:
  const std::unordered_map<char, Cmder> cmderMap = {
      {'M', MoveCommand()}, {'L', TurnLeftCommand()}, {'R', TurnRightCommand()},
      {'F', FastCommand()}, {'B', ReverseCommand()},
  };
};

}  // namespace adas
