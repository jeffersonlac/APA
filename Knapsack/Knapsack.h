#ifndef Knapsack_H
#define Knapsack_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Knapsack
{
	int qtd_instancias;
	int capacidade_mochila;
	vector<int> pesos;
	vector<int> valor;
	char* fileIn;
	char* fileOut;
public:
	Knapsack();
	Knapsack(char** argv);
	int loadFile(void);
	int calcula(void);
	int saveFile(void);
};

#endif