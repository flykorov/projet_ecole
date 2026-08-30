all : hexa EXECUTION

hexa.o : hexa.cpp hexa.h
	g++ -c hexa.cpp -Wall -g

main.o : main.cpp
	g++ -c main.cpp -Wall -g

hexa : main.o hexa.o
	g++ -o TP4 main.o hexa.o -Wall -g

EXECUTION :
	./TP4
