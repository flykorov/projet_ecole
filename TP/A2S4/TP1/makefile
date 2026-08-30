CC=gcc
CFLAGS = -I.
DEFS = graph.h
OBJ = graph.o main.o

%.o: %.c $(DEFS)
	$(CC) -c -o $@ $< $(CFLAGS)

graph: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm -f *.o graph