#include "RadixSort.h"

using namespace std;

int main(int argc, char** argv)
{
	RadixSort CS(argv);
    
	RS.loadFile();
	RS.ordena();
	RS.saveFile();
    
	return 0;
}