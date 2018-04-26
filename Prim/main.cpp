#include "Prim.h"

using namespace std;

int main(int argc, char** argv)
{
	Prim p(argv);
	p.loadFile();
	p.MST_Prim();
	p.calcResultado();
	p.saveFile();
}