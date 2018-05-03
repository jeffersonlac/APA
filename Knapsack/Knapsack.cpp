#include "Knapsack.h"

Knapsack::Knapsack(char** argv)
{
	fileIn = argv[1];
	fileOut = argv[2];
	sentido = *argv[3]-48;
}

int Knapsack::loadFile(void)
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

int Knapsack::ordena(void)
{
	if(this->sentido)
	{
		int eleito;
		for(int i = 1; i < this->lista.size(); i++)
		{
			int novoIndice = i;
			eleito = this->lista[i];
			for(int j = i-1; (j >= 0) && (eleito < this->lista[j]); j--)
			{
				this->lista[j+1] = this->lista[j];
				novoIndice = j;
			}
			this->lista[novoIndice] = eleito;
		}
	}
	else
	{
		int eleito;
		for(int i = 1; i < this->lista.size(); i++)
		{
			int novoIndice = i;
			eleito = this->lista[i];
			for(int j = i-1; (j >= 0) && (eleito > this->lista[j]); j--)
			{
				this->lista[j+1] = this->lista[j];
				novoIndice = j;
			}
			this->lista[novoIndice] = eleito;
		}
	}
};

int Knapsack::saveFile(void)
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