#include<iostream>
#include"Utils.hpp"
#include<locale>
#include<codecvt>
#include"Analysis.hpp"
#include"Hash.hpp"

using namespace std;

void ExtractWords(){

  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  wofstream output = createOutput(loc);
  wchar_t *txt = getText(loc), *ch = txt;
  wchar_t *ptr;
  wstring word;
  Map mp;

//put the header in the output.data
  printStart(output);

  while (*ch) {
    switch(*ch) {
      case L'.': case L'!': case L'?':
        if(!word.empty()) {
            mp.addWord(word);
          }
          word.clear();
        break;

      case L'\n':
        if(!word.empty()) {
            mp.addWord(word);
          }
          word.clear();
        break;

      case L' ': case L',': case L':':
      case L';': case L'(': case L')':
      case L'"': case L'-': case L'/':
        if(!word.empty()) {
        
          mp.addWord(word);

          word.clear();
        }
        break;

      default:
        word += tolower(*ch);
        break;
    }
    ++ch;
  }

  //add print
  printEnd(output,mp);

}