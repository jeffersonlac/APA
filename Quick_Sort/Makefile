###################  Makefile  ###################
all: QuickSort.exe
QuickSort.exe: QuickSort.o
	g++ -o QuickSort.exe QuickSort.o main.o -pedantic
QuickSort.o: QuickSort.cpp QuickSort.h main.cpp
	g++ -c QuickSort.cpp main.cpp
clean:
	del *.o
	del QuickSort.exe