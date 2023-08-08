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

void FillingHeap(Map &mp,Vector *v);
void Initialize(Vector *v);
void Imprime(Vector *v, int right);
void Swap(int *a, int *b);

void RebuildHeap(Vector *v, int left);
void BuildHeap(Vector *v, int right);
void HeapSort(Vector *v);

#endif