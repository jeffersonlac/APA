#include "Dijkstra.h"

Vertice* buscaVerticePorId(vector<Vertice> &lista, int ind)
{
	for(int i = 0; i < lista.size(); i++)
		if(lista[i].get_id() == ind)
			return &lista[i];
	return nullptr;
}

Aresta* buscaArestaPorNos(vector<Aresta> &lista, Vertice n1, Vertice n2)
{
	for(int i = 0; i < lista.size(); i++)
		if((lista[i].get_no_1().get_id() == n1.get_id() && lista[i].get_no_2().get_id() == n2.get_id()) || (lista[i].get_no_2().get_id() == n1.get_id() && lista[i].get_no_1().get_id() == n2.get_id()))
			return &lista[i];
	return nullptr;
}

Dijkstra::Dijkstra(char** argv)
{
	this->fileIn = argv[1];
	this->fileOut = argv[2];
	this->resultado = 0;
};

int Dijkstra::loadFile(void)
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
		}
		
		for(int i = 0; i < this->qtd_nos; i++)
		{
			Vertice v1;
			v1.set_id(i);
			for(int j = 0; j < this->qtd_nos; j++)
			{
				this->matriz[j][i] = matriz[i][j];
				Vertice v2;
				v2.set_id(j);
				v1.add_adj(v2);
				Aresta a(v1, v2, this->matriz[i][j]);
				this->arestas.push_back(a);
			}
			this->vertices.push_back(v1);
		}
		
		FILE.close();
	}
	
	return 1;
};

int Dijkstra::saveFile(void)
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

void Dijkstra::relaxa(Vertice& u, Vertice& v, Aresta& a)
{
	
};

void Dijkstra::CM_Dijkstra(void)
{
	for(int i = 0; i < this->vertices.size(); i++)
	{
		this->vertices[i].set_chave(INT32_MAX);
		this->vertices[i].set_pai(nullptr);
	}
	
	this->vertices[0].set_chave(0);
	
	vector<Vertice> s;
	vector<Vertice> q = this->vertices;

	while(q.size() > 0)
	{
		/////////extrair mínimo
		auto min = min_element( q.begin(), q.end(), []( const Vertice &a, const Vertice &b ){return a.get_chave() < b.get_chave();});
		Vertice u = *min;
		q.erase(min);
		/////////extrair mínimo
		s.push_back(u);
		vector<Vertice> adj = u.get_adj();
		for(int i = 0; i < adj.size(); i++)
		{
			Vertice* z = buscaVerticePorId(q, adj[i].get_id());
			if(z != nullptr)
			{
				Vertice* v = buscaVerticePorId(this->vertices, adj[i].get_id());
				Aresta* a = buscaArestaPorNos(this->arestas, u, *v);
				if(a != nullptr)
				{
					if(a->get_peso() + u.get_chave() < v->get_chave())
					{
						z->set_pai(&u);
						z->set_chave(a->get_peso() + u.get_chave());
						v->set_pai(&u);
						v->set_chave(a->get_peso() + u.get_chave());
					}
				}
			}
		}
	}
};

void Dijkstra::calcResultado(void)
{	
	for(int i = 0; i < this->vertices.size(); i++)
	{
		this->resultado += this->vertices[i].get_chave();
	}
};