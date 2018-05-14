#ifndef Prim_H
#define Prim_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <queue>

#include "Aresta.h"
#include "Vertice.h"

using namespace std;

class Prim
{
	vector< vector<int> > matriz;
	vector<Aresta> arestas;
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