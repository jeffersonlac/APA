#include "QuickSort.h"

using namespace std;

int main(int argc, char** argv)
{
	QuickSort QS(argv);
    
	QS.loadFile();
	QS.ordena(QS.getLista(), 0, QS.getTam()-1);
	QS.saveFile();
    
	return 0;
}