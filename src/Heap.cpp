#include "Heap.hpp"

MaxMin::MaxMin() : Small(10000000) , Bigger(0) {}

void Initialize(Vector *v){
	
	srand(42); 
    
    v->vet = (Itens*)malloc(MAXSIZE*sizeof(Itens));

	for(int i=0; i< MAXSIZE; i++)
	{
		v->vet[i].frequence = rand()%100;
		v->vet[i].value = L"Vazio";
	}	
}

void FinishHeap(Vector *v) 
{
	int frequence_aux;
	int i = 0;
	wstring key_aux;
	MaxMin Obj;

	frequence_aux = v->vet[0].frequence;
	key_aux = v->vet[0].value;

	while(v->vet[i].frequence != Obj.Small)
	{
		i++;
	}

	v->vet[0].frequence = v->vet[i].frequence;
	v->vet[0].value = v->vet[i].value;
	v->vet[i].frequence = frequence_aux ;
	v->vet[i].value = key_aux;

	frequence_aux = v->vet[MAXSIZE - 1].frequence;
	key_aux = v->vet[MAXSIZE - 1].value;

	i = 0;

	while(v->vet[i].frequence != Obj.Bigger)
	{
		i++;
	}

	v->vet[MAXSIZE - 1].frequence = v->vet[i].frequence;
	v->vet[MAXSIZE - 1].value = v->vet[i].value;
	v->vet[i].frequence = frequence_aux ;
	v->vet[i].value = key_aux;

}

void Swap(Itens *a, Itens *b){
	Itens aux = *a;
	*a = *b;
	*b = aux;
}

void Heapfy(Vector *v,int i)
{
	int last = i;
	int LC = 2 * i;
	int RC = (2 * 1) + 1;
	MaxMin Obj;

	if (v->vet[LC].frequence > v->vet[last].frequence)
	{
		Swap(&v->vet[last],&v->vet[LC]);
	}
	if(v->vet[RC].frequence > v->vet[last].frequence)
	{
		Swap(&v->vet[last],&v->vet[RC]);
	}
	if(v->vet[last].frequence > Obj.Bigger)
	{
		Obj.Bigger = v->vet[last].frequence;
	}
	if(v->vet[LC].frequence < Obj.Small)
	{
		Obj.Small = v->vet[LC].frequence;
	}
	if(v->vet[RC].frequence < Obj.Small)
	{
		Obj.Small = v->vet[RC].frequence;
	}
	
}

void Heap(Vector *v){

cout << "in Here";
	for (int i = (MAXSIZE / 2) - 1; i >= 0; i--) 
	{
        Heapfy(v,i);
    }
	FinishHeap(v);
}

void FillingHeap(Map &mp,Vector *v)
{
	int Counter_Aux = 0;
	bool key = false;


	for(const auto &pair : mp.mp) {
		if(Counter_Aux < 20)
		{
			v->vet[Counter_Aux].value = pair.first;
			v->vet[Counter_Aux].frequence = pair.second.appearences;
			Counter_Aux++;
			if(Counter_Aux == 20)
			{
				cout << "in Here";
				Heap(v);
				key = true;
			}
		}
		else if(key == true){
			if(v->vet[0].frequence < pair.second.appearences){
				v->vet[0].frequence = pair.second.appearences;
				v->vet[0].value = pair.first;
				Heap(v);
			}
		}
   }

}