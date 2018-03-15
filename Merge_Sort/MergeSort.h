#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class MergeSort
{
	std::vector<int> lista;
	char* fileIn;
	char* fileOut;
	int sentido;
public:
	MergeSort();
	MergeSort(char** argv);
	vector<int>& getLista(void);
	int getTam(void);
	int loadFile(void);
	int ordena(vector<int> &l, int comeco, int fim);
	int merge(int comeco, int meio, int fim);
	int saveFile(void);
};

#endif