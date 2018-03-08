#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class InsertionSort
{
	std::vector<int> lista;
	char* fileIn;
	char* fileOut;
	int sentido;
public:
	InsertionSort();
	InsertionSort(char** argv);
	int loadFile(void);
	int ordena(void);
	int saveFile(void);
};

#endif