#include<iostream>
#include"Utils.hpp"
#include<locale>
#include<codecvt>
#include"Analysis.hpp"
#include"Hash.hpp"
#include"Heap.hpp"
#include<vector>
#include<map>
#include"StopWords.hpp"

using namespace std;

void Analysis(){

  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);
  setlocale(LC_ALL, "portuguese");

  wchar_t *txt = getText(loc), *ch = txt;
  wchar_t *ptr;
  wstring word;
  StopWords stop_words(loc);
  Map mp;
  Vector Heapp;

  while (*ch) {
    switch(*ch) {
      case L'.': case L'!': case L'?':
        if(!word.empty()) {
          if(stop_words.isStopWord(word)) {
              word.clear();
          } else {
            mp.addWord(word);
          }
          }
          word.clear();
        break;

      case L'\n':
        if(!word.empty()) {
            if(stop_words.isStopWord(word)) {
              word.clear();
            } else {
              mp.addWord(word);
            }
          }
          word.clear();
        break;

      case L' ': case L',': case L':':
      case L';': case L'(': case L')':
      case L'"': case L'-': case L'/':
        if(!word.empty()) {
          if(stop_words.isStopWord(word)) {
              word.clear();
            } else {
              mp.addWord(word);
            }

          word.clear();
        }
        break;

      default:
        word += tolower(*ch);
        break;
    }
    ++ch;
  }

  //In here add the Heap sort
  Initialize(&Heapp);

  FillingHeap(mp,&Heapp);  

  //add print
  printEnd(&Heapp);

}