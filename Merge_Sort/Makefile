###################  Makefile  ###################
all: MergeSort.exe
MergeSort.exe: MergeSort.o
	g++ -o MergeSort.exe MergeSort.o main.o -pedantic
MergeSort.o: MergeSort.cpp MergeSort.h main.cpp
	g++ -c MergeSort.cpp main.cpp
clean:
	rm -rf *.o
	del *.o
	del MergeSort.exe