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
public:
	CountingSort();
	CountingSort(vector<int> l);
	int encontraMax(vector<int> &l);
	int encontraMin(vector<int> &l);
	vector<int> ordena(vector<int> l);
};

#endif