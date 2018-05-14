#include "Dijkstra.h"

using namespace std;

int main(int argc, char** argv)
{
	Dijkstra d(argv);
	d.loadFile();
	d.CM_Dijkstra();
	d.saveFile();
}