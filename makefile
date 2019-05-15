all: main

main: pilha.o lista.o main.o
	g++ pilha.o lista.o main.o -o main.exe

lista.o: lista.cpp
	g++ -c lista.cpp

main.o: main.cpp
	g++ -c main.cpp

pilha.o: pilha.cpp
	g++ -c pilha.cpp

clear:
	del *.o *.exe
