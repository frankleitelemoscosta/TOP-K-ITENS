#ifndef HEAP_H 
#define HEAP_H

#include<stdbool.h>
#include"Hash.hpp"
#include<iostream>
#include <sstream>
#include <codecvt>
#include <fstream>
#include<locale>
#include<string>


#define MAXSIZE 10

using namespace std;

typedef struct Vector Vector;
typedef struct Itens Itens;


struct Itens{

	int frequence;
	std::string value;

};

struct Vector{

	Itens *vet;

};

void FillingHeap(HashTable *has,Vector *v);

void Initialize(Vector *v);
void Swap(Itens *a, Itens *b);
void BuildHeap(Vector *v, int right);
void Heap(Vector *v);

#endif