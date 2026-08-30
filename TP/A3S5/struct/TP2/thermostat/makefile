all : thermostat EXECUTION

thermostat.o : thermostat.cpp thermostat.h
	g++ -c thermostat.cpp

main.o : main.cpp thermostat.h
	g++ -c main.cpp

thermostat : main.o thermostat.o
	g++ -o thermostat main.o thermostat.o

clean :
	rm -f main.o thermostat.o

EXECUTION :
	./thermostat