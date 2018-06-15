#include "Vertice.h"

Vertice::Vertice()
{
	this->pai = nullptr;
	this->acessado = false;
};

Vertice::Vertice(int i, int x, int y, int c, Vertice* p)
{
	this->id = i;
	this->chave = c;
	this->pai = p;
	this->acessado = false;
};

int Vertice::get_id(void)
{
	return this->id;
};

int Vertice::get_x (void)
{
	return x;
};

int Vertice::get_y (void)
{
	return y;
};

int Vertice::get_chave(void)
{
	return this->chave;
};

bool Vertice::get_ac(void)
{
	return this->acessado;
};

Vertice* Vertice::get_pai(void)
{
	return this->pai;
};

void Vertice::set_id(int i)
{
	this->id = i;
};

void Vertice::set_x(int x)
{
	this->x = x;
};

void Vertice::set_y(int y)
{
	this->y = y;
};

void Vertice::set_chave(int c)
{
	this->chave = c;
};

void Vertice::set_ex(bool e)
{
	this->acessado = e;
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