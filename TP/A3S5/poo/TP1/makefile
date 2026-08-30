all : class EXECUTION

employes.o : employes.cpp employes.h
	g++ -c employes.cpp -g

concepteur.o : concepteur.cpp concepteur.h
	g++ -c concepteur.cpp -g

programmeur.o : programmeur.cpp programmeur.h
	g++ -c programmeur.cpp -g

specialite.o : specialite.cpp specialite.h
	g++ -c specialite.cpp -g

main.o : main.cpp #employes.h concepteur.h programmeur.h specialite.h
	g++ -c main.cpp -g

class : main.o employes.o concepteur.o programmeur.o specialite.o
	g++ -o TP1 main.o employes.o concepteur.o programmeur.o specialite.o -g

clean :
	rm main.o employes.o concepteur.o programmeur.o specialite.o

EXECUTION :
	./TP1