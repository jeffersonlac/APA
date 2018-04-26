#ifndef ARESTA_H
#define ARESTA_H

using namespace std;

class Aresta
{
	int no_1;
	int no_2;
	int peso;
public:
	Aresta();
	Aresta(int n1, int n2, int p);
	int get_no_1(void);
	int get_no_2(void);
	int get_peso(void);
	void set_no_1(int valor);
	void set_no_2(int valor);
	void set_peso(int valor);
};

#endif