#include "Kruskal.h"

using namespace std;

int main(int argc, char** argv)
{
	Kruskal k(argv);
	k.loadFile();
	k.MST_KRUSKAL();
	k.calcResultado();
	k.saveFile();
}