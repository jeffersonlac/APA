#ifndef Knapsack_H
#define Knapsack_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Knapsack
{
	std::vector<int> lista;
	char* fileIn;
	char* fileOut;
	int sentido;
public:
	Knapsack();
	Knapsack(char** argv);
	int loadFile(void);
	int maxValue(void);
	int saveFile(void);
};

#endif