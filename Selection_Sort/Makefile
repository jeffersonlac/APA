###################  Makefile  ###################
all: SelectionSort.exe
SelectionSort.exe: SelectionSort.o
	g++ -o SelectionSort.exe SelectionSort.o main.o -pedantic
SelectionSort.o: SelectionSort.cpp SelectionSort.h main.cpp
	g++ -c SelectionSort.cpp main.cpp
clean:
	del *.o
	del SelectionSort.exe