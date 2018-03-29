#include "CountingSort.h"

using namespace std;

int main(int argc, char** argv)
{
	CountingSort CS(argv);
    
	CS.loadFile();
	CS.ordena();
	CS.saveFile();
    
	return 0;
}