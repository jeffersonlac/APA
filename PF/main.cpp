#include "ST.h"

using namespace std;

int main(int argc, char** argv)
{
	ST st(argv);
	st.loadFile();
	st.RMST();
	st.calcResultado();
	st.saveFile();
}