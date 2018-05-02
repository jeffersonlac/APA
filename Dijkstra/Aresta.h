#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

using namespace std;

class Aresta
{
	Vertice no_1;
	Vertice no_2;
	int peso;
public:
	Aresta();
	Aresta(Vertice n1, Vertice n2, int p);
	Vertice get_no_1(void);
	Vertice get_no_2(void);
	int get_peso(void);
	void set_no_1(Vertice v);
	void set_no_2(Vertice v);
	void set_peso(int valor);
};

#endif