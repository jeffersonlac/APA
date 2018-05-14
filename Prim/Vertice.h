#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

using namespace std;

class Vertice
{
	int id;
	int chave;
	bool excluido;
	vector<Vertice*> adjacencias;
	Vertice* pai;
public:
	Vertice();
	Vertice(int i, int c, Vertice* p);
	int get_id (void);
	int get_chave(void);
	bool get_ex(void);
	Vertice* get_pai(void);
	void set_id(int i);
	void set_chave(int c);
	void set_ex(bool e);
	vector<Vertice*> get_adj(void);
	void add_adj(Vertice* v);
	void set_pai(Vertice* p);
};

#endif