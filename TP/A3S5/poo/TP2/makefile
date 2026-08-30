all : matrix EXECUTION

matrix.o : matrix.cpp matrix.h
	g++ -c matrix.cpp

main.o : main.cpp matrix.h
	g++ -c main.cpp

matrix : main.o matrix.o
	g++ -o matrix main.o matrix.o

EXECUTION :
	./matrix