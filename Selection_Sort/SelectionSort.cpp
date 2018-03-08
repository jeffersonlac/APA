#include "SelectionSort.h"

SelectionSort::SelectionSort(char** argv)
{
	fileIn = argv[1];
	fileOut = argv[2];
	sentido = *argv[3]-48;
}

int SelectionSort::loadFile(void)
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

int SelectionSort::ordena(void)
{
	if(this->sentido)
	{
		vector<int>::iterator menor;
		for(vector<int>::iterator i = this->lista.begin(); i != this->lista.end(); i++)
		{
			menor = i;
			for(vector<int>::iterator j = i+1; j != this->lista.end(); j++)
			{
				if(*j < *menor)
				{
					menor = j;
				}
			}
			int aux = *i;
			*i = *menor;
			*menor = aux;
		}
	}
	else
	{
		vector<int>::iterator maior;
		for(vector<int>::iterator i = this->lista.begin(); i != this->lista.end(); i++)
		{
			maior = i;
			for(vector<int>::iterator j = i+1; j != this->lista.end(); j++)
			{
				if(*j > *maior)
				{
					maior = j;
				}
			}
			int aux = *i;
			*i = *maior;
			*maior = aux;
		}
	}
	
	// cout << "ordena" << endl;
	// for(vector<int>::iterator i = this->lista.begin(); i != this->lista.end(); i++)
	// {
		// cout << *i << endl;
	// }
	// cout << "termina ordena" << endl;
		
};

int SelectionSort::saveFile(void)
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