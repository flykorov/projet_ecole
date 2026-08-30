all : class EXECUTION

programmeur.o : programmeur.cpp programmeur.h
	g++ -c programmeur.cpp -g -Wall

concepteur.o : concepteur.cpp concepteur.h
	g++ -c concepteur.cpp -g -Wall

designer.o : designer.cpp designer.h
	g++ -c designer.cpp -g -Wall

gestionnaire.o : gestionnaire.cpp gestionnaire.h
	g++ -c gestionnaire.cpp -g -Wall

main.o : main.cpp
	g++ -c main.cpp -g -Wall

class : main.o programmeur.o concepteur.o designer.o gestionnaire.o
	g++ -o TP3 main.o programmeur.o concepteur.o designer.o gestionnaire.o -g -Wall

EXECUTION :
	./TP3