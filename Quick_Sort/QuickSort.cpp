#include "QuickSort.h"

QuickSort::QuickSort(char** argv)
{
	fileIn = argv[1];
	fileOut = argv[2];
	sentido = *argv[3]-48;
};

vector<int>& QuickSort::getLista(void)
{
	return this->lista;
};

int QuickSort::getTam(void)
{
	return this->lista.size();
};

int QuickSort::loadFile(void)
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

int QuickSort::separaCre(int comeco, int fim)
{
	int pivo = this->lista[(comeco+fim)/2], i = comeco, j = fim;
	
		while(true)
		{
			while(this->lista[i] < pivo)
				i++;
			while(this->lista[j] > pivo)
				j--;
			if(i >= j)
				return j;
			
			int aux = this->lista[i];
			this->lista[i] = this->lista[j];
			this->lista[j] = aux;
			
			i++; j--;
		}
};

int QuickSort::separaDec(int comeco, int fim)
{
	int pivo = this->lista[(comeco+fim)/2], i = comeco, j = fim;
	
		while(true)
		{
			while(this->lista[i] > pivo)
				i++;
			while(this->lista[j] < pivo)
				j--;
			if(i >= j)
				return j;
			
			int aux = this->lista[i];
			this->lista[i] = this->lista[j];
			this->lista[j] = aux;
			
			i++; j--;
		}
};

int QuickSort::ordena(vector<int> &l, int comeco, int fim)
{
	this->lista = l;
	
	if(comeco < fim)
	{
		int p;
		if(this->sentido)
			p = this->separaCre(comeco, fim);
		else
			p = this->separaDec(comeco, fim);
		this->ordena(this->lista, comeco, p);
		this->ordena(this->lista, p+1, fim);
	}
};

int QuickSort::saveFile(void)
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