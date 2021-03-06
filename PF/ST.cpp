#include "ST.h"

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

int ST::distancia(Vertice &v1, Vertice &v2)
{
	return abs(v1.get_x() - v2.get_x()) + abs(v1.get_y() - v2.get_y());
};

int ST::proximoNo(Vertice &v1)
{
	long int menor = INT32_MAX;
	int ind;
	for(int i = 0; i < this->qtd_nos; i++)
	{
		if((*this->vertices[i]).get_ac() == false)
		{
			long int dist = this->distancia(v1, (*this->vertices[i]));
			if(dist < menor)
			{
				menor = dist;
				ind = i;
			}
		}
	}
	this->nos_nvisitados--;
	v1.set_chave(menor);
	return ind;
};

ST::ST(char** argv)
{
	this->fileIn = argv[1];
	this->fileOut = argv[2];
	this->resultado = 0;
};

int ST::loadFile(void)
{
	string linha;
	char c;
	fstream FILE(this->fileIn);
	if(FILE.is_open())
	{
		getline(FILE, linha);
		this->qtd_nos_total = this->nos_nvisitados = this->qtd_nos = atoi(linha.c_str());
		
		for(int i = 0; i < this->qtd_nos; i++)
		{
			int x, y;
			linha = "";
			size_t pos_i = 2, pos_f = 1;
			getline(FILE, linha);
			
			pos_f = linha.find(' ', pos_f+1);
			x = stoi(linha.substr(pos_i, pos_f-1));
			pos_i = pos_f + 2;

			pos_f = linha.find('\n', pos_i);
			y = stoi(linha.substr(pos_i, pos_f-2));
			
			Vertice *v = new Vertice();
			(*v).set_id(i);
			(*v).set_x(x);
			(*v).set_y(y);
			(*v).set_ex(false);
			this->vertices.push_back(v);
		}
		FILE.close();
	}

	/* for(int i = 0; i < this->qtd_nos; i++)
	{
		cout << "Id: " << vertices[i].get_id();
		cout << "   X: " << vertices[i].get_x();
		cout << "   Y: " << vertices[i].get_y() << endl;
	} */
	this->vertices_total = this->vertices;
	return 1;
};

int ST::saveFile(void)
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

void ST::RMST(void)
{
	Vertice* root = new Vertice(-1, 0, 0, 0, nullptr);
	(*root).set_id(-1);
	(*root).set_x(0);
	(*root).set_y(0);
	(*root).set_ex(false);

	int ind  = this->proximoNo(*root);
	//cout << ind << endl;
	(*this->vertices[ind]).set_ex(true);
	root = this->vertices[ind];

	while(this->nos_nvisitados > 0)
	{
		ind = this->proximoNo(*root);
		(*this->vertices[ind]).set_ex(true);
		Vertice *proximo = this->vertices[ind];
		
		if((*proximo).get_x() == (*root).get_x() || (*proximo).get_y() == (*root).get_y())
		{
			Aresta a((*root), (*proximo), (*root).get_chave());
			this->arestas.push_back(a);
		} else
		{
			this->qtd_nos_total++;
			Vertice *steiner = new Vertice();
			(*steiner).set_id(this->qtd_nos_total);
			(*steiner).set_x((*proximo).get_x());
			(*steiner).set_y((*root).get_y());
			(*steiner).set_chave(-1);
			(*steiner).set_pai(root);
			this->vertices_total.push_back(steiner);
			
			Aresta b((*root), (*steiner), abs((*root).get_x() - (*steiner).get_x()));
			this->arestas.push_back(b);
			
			Aresta c((*steiner), (*proximo), abs((*proximo).get_y() - (*steiner).get_y()));
			this->arestas.push_back(c);
		}
		root = proximo;
	}

	for(int i = 0; i < this->arestas.size(); i++)
	{
		cout << "x1: " << (this->arestas[i].get_no_1()).get_x() << "; " << "y1: " << (this->arestas[i].get_no_1()).get_y() << endl;
		cout << "x2: " << (this->arestas[i].get_no_2()).get_x() << "; " << "y2: " << (this->arestas[i].get_no_2()).get_y() << endl;
		cout << "Peso: " << this->arestas[i].get_peso() << endl << endl;
	}
};

void ST::calcResultado(void)
{
	for(int i = 0; i < this->arestas.size(); i++)
		this->resultado += this->arestas[i].get_peso();
};