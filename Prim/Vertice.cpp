#include "Vertice.h"

Vertice::Vertice(){};

Vertice::Vertice(int i, int c, Vertice* p)
{
	this->id = i;
	this->chave = c;
	this->pai = p;
};

int Vertice::get_id(void)
{
	return this->id;
};

int Vertice::get_chave(void)
{
	return this->chave;
};

Vertice* Vertice::get_pai(void)
{
	return this->pai;
};

void Vertice::set_id(int i)
{
	this->id = i;
};

void Vertice::set_chave(int c)
{
	this->chave = c;
};

int Vertice::get_tam_adj(void)
{
	return this->adjacencias.size();
};

void Vertice::add_adj(Vertice* v)
{
	this->adjacencias.push_back(v);
};

void Vertice::set_pai(Vertice* p)
{
	this->pai = p;
};