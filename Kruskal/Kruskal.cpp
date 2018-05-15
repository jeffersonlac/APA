#include "Kruskal.h"

bool comp (Aresta a1, Aresta a2)
{
	return (a1.get_peso() <= a2.get_peso());
}

Kruskal::Kruskal(char** argv)
{
	this->fileIn = argv[1];
	this->fileOut = argv[2];
	this->resultado = 0;
};

int Kruskal::loadFile(void)
{
	string linha;
	char c;
	fstream FILE(this->fileIn);
	if(FILE.is_open())
	{
		getline(FILE, linha);
		this->qtd_nos = atoi(linha.c_str());
		
		this->matriz.resize(this->qtd_nos);
		for (int i = 0; i < this->qtd_nos; i++)
			matriz[i].resize(this->qtd_nos);
		
		for(int i = 0; i < this->qtd_nos; i++)
		{
			linha = "";
			size_t pos_i = 0, pos_f = 0;
			getline(FILE, linha);
			for(int j = i+1; j < this->qtd_nos; j++)
			{
				if(j > i)
				{
					pos_f = linha.find('	', pos_f+1);
					this->matriz[i][j] = stoi(linha.substr(pos_i, pos_f-pos_i));
					pos_i = pos_f;
					Aresta a(i, j, this->matriz[i][j]);
					this->arestas.push_back(a);
				}
			}
		}
		
		FILE.close();
	}
	
	return 1;
};

int Kruskal::saveFile(void)
{
	fstream FILE(this->fileOut, ofstream::out);
	if(FILE.is_open())
	{
		FILE << this->fileIn << endl;
		FILE << "Resultado: " << this->resultado;
		FILE.close();
	}
	return 1;
};

void Kruskal::MST_KRUSKAL(void)
{
	char set[this->qtd_nos], c = 97;
	for(int i = 0; i < this->qtd_nos; i++)
		set[i] = c++;
	
	sort(this->arestas.begin(), this->arestas.end(), comp);
	
	for(int i = 0; i < this->arestas.size(); i++)
	{
		if(set[this->arestas[i].get_no_1()] != set[this->arestas[i].get_no_2()])
		{
			this->arvore.push_back(arestas[i]);
			c = set[this->arestas[i].get_no_2()];
			set[this->arestas[i].get_no_2()] = set[this->arestas[i].get_no_1()];
			for(int j = 0; j < this->qtd_nos; j++)
			{
				if(set[j] == c)
					set[j] = set[this->arestas[i].get_no_1()];
				
			}
		}
	}
	
};

void Kruskal::calcResultado(void)
{
	for(int i = 0; i < this->arvore.size(); i++)
		this->resultado += this->arvore[i].get_peso();
};