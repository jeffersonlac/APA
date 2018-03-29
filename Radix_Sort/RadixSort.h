#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "CountingSort.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;

class RadixSort
{
	std::vector<int> lista;
	char* fileIn;
	char* fileOut;
	int sentido;
public:
	RadixSort();
	RadixSort(char** argv);
	int loadFile(void);
	int encontraMax(void);
	int ordena(void);
	int saveFile(void);
};

#endif