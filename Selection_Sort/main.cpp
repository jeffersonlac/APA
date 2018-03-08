#include "SelectionSort.h"

using namespace std;

int main(int argc, char** argv)
{
	SelectionSort SS(argv);
    
	SS.loadFile();
	SS.ordena();
	SS.saveFile();
    
	return 0;
}