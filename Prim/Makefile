###################  Makefile  ###################
all: Prim.exe
Prim.exe: Prim.o
	g++ -o Prim.exe Prim.o Aresta.o Vertice.o main.o -pedantic
Prim.o: Prim.cpp Prim.h Aresta.cpp Aresta.h Vertice.cpp Vertice.h main.cpp
	g++ -c -std=c++11 Prim.cpp Aresta.cpp Vertice.cpp main.cpp
clean:
	del *.o
	del Prim.exe