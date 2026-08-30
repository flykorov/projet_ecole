all : hachage EXECUTION

hach.o : TableHachage.cpp TableHachage.h
	g++ -c TableHachage.cpp -Wall -g

main.o : main.cpp
	g++ -c main.cpp -Wall -g

hachage : main.o hach.o
	g++ -o TP12 main.o TableHachage.o -Wall -g

EXECUTION :
	./TP12