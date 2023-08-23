//libraries
#include<iostream>
#include"Utils.hpp"
#include<locale>
#include<codecvt>
#include"Analysis.hpp"
#include"Hash.hpp"
#include"Heap.hpp"
#include"StopWords.hpp"

using namespace std;

void Analysis(){

  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  //local variables
  int counter = 1;
  wchar_t *txt = getText(loc,counter), *ch = txt;
  string word;
  StopWords stop_words(loc);
  Vector Heapp;
  wstring utf16String ;

  HashTable hashTable(INITIAL_SIZE);//for alocate space in the memory for hash table

  //main loop
  while (*ch) {

    switch(*ch) 
    {
      //in case the ch is in the end sentence or a speak or a question.
      case L'.': case L'!': case L'?':
        if(!word.empty()) 
        {         
          if(stop_words.isStopWord(utf16String)) 
            {
              word.clear();
            } 
          else 
            {
              hashTable.insert(word);
            }
        }
        word.clear();
        utf16String.clear();
        break;

      //in case the ch is in the skip of line.
      case L'\n':
        if(!word.empty()) 
        {
            if(stop_words.isStopWord(utf16String)) {
              word.clear();
            } else {
              hashTable.insert(word);
            }
          }
          word.clear();
          utf16String.clear();
        break;

      //in case the ch is between space, comma, feature, quotation marks, bar, two points
      case L' ': case L',': case L':':
      case L';': case L'(': case L')':
      case L'"': case L'-': case L'/':
        if(!word.empty()) 
        {
          if(stop_words.isStopWord(utf16String)) {
              word.clear();
            } else {
              hashTable.insert(word);
            }
          word.clear();
          utf16String.clear();
        }
        break;

      //if there is no case, the letter will be concatenated with the word that had already been formed with the preceding letters.
      default:
        word += tolower(*ch);
        utf16String += tolower(*ch);
      break;
    }
    ++ch;
    if(!(*ch))
    {
      printf("File number: %d\n",counter);
      counter++;

      //hashTable.printHashTable();

      //In here add the Heap sort
        Initialize(&Heapp);

        FillingHeap(&hashTable,&Heapp);
  
        //add print
        printEnd(&Heapp);
      if(counter < 3){
        hashTable.clear();
        ch = getText(loc,counter);
      }else{
        break;
      }
    }
  }

}

//end code