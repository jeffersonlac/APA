#include "Prim.h"

bool comp (Aresta a1, Aresta a2)
{
	return (a1.get_peso() < a2.get_peso());
}

Prim::Prim(char** argv)
{
	this->fileIn = argv[1];
	this->fileOut = argv[2];
	this->resultado = 0;
};

int Prim::loadFile(void)
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
			for(int j = this->qtd_nos-1; j >= 0; j--)
			{
				if(j > i)
				{
					pos_f = linha.find('	', pos_f+1);
					this->matriz[i][j] = stoi(linha.substr(pos_i, pos_f-pos_i));
					pos_i = pos_f;
					Vertice v1, v2;
					v1.set_id(i);
					v1.add_adj(&v2);
					v2.set_id(j);
					v2.add_adj(&v1);
					Aresta a(v1, v2, this->matriz[i][j]);
					this->arestas.push_back(a);
				}
			}
		}
		
		FILE.close();
	}
	
	return 1;
};

int Prim::saveFile(void)
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

void Prim::MST_Prim(void)
{
	for(int i = 0; i < this->vertices.size(); i++)
	{
		this->vertices[i].set_chave(INT_MAX);
		this->vertices[i].set_pai(nullptr);
	}
	
	this->vertices[0].set_chave(0);
	
	vector<Vertice> q = this->vertices;
	
	while(q.size() > 0)
	{
		Vertice u = *min_element(q.begin(), q.end());
		q.erase(min_element(q.begin(), q.end()));
		for(int i = 0; i < u.get_tam_adj(); i++)
		{
			if(u[i])
		}
	}
	
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

void Prim::calcResultado(void)
{
	for(int i = 0; i < this->arvore.size(); i++)
	{
		this->resultado += this->arvore[i].get_peso();
		cout << this->arvore[i].get_peso() << endl;
	}
};