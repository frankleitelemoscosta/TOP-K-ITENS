#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include<locale>
#include<iostream>
#include <fstream>
#include<map>
#include"Hash.hpp"

using namespace std;

wchar_t *getText(const locale &loc);
void printStart(std::wofstream &output);
std::wofstream createOutput(const std::locale &loc);
void printEnd(std::wofstream &output,Map &mp);


#endif
//end code