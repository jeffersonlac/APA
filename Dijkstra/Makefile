###################  Makefile  ###################
all: Dijkstra.exe
Dijkstra.exe: Dijkstra.o
	g++ -o Dijkstra.exe Dijkstra.o Aresta.o Vertice.o main.o -pedantic
Dijkstra.o: Dijkstra.cpp Dijkstra.h Aresta.cpp Aresta.h Vertice.cpp Vertice.h main.cpp
	g++ -c -std=c++11 Dijkstra.cpp Aresta.cpp Vertice.cpp main.cpp
clean:
	del *.o
	del Dijkstra.exe