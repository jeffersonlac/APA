#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;

class CountingSort
{
	std::vector<int> listaIn;
	std::vector<int> listaOut;
	char* fileIn;
	char* fileOut;
	int sentido;
public:
	CountingSort();
	CountingSort(char** argv);
	int loadFile(void);
	int encontraMax(vector<int> l);
	int encontraMin(vector<int> l);
	int ordena(void);
	int saveFile(void);
};

#endif