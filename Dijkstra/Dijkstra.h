#ifndef DIJKSTRA_H
#define DIJKSTRA_H

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

class Dijkstra
{
	vector< vector<int> > matriz;
	vector<Aresta> arestas;
	vector<Vertice> vertices;
	int qtd_nos;
	int resultado;
	char* fileIn;
	char* fileOut;
public:
	Dijkstra();
	Dijkstra(char** argv);
	void CM_Dijkstra(void);
	int loadFile(void);
	int saveFile(void);
};

#endif