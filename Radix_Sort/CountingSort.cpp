#include "CountingSort.h"

CountingSort::CountingSort(vector<int> l)
{
	this->listaIn = l;
	this->listaOut = vector<int>(l.size());
}

int CountingSort::encontraMax(vector<int> &l)
{
	return *(max_element(l.begin(), l.end()));
};

int CountingSort::encontraMin(vector<int> &l)
{
	return *(min_element(l.begin(), l.end()));
};

vector<int> CountingSort::ordena(vector<int> l)
{
	int max = this->encontraMax(this->listaIn);
	int min = this->encontraMin(this->listaIn);
	vector<int> listaAux (max - min + 1, 0);
	
	for(int i = 0; i <= this->listaIn.size(); i++)
		listaAux[this->listaIn[i]-min]++;
	
	partial_sum(listaAux.begin(), listaAux.end(), listaAux.begin());
	
	vector<int>::reverse_iterator j = this->listaIn.rbegin();
	for(vector<int>::reverse_iterator i = l.rbegin(); i != l.rend(); i++)
	{
		this->listaOut[listaAux[*j - min]] = *i;
		listaAux[*j - min]--;
		j++;
	};
	
	return this->listaOut;
};

