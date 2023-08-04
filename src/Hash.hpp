#ifndef __HASH_HPP
#define __HASH_HPP

#include <map>
#include <string>

struct Data {
  unsigned short appearences;
  Data();
};

struct Map {
  std::map<std::wstring, Data> mp;
  void addWord(const std::wstring &word);
};

#endif