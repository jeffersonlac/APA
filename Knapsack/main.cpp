#include "Knapsack.h"

using namespace std;

int main(int argc, char** argv)
{
	Knapsack KS(argv);
    
	KS.loadFile();
	KS.calcula();
	KS.saveFile();
    
	return 0;
}