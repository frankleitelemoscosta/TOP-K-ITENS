#ifndef __HASH_HPP
#define __HASH_HPP

#include <string>
#include <unordered_map>

struct Data {
  unsigned short appearences;
  Data();
};

struct UnoMap {
  std::unordered_map<std::wstring, Data> mp;
  void addWord(const std::wstring &word);
};

#endif