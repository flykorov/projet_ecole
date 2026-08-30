All : ProjetProg EXECUTION

LDLIBS = -lncurses

code.o : code_ProjetProg.c code_ProjetProg.h
	gcc -c code_ProjetProg.c -Wall -lncurses
main.o : main_ProjetProg.c code_ProjetProg.h
	gcc -c main_ProjetProg.c -Wall -lncurses
PROJET : main_ProjetProg.o code_ProjetProg.o
	gcc -o ProjetProg main_ProjetProg.o code_ProjetProg.o -Wall -lncurses
        
EXECUTION :
	./ProjetProg    

