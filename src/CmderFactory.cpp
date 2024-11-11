#include "CmderFactory.h"

#include "PoseHandler.h"
namespace adas {
std::list<std::function<void(PoseHandler&)>> CmderFactory::GetCmders(
    const std::string& commands) const noexcept {
  std::list<std::function<void(PoseHandler&)>> funtionList;

  for (const auto it : commands) {
    auto itr = cmderMap.find(it);
    if (itr != cmderMap.end()) {
      funtionList.push_back((*itr).second);
    }
  }
  return funtionList;
}
}  // namespace adas
