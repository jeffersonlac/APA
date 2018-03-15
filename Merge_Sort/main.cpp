#include "MergeSort.h"

using namespace std;

int main(int argc, char** argv)
{
	MergeSort MS(argv);
    
	MS.loadFile();
	MS.ordena(MS.getLista(), 0, MS.getTam()-1);
	MS.saveFile();
    
	return 0;
}