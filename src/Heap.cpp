#include "Heap.hpp"

void Initialize(Vector *v){
	
	//srand(42); 
    
    v->vet = (Itens*)malloc(MAXSIZE*sizeof(Itens));

	for(int i = 0 ; i < MAXSIZE; i++)
	{
		//v->vet[i].frequence = rand()%100;
		v->vet[i].value = L"Vazio";
	}	
}

void Swap(Itens *a, Itens *b){
	Itens aux = *a;
	*a = *b;
	*b = aux;
}

void Imprime(Vector *v){
		
	for(int i=0; i<MAXSIZE; i++){
		wcout << v->vet[i].value << "\t";	
		printf("frequence: %d\t \n", v->vet[i].frequence);
		}
	
	printf("\n");
}

void BuildHeap(Vector *v, int right){

	int left = (right/2) - 1;
	int LC;
	int RC;

	while(left > 0){

		LC = (2 * left);
		RC = (2 * left) + 1;

		if(v->vet[LC].frequence < v->vet[left].frequence)
		{
			Swap(&v->vet[LC],&v->vet[left]);
		}
		if(v->vet[RC].frequence < v->vet[left].frequence)
		{
			Swap(&v->vet[RC],&v->vet[left]);
		}

		left = left - 1; 

	}
}


void Heap(Vector *v){
	int left = 0;//this is the index of the houses the vector into v.
	int right = MAXSIZE;

	while(right > 0){
		right = right - 1;//this is define the walking per tree heap.
		BuildHeap(v, right);
		Swap(&v->vet[left], &v->vet[right]);
	}
	
}

void FillingHeap(Map &mp,Vector *v)
{
	int Counter_Aux = 0;
	bool key = false;


	for(const auto &pair : mp.mp) {
		if(Counter_Aux <20)
		{
			v->vet[Counter_Aux].value = pair.first;
			v->vet[Counter_Aux].frequence = pair.second.appearences;
			Counter_Aux++;
			if(Counter_Aux == 20){
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