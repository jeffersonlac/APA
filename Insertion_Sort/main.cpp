#include "InsertionSort.h"

using namespace std;

int main(int argc, char** argv)
{
	InsertionSort IS(argv);
    
	IS.loadFile();
	IS.ordena();
	IS.saveFile();
    
	return 0;
}