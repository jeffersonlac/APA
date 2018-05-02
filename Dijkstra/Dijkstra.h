#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>

#include "Aresta.h"
#include "Vertice.h"

using namespace std;

class Dijkstra
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
	Dijkstra();
	Dijkstra(char** argv);
	void relaxa(Vertice& u, Vertice& v, Aresta& a);
	void CM_Dijkstra(void);
	void calcResultado(void);
	int loadFile(void);
	int saveFile(void);
};

#endif