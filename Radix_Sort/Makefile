###################  Makefile  ###################
all: RadixSort.exe
RadixSort.exe: RadixSort.o
	g++ -o RadixSort.exe RadixSort.o main.o -pedantic
RadixSort.o: RadixSort.cpp RadixSort.h main.cpp
	g++ -c RadixSort.cpp main.cpp
clean:
	del *.o
	del RadixSort.exe