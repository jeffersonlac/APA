#include "Aresta.h"

Aresta::Aresta(){};

Aresta::Aresta(int n1, int n2, int p)
{
	this->no_1 = n1;
	this->no_2 = n2;
	this->peso = p;
};

int Aresta::get_no_1(void)
{
	return this->no_1;
};

int Aresta::get_no_2(void)
{
	return this->no_2;
};

int Aresta::get_peso(void)
{
	return this->peso;
};

void Aresta::set_no_1(int valor)
{
	this->no_1 = valor;
};

void Aresta::set_no_2(int valor)
{
	this->no_2 = valor;
};

void Aresta::set_peso(int valor)
{
	this->peso = valor;
};
