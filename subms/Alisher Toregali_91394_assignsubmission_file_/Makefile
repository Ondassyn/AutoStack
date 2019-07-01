Flags = -Wreturn-type -pedantic -Wundef -std=c++17 -O5
CPP = g++

main: Makefile main.o stack.o
	$(CPP) $(Flags) -o main main.o stack.o

main.o: Makefile main.cpp stack.h
	$(CPP) -c $(Flags) -o main.o main.cpp

stack.o: Makefile stack.cpp stack.h
	$(CPP) -c $(Flags) -o stack.o stack.cpp
