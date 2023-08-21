#include"Hash.hpp"

Data::Data() : appearences(0) {}

void UnoMap::addWord(const std::wstring &word)
{
  ++mp[word].appearences;
}