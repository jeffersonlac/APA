#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "Aresta.h"

using namespace std;

class Kruskal
{
	vector< vector<int> > matriz;
	vector<Aresta> arestas;
	vector<Aresta> arvore;
	int qtd_nos;
	int resultado;
	char* fileIn;
	char* fileOut;
public:
	Kruskal();
	Kruskal(char** argv);
	void MST_KRUSKAL(void);
	void calcResultado(void);
	int loadFile(void);
	int saveFile(void);
};

#endif