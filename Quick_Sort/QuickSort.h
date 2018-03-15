#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class QuickSort
{
	std::vector<int> lista;
	char* fileIn;
	char* fileOut;
	int sentido;
public:
	QuickSort();
	QuickSort(char** argv);
	vector<int>& getLista(void);
	int getTam(void);
	int loadFile(void);
	int separaCre(int comeco, int fim);
	int separaDec(int comeco, int fim);
	int ordena(vector<int> &l, int comeco, int fim);
	int saveFile(void);
};

#endif