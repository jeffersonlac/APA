#include "HeapSort.h"

using namespace std;

int main(int argc, char** argv)
{
	HeapSort HS(argv);
    
	HS.loadFile();
	HS.ordena();
	HS.saveFile();
    
	return 0;
}