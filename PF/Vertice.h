#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

using namespace std;

class Vertice
{
	int id;
	int chave;
	int x;
	int y;
	bool acessado;
	vector<Vertice*> adjacencias;
	Vertice* pai;
public:
	Vertice();
	Vertice(int i, int x, int y, int c, Vertice* p);
	int get_id (void);
	int get_x (void);
	int get_y (void);
	int get_chave(void);
	bool get_ac(void);
	Vertice* get_pai(void);
	void set_id(int i);
	void set_x(int x);
	void set_y(int y);
	void set_chave(int c);
	void set_ex(bool e);
	vector<Vertice*> get_adj(void);
	void add_adj(Vertice* v);
	void set_pai(Vertice* p);
};

#endif