#include "Prim.h"

Aresta* buscaArestaPorNos(vector<Aresta> &lista, Vertice& n1, Vertice& n2)
{
	for(int i = 0; i < lista.size(); i++)
		if((lista[i].get_no_1().get_id() == n1.get_id() && lista[i].get_no_2().get_id() == n2.get_id()) || (lista[i].get_no_2().get_id() == n1.get_id() && lista[i].get_no_1().get_id() == n2.get_id()))
			return &lista[i];
	return nullptr;
}

class comparaVerticePorChave {
public:
    int operator() (Vertice* v1, Vertice* v2)
    {
        return v1->get_chave() > v2->get_chave();
    }
};

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
				}
			}
			Vertice v1;
			v1.set_id(i);
			this->vertices.push_back(v1);
		}
		
		for(int i = 0; i < this->qtd_nos; i++)
		{
			for(int j = 0; j < this->qtd_nos; j++)
			{
				this->matriz[j][i] = matriz[i][j];
				if(matriz[i][j] != -1)
				{
					if(i != j)
						vertices[i].add_adj(&vertices[j]);
					if(j > i)
					{
						Aresta a(vertices[i], vertices[j], this->matriz[i][j]);
						this->arestas.push_back(a);
					}
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
	priority_queue < Vertice*, vector<Vertice*>, comparaVerticePorChave > q;
	
	this->vertices[0].set_chave(0);
	q.push(&this->vertices[0]);
	////INITIALIZE-SINGLE-SOURCE
	for(int i = 1; i < this->vertices.size(); i++)
	{
		this->vertices[i].set_chave(10000000);
		this->vertices[i].set_pai(nullptr);
		q.push(&this->vertices[i]);
	}
	////INITIALIZE-SINGLE-SOURCE

	while(q.empty() == false)
	{
		////EXTRACT-MIN(Q)
		Vertice* u = q.top();
		q.pop();
		u->set_ex(true);
		////EXTRACT-MIN(Q)

		vector<Vertice*> adj = (*u).get_adj();

		for(int i = 0; i < adj.size(); i++)
		{
			Vertice* v = adj[i];
			Aresta* a = buscaArestaPorNos(this->arestas, *u, *v);
			if(!v->get_ex() && (a->get_peso() < v->get_chave()))
			{
				v->set_pai(u);
				v->set_chave(a->get_peso());
				make_heap(const_cast<Vertice**>(&q.top()), const_cast<Vertice**>(&q.top()) + q.size(), comparaVerticePorChave());
			}
		}
	}
};

void Prim::calcResultado(void)
{
	for(int i = 0; i < this->vertices.size(); i++)
		this->resultado += this->vertices[i].get_chave();
};