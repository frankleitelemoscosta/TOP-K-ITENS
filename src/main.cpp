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

int main(){

    //call the function where is the logic of extract and processing data
    //Analysis();

     setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  //local variables
  int counter = 1;
  wchar_t *txt = getText(loc,counter), *ch = txt;
  wchar_t *ptr;
  wstring word;
  StopWords stop_words(loc);
  Map mp;
  Vector Heapp;

  //main loop
  while (*ch) {

    switch(*ch) 
    {
      //in case the ch is in the end sentence or a speak or a question.
      case L'.': case L'!': case L'?':
        if(!word.empty()) 
        {
          if(stop_words.isStopWord(word)) 
            {
              word.clear();
            } 
          else 
            {
              mp.addWord(word);
            }
        }
        word.clear();
        break;

      //in case the ch is in the skip of line.
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

      //in case the ch is between space, comma, feature, quotation marks, bar, two points
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

      //if there is no case, the letter will be concatenated with the word that had already been formed with the preceding letters.
      default:
        word += tolower(*ch);
      break;
    }
    ++ch;
    if(!(*ch)){
      printf("File number: %d\n",counter);
      counter++;

      //In here add the Heap sort
        Initialize(&Heapp);

        FillingHeap(&mp,&Heapp);
  
        //add print
        printEnd(&Heapp);
      if(counter < 3){
        mp.mp.clear();
        ch = getText(loc,counter);
      }else{
        break;
      }
    }
  }

    return 0;

}