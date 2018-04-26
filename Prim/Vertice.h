#ifndef VERTICE_H
#define VERTICE_H

using namespace std;

class Vertice
{
	int id;
	int chave;
	vector<*Vertice> adjacencias;
	Vertice* pai;
public:
	Vertice();
	Vertice(int i, int c, Vertice* p);
	int get_id(void);
	int get_chave(void);
	Vertice* get_pai(void);
	void set_id(int i);
	void set_chave(int c);
	int get_tam_adj(void);
	void add_adj(Vertice* v);
	void set_pai(Vertice* p);
};

#endif