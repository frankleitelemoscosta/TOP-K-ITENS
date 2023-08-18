#include "Heap.hpp"


void Initialize(Vector *v)
{
	
	//srand(42); 
    
	cout << "Here";


    v->vet = (Itens*)malloc(MAXSIZE*sizeof(Itens));

	for(int i = 0; i < MAXSIZE; i++)
	{
		//v->vet[i].frequence = rand()%100;
		v->vet[i].value = L"Vazio";
	}
	cout << "Here";


}

void Swap(Itens *a, Itens *b){
	Itens aux = *a;
	*a = *b;
	*b = aux;
}

void Imprime(Vector *v){

	wstring_convert<codecvt_utf8<wchar_t>> converter;
	string key;

   for(int i = 0 ; i < MAXSIZE ; i++) {
    key = converter.to_bytes(v->vet[i].value);
    cout << " Chave: " << key;
    printf(" frequência: %d\n",v->vet[i].frequence);
   }
}


void RebuildHeap(Vector *v, int left)
{

	int i = left;
	int child = (left > 0)?(i*2):1;

	if((child+1 < MAXSIZE) && (v->vet[child].frequence < v->vet[child+1].frequence))
		child = child + 1;
	if (v->vet[i].frequence < v->vet[child].frequence)
		Swap(&v->vet[i], &v->vet[child]);
	
}

void BuildHeap(Vector *v, int right)
{

	int left = (right/2) ;

	while(left > 0)
	{
		left = left - 1; 
		RebuildHeap(v, left);
	}
}


void HeapSort(Vector *v){
	int left = 0;
	int right = MAXSIZE;

	BuildHeap(v, right);
	Swap(&v->vet[left], &v->vet[right]);
	//Imprime(v);
	
	
}

void FillingHeap(Map *mp,Vector *v)
{
	int Counter_Aux = 0;
	bool key = false;
					cout << "Here";


	for(const auto &pair : mp->mp) {
		if(Counter_Aux < 20)
		{
			v->vet[Counter_Aux].value = pair.first;
			v->vet[Counter_Aux].frequence = pair.second.appearences;
			Counter_Aux++;


			if(Counter_Aux == 20)
			{
				cout << "Here";
				HeapSort(v);
				key = true;
			}
		}
		else if(key == true){
			if(v->vet[0].frequence < pair.second.appearences){
				v->vet[0].frequence = pair.second.appearences;
				v->vet[0].value = pair.first;
				HeapSort(v);
			}
		}
   }

}