#include "Vertice.h"

Vertice::Vertice(){};

Vertice::Vertice(int i, int c, Vertice* p)
{
	this->id = i;
	this->chave = c;
	this->pai = p;
};

int Vertice::get_id(void) const
{
	return this->id;
};

int Vertice::get_chave(void) const
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

vector<Vertice*> Vertice::get_adj(void)
{
	return this->adjacencias;
};

void Vertice::add_adj(Vertice* v)
{
	this->adjacencias.push_back(v);
};

void Vertice::set_pai(Vertice* p)
{
	this->pai = p;
};