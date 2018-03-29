#include "RadixSort.h"

RadixSort::RadixSort(char** argv)
{
	fileIn = argv[1];
	fileOut = argv[2];
	sentido = *argv[3]-48;
}

int RadixSort::loadFile(void)
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
		this->lista.pop_back();
		FILE.close();
	}
	
	return 1;
};

int RadixSort::encontraMax(void)
{
	return *(max_element(this->lista.begin(), this->lista.end()));
};

int RadixSort::ordena(void)
{
	int exp = 1;
	int maior = this->encontraMax();
	while(maior/exp > 0)
	{
		vector<int> listaAux (this->lista.size());
		for(int i = 0; i < this->lista.size(); i++)
			listaAux[i] = (this->lista[i] / exp) % 10;
		
		CountingSort CS(listaAux);
		this->lista = CS.ordena(this->lista);
		
		exp *= 10;
	}
};

int RadixSort::saveFile(void)
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