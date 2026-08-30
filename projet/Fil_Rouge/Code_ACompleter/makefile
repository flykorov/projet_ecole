all : Code_Complet EXECUTION

LDLIBS = -lwiringPi

code_1.o : but_celebration.c but_celebration.h
	gcc -c but_celebration.c -Wall 
	
code_2.o : motors_mini.c motors_mini.h
	gcc -c motors_mini.c -Wall -lwiringPi
	
main.o : main.c but_celebration.h motors_mini.h
	gcc -c main.c -Wall -lwiringPi
	
PROJET : main.o but_celebration.o motors_mini.o
	gcc -o ROBOT main.o but_celebration.o motors_mini.o -Wall -lwiringPi
	
EXECUTION : 
	sudo ./ROBOT	
