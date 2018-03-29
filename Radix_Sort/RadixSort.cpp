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
			this->listaIn.push_back(atoi(linha.c_str()));
		}
		this->listaIn.pop_back();
		this->listaOut = vector<int>(this->listaIn.size());
		FILE.close();
	}
	
	return 1;
};

int RadixSort::encontraMax(vector<int> l)
{
	return *(max_element(l.begin(), l.end()));
};

int RadixSort::encontraMin(vector<int> l)
{
	return *(min_element(l.begin(), l.end()));
};

int RadixSort::ordena(void)
{
	int max = this->encontraMax(this->listaIn);
	int min = this->encontraMin(this->listaIn);
	vector<int> listaAux (max - min + 1, 0);
	cout << "minimo: " << min << endl;
	
	for(int i = 0; i <= this->listaIn.size(); i++)
		listaAux[this->listaIn[i]-min]++;
	
	partial_sum(listaAux.begin(), listaAux.end(), listaAux.begin());
	
	for(vector<int>::iterator i = this->listaIn.end(); i != this->listaIn.begin(); i--)
	{
		this->listaOut[listaAux[*i - min]] = *i;
		listaAux[*i - min]--;
	};
};

int RadixSort::saveFile(void)
{
	fstream FILE(this->fileOut, ofstream::out);
	if(FILE.is_open())
	{
		for(vector<int>::iterator i = this->listaOut.begin(); i != this->listaOut.end(); i++)
		{
			FILE << *i << endl;
		}
		FILE.close();
	}
	return 1;
};