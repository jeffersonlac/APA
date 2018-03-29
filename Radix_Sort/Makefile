###################  Makefile  ###################
all: RadixSort.exe
RadixSort.exe: RadixSort.o
	g++ -o RadixSort.exe RadixSort.o CountingSort.o main.o -pedantic
RadixSort.o: RadixSort.cpp RadixSort.h CountingSort.cpp CountingSort.h main.cpp
	g++ -c RadixSort.cpp CountingSort.cpp main.cpp
clean:
	del *.o
	del RadixSort.exe