#include "HeapSort.h"

HeapSort::HeapSort(char** argv)
{
	fileIn = argv[1];
	fileOut = argv[2];
	sentido = *argv[3]-48;
	tam_heap = 0;
};

vector<int>& HeapSort::getLista(void)
{
	return this->lista;
};

int HeapSort::getTam(void)
{
	return this->lista.size();
};

int HeapSort::loadFile(void)
{
	string linha;
	fstream FILE(this->fileIn);
	if(FILE.is_open())
	{
		while(!FILE.eof())
		{
			getline(FILE, linha);
			this->lista.push_back(atoi(linha.c_str()));
		}
		lista.pop_back();
		FILE.close();
	}
	
	return 1;
};

int HeapSort::buildMax(void)
{
	for(int i = floor((this->getTam()-1)/2); i >= 0; i--)
		this->maxHeapfy(this->lista, i);
};

int HeapSort::maxHeapfy(vector<int> &l, int ind)
{
	this->lista = l;
	int maior = 0;
	int esq = 2*ind + 1;
	int dir = 2*ind + 2;
	
	if(esq < this->tam_heap && this->lista[esq] > this->lista[ind])
		maior = esq;
	else
		maior = ind;
	if(dir < this->tam_heap && this->lista[dir] > this->lista[maior])
		maior = dir;
	if(maior != ind)
	{
		int aux = this->lista[ind];
		this->lista[ind] = this->lista[maior];
		this->lista[maior] = aux;
		this->maxHeapfy(this->lista, maior);
	}
};

int HeapSort::ordena(void)
{
	this->tam_heap = this->getTam();
	this->buildMax();
	for(int i = this->getTam()-1; i > 0; i--)
	{
		int aux = this->lista[0];
		this->lista[0] = this->lista[i];
		this->lista[i] = aux;
		this->tam_heap--;
		this->maxHeapfy(this->lista, 0);
	}
};

int HeapSort::heapMaximun(void)
{
	return this->lista[0];
};

int HeapSort::maxHeapInsert(int v)
{
	this->lista.push_back(-2147483646);
	this->tam_heap = this->getTam();
	this->heapIncreaseKey(this->tam_heap, v);
};

int HeapSort::heapExtractMax(void)
{
	// if(this->getTam() < 1)
		// return NULL;
	int max = this->lista[0];
	this->lista[0] = this->lista[tam_heap-1];
	tam_heap--;
	this->maxHeapfy(this->lista, 0);
	
	return max;
};

int HeapSort::heapIncreaseKey(int ind, int v)
{
	if(v < this->lista[ind])
		return 0;
	this->lista[ind] = v;
	while(ind > 0 && this->lista[(ind-1)/2] < this->lista[ind])
	{
		int aux = this->lista[ind];
		this->lista[ind] = this->lista[(ind-1)/2];
		this->lista[(ind-1)/2] = aux;
		ind = (ind-1)/2;
	}
};

int HeapSort::saveFile(void)
{
	fstream FILE(this->fileOut, ofstream::out);
	if(FILE.is_open())
	{
		for(vector<int>::iterator i = this->lista.begin(); i != this->lista.end(); i++)
		{
			FILE << *i << endl;
		}
		FILE.close();
	}
	return 1;
};