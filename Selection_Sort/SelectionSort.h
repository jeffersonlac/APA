#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class SelectionSort
{
	std::vector<int> lista;
	char* fileIn;
	char* fileOut;
	int sentido;
public:
	SelectionSort();
	SelectionSort(char** argv);
	int loadFile(void);
	int ordena(void);
	int saveFile(void);
};

#endif