#ifndef HEAP_H 
#define HEAP_H

#include<stdbool.h>
#include"Hash.hpp"
#include<iostream>
#include <sstream>
#include <codecvt>
#include <fstream>
#include<locale>


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

void FillingHeap(UnoMap &mp,Vector *v);

void Initialize(Vector *v);
void Swap(Itens *a, Itens *b);
void BuildHeap(Vector *v, int right);
void Heap(Vector *v);

#endif