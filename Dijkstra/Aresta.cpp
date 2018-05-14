#include "Aresta.h"

Aresta::Aresta(){};

Aresta::Aresta(Vertice& n1, Vertice& n2, int p)
{
	this->no_1 = n1;
	this->no_2 = n2;
	this->peso = p;
};

Vertice Aresta::get_no_1(void)
{
	return this->no_1;
};

Vertice Aresta::get_no_2(void)
{
	return this->no_2;
};

int Aresta::get_peso(void)
{
	return this->peso;
};

void Aresta::set_no_1(Vertice& v)
{
	this->no_1 = v;
};

void Aresta::set_no_2(Vertice& v)
{
	this->no_2 = v;
};

void Aresta::set_peso(int valor)
{
	this->peso = valor;
};
