#include "CmderFactory.h"

#include "PoseHandler.h"
namespace adas {
CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept {
  CmderList cmderList;

  for (const auto it : commands) {
    auto itr = cmderMap.find(it);
    if (itr != cmderMap.end()) {
      cmderList.push_back((*itr).second);
    }
  }
  return cmderList;
}
}  // namespace adas
