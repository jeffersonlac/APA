###################  Makefile  ###################
all: HeapSort.exe
HeapSort.exe: HeapSort.o
	g++ -o HeapSort.exe HeapSort.o main.o -pedantic
HeapSort.o: HeapSort.cpp HeapSort.h main.cpp
	g++ -c HeapSort.cpp main.cpp
clean:
	del *.o
	del HeapSort.exe