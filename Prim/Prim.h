#ifndef Prim_H
#define Prim_H
#define __STDC_LIMIT_MACROS

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>

#include "Aresta.h"
#include "Vertice.h"

using namespace std;

class Prim
{
	vector< vector<int> > matriz;
	vector<Aresta> arestas;
	vector<Aresta> arvore;
	vector<Vertice> vertices;
	int qtd_nos;
	int resultado;
	char* fileIn;
	char* fileOut;
public:
	Prim();
	Prim(char** argv);
	void MST_Prim(void);
	void calcResultado(void);
	int loadFile(void);
	int saveFile(void);
};

#endif