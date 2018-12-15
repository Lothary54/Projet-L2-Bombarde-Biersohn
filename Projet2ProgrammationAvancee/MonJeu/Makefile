CC=g++
CFLAGS=-O2 `sdl2-config --cflags`
LINK=-O2 `sdl2-config --libs`	-lSDL2	-lSDL2_image
SRC=Source.cpp Asteroide.cpp Map.cpp Vaisseau.cpp
OBJ=$(SRC:.cpp=.o)

%.o:	%.c
	$(CC) -c $(CFLAGS) $< 

monJeu: $(OBJ)
	$(CC) $(OBJ) $(LINK) -o $@
	

clean:
	rm *.o Source
