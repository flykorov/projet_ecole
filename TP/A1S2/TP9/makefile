all : TP9 EXECUTION
code.o : code_TP9.c code_TP9.h
	gcc -c code_TP9.c -Wall
main.o : main_TP9.c main_TP9.h
	gcc -c main_TP9.c -Wall
PROJET : main_TP9.o code_TP9.o
	gcc -o TP9 main_TP9.o code_TP9.o -Wall
	
EXECUTION :
	./TP9			
