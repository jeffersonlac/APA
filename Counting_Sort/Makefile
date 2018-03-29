###################  Makefile  ###################
all: CountingSort.exe
CountingSort.exe: CountingSort.o
	g++ -o CountingSort.exe CountingSort.o main.o -pedantic
CountingSort.o: CountingSort.cpp CountingSort.h main.cpp
	g++ -c CountingSort.cpp main.cpp
clean:
	del *.o
	del CountingSort.exe