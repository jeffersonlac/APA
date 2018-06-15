#ifndef ST_H
#define ST_H

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

class ST
{
	vector< vector<int> > matriz;
	vector<Aresta> arestas;
	vector<Vertice*> vertices;
	vector<Vertice*> vertices_total;
	vector<Vertice*> vertices_steiner;
	int qtd_nos;
	int qtd_nos_total;
	int qtd_nos_steiner;
	int nos_nvisitados;
	int resultado;
	char* fileIn;
	char* fileOut;
public:
	ST();
	ST(char** argv);
	int distancia(Vertice &v1, Vertice &v2);
	int proximoNo(Vertice &v1, bool &foi_steiner);
	int menorDistancia(Vertice &root);
	void RMST(void);
	void calcResultado(void);
	int loadFile(void);
	int saveFile(void);
};

#endif