#ifndef HEAP_H 
#define HEAP_H

#include<stdbool.h>
#include"Hash.hpp"
#include<map>
#include<cstring>
#include<iostream>
#include <sstream>

#define MAXSIZE 20

using namespace std;

typedef struct Vector Vector;
typedef struct Itens Itens;


struct Itens{
	int frequence;
	wstring value;

};

struct Vector{
	Itens *vet;
};

struct MaxMin{
	int Bigger;
	int Small;
	MaxMin();
};

void FillingHeap(Map &mp,Vector *v);
void Initialize(Vector *v);
void Heap(Vector *v);
void Heapfy(Vector *v,int i);
void Swap(Itens *a, Itens *b);
void FinishHeap(Vector *v);

#endif