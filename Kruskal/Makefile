###################  Makefile  ###################
all: Kruskal.exe
Kruskal.exe: Kruskal.o
	g++ -o Kruskal.exe Kruskal.o Aresta.o main.o -pedantic
Kruskal.o: Kruskal.cpp Kruskal.h Aresta.cpp Aresta.h main.cpp
	g++ -c -std=c++11 Kruskal.cpp Aresta.cpp main.cpp
clean:
	del *.o
	del Kruskal.exe