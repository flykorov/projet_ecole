all : projet EXECUTION

cercle.o : cercle.cpp cercle.h
	g++ -c cercle.cpp -Wall

rectangle.o : rectangle.cpp rectangle.h
	g++ -c rectangle.cpp -Wall

point.o : point.cpp point.h
	g++ -c point.cpp -Wall

dataset.o : dataset.cpp dataset.h
	g++ -c dataset.cpp -Wall

main.o : main.cpp
	g++ -c main.cpp -Wall

projet : main.o cercle.o rectangle.o point.o dataset.o
	g++ -o TP4 main.o cercle.o rectangle.o point.o dataset.o -Wall

EXECUTION :
	./TP4