#include"Hash.hpp"

Data::Data() : appearences(0) {}

void Map::addWord(const std::wstring &word)
{
  ++mp[word].appearences;
}