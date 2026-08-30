all : carte EXECUTION

fonc.o : fonc.c fonc.h struct.h
	gcc -c fonc.c -Wall -g -lm

allouer.o : allouer.c allouer.h struct.h
	gcc -c allouer.c -Wall -g -lm

lib.o : lib.c lib.h struct.h
	gcc -c lib.c -Wall -g -lm

affiche.o : affiche.c affiche.h struct.h
	gcc -c affiche.c -Wall -g -lm

SDL.o : SDL.c SDL.h
	gcc -c SDL.c -Wall -g `sdl2-config --cflags --libs`

donne.o : donne.c donne.h
	gcc -c donne.c -Wall -g

huffman.o : huffman.c huffman.h
	gcc -c huffman.c -Wall -g

compression.o : compression.c compression.h
	gcc -c compression.c -Wall -g

main.o : main.c fonc.h struct.h
	gcc -c main.c -Wall -g -lm `sdl2-config --cflags --libs`

carte : main.o SDL.o fonc.o affiche.o lib.o allouer.o donne.o compression.o huffman.o
	gcc -o autresor main.o fonc.o affiche.o lib.o allouer.o donne.o compression.o huffman.o SDL.o `sdl2-config --cflags --libs` -Wall -g -lm

# clean :
# 	rm -f *.o

EXECUTION :
	./autresor
# 	valgrind -s --tool=memcheck --leak-check=yes --leak-check=full --track-origins=yes ./autresor