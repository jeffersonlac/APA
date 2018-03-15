#include "MergeSort.h"

MergeSort::MergeSort(char** argv)
{
	fileIn = argv[1];
	fileOut = argv[2];
	sentido = *argv[3]-48;
};

vector<int>& MergeSort::getLista(void)
{
	return this->lista;
};

int MergeSort::getTam(void)
{
	return this->lista.size();
};

int MergeSort::loadFile(void)
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

int MergeSort::merge(int comeco, int meio, int fim)
{
	int com1 = comeco, com2 = meio+1, tam = fim-comeco+1;
	vector<int> listaAux;
	
	if(this->sentido)
	{
		while(com1 <= meio && com2 <= fim)
		{
			if(this->lista[com1] <= this->lista[com2])
			{
				listaAux.push_back(this->lista[com1]);
				com1++;
			}
			else
			{
				listaAux.push_back(this->lista[com2]);
				com2++;
			}
		}
	}
	else
	{
		while(com1 <= meio && com2 <= fim)
		{
			if(this->lista[com1] >= this->lista[com2])
			{
				listaAux.push_back(this->lista[com1]);
				com1++;
			}
			else
			{
				listaAux.push_back(this->lista[com2]);
				com2++;
			}
		}
	}
	
	for(;com1 <= meio; com1++)
		listaAux.push_back(lista[com1]);
	
	for(;com2 <= fim; com2++)
		listaAux.push_back(lista[com2]);
	
	for(int i = comeco; i <= fim; i++)
	{
		lista[i] = listaAux[i - comeco];
	}
};

int MergeSort::ordena(vector<int> &l, int comeco, int fim)
{
	this->lista = l;

	if(comeco < fim)
	{
		int meio = (fim + comeco)/2;
		this->ordena(this->lista, comeco, meio);
		this->ordena(this->lista, meio+1, fim);
		this->merge(comeco, meio, fim);
	}
};

int MergeSort::saveFile(void)
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