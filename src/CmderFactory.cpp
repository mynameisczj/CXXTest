#include "CmderFactory.h"

#include "PoseHandler.h"
namespace adas {
CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept {
  CmderList cmderList;

  for (const auto it : ParseCommandString(commands)) {
    auto itr = cmderMap.find(it);
    if (itr != cmderMap.end()) {
      cmderList.push_back((*itr).second);
    }
  }
  return cmderList;
}
std::string CmderFactory::ParseCommandString(
    std::string_view commands) const noexcept {
  std::string result(commands);
  ReplaceAll(result, "TR", "Z");
  return result;
}
void CmderFactory::ReplaceAll(std::string& inout, std::string_view what,
                              std::string_view with) const noexcept {
  for (std::string::size_type pos{};
       inout.npos != (pos = inout.find(what.data(), pos, what.length()));
       pos += with.length()) {
    inout.replace(pos, what.length(), with.data(), with.length());
  }
}
}  // namespace adas
