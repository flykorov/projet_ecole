all : ProjetProg EXECUTION

code.o : code_ProjetProg.c code_ProjetProg.h
	gcc -c code_ProjetProg.c -Wall
main.o : main_ProjetProg.c code_ProjetProg.h
	gcc -c main_ProjetProg.c -Wall
PROJET : main_ProjetProg.o code_ProjetProg.o
	gcc -o ProjetProg main_ProjetProg.o code_ProjetProg.o -Wall
	
EXECUTION :
	./ProjetProg	
