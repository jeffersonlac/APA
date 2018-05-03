#include "Knapsack.h"

Knapsack::Knapsack(char** argv)
{
	fileIn = argv[1];
	fileOut = argv[2];
}

int Knapsack::loadFile(void)
{
	string linha;
	size_t div;
	fstream FILE(this->fileIn);
	if(FILE.is_open())
	{
		if(!FILE.eof())
		{
			getline(FILE, linha);
			div = linha.find(' ');
			if (div != string::npos)
			{
				this->qtd_instancias = stoi(linha.substr(0,div));
				this->capacidade_mochila = stoi(linha.substr(div, string::npos));
			}
		}
		
		while(!FILE.eof())
		{
			getline(FILE, linha);
			div = linha.find(' ');
			if (div != string::npos)
			{
				this->pesos.push_back(stoi(linha.substr(0,div)));
				this->valor.push_back(stoi(linha.substr(div, string::npos)));
			}
		}
		FILE.close();
	}
	
	return 1;
};

int Knapsack::calcula(void)
{
	// tabela que será preenchida
	int V[this->qtd_instancias + 1][this->capacidade_mochila + 1];

	// inicializando a primeira linha e primeira coluna com 0
	for(int w = 0; w <= this->capacidade_mochila; w++)
		V[0][w] = 0;
	for(int i = 1; i <= this->qtd_instancias; i++)
		V[i][0] = 0;

	for(int i = 1; i <= this->qtd_instancias; i++)
	{
		for(int w = 1; w <= this->capacidade_mochila; w++)
		{	
			// elemento pode fazer parte da solução
			if(this->pesos[i - 1] <= w)
			{
				// max...
				if((this->valor[i - 1] + V[i - 1][w - this->pesos[i - 1]]) > V[i - 1][w])
					V[i][w] = this->valor[i - 1] + V[i - 1][w - this->pesos[i - 1]];
				else
					V[i][w] = V[i - 1][w];
			}
			else
				V[i][w] = V[i - 1][w]; // wi > w
		}
	}

	// guarda o valor máximo colocado na mochila
	this->max = V[this->qtd_instancias][this->capacidade_mochila];
	
	// guarda os itens selecionados
	int v, i = this->qtd_instancias, w = this->capacidade_mochila;
	while(w > 0)
	{
		while(i >= 0)
		{
			v = V[i-1][w];
			if(v != V[i][w])
			{
				this->itens_selecionados.push_back(i);
				w = w - this->pesos[i-1];
				i--;
				break;
			}
			i--;
		}
	}
	
	return 1;
};

int Knapsack::saveFile(void)
{
	fstream FILE(this->fileOut, ofstream::out);
	if(FILE.is_open())
	{
		FILE << this->fileIn << endl;
		FILE << "valor : " << this->max << endl;
		FILE << "produtos escolhidos : ";
		for(vector<int>::iterator i = this->itens_selecionados.begin(); i != this->itens_selecionados.end(); i++)
		{
			if(i != this->itens_selecionados.end()-1)
				FILE << *i << ", ";
			else
				FILE << *i;
		}
		FILE.close();
	}
	return 1;
};