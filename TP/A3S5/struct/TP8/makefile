all : prisme EXECUTION

Prisme.o : Prisme.cpp Prisme.h
	g++ -c Prisme.cpp

# arbre.o : arbreBST.cpp
# 	g++ -c arbreBST.cpp

main.o : main.cpp #arbreBST.h
	g++ -c main.cpp

prisme : main.o Prisme.o #arbre.o
	g++ -o TP8 main.o Prisme.o #arbre.o

EXECUTION :
	./TP8