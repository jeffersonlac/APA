###################  Makefile  ###################
all: ST.exe
ST.exe: ST.o
	g++ -o ST.exe ST.o Aresta.o Vertice.o main.o -pedantic
ST.o: ST.cpp ST.h Aresta.cpp Aresta.h Vertice.cpp Vertice.h main.cpp
	g++ -c -std=c++11 ST.cpp Aresta.cpp Vertice.cpp main.cpp
clean:
	del *.o
	del ST.exe