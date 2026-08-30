all : aeroport EXECUTION

avion.o : avion.c avion.h
	gcc -c avion.c -Wall 

main.o : main.c avion.h
	gcc -c main.c -Wall 

aeroport : main.o avion.o
	gcc -o poport main.o avion.o -Wall

EXECUTION :
	./poport