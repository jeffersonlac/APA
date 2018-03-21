#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

class HeapSort
{
	std::vector<int> lista;
	char* fileIn;
	char* fileOut;
	int sentido;
	int tam_heap;
public:
	HeapSort();
	HeapSort(char** argv);
	vector<int>& getLista(void);
	int getTam(void);
	int loadFile(void);
	int buildMax(void);
	int maxHeapfy(vector<int> &l, int ind);
	int ordena(void);
	int heapMaximun(void);
	int maxHeapInsert(int v);
	int heapExtractMax(void);
	int heapIncreaseKey(int ind, int v);
	int saveFile(void);
};

#endif