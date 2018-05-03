###################  Makefile  ###################
all: Knapsack.exe
Knapsack.exe: Knapsack.o
	g++ -o Knapsack.exe Knapsack.o main.o -pedantic
Knapsack.o: Knapsack.cpp Knapsack.h main.cpp
	g++ -c Knapsack.cpp main.cpp
clean:
	del *.o
	del Knapsack.exe