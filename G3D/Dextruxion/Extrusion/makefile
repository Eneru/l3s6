SRC=src
INCLUDE=include
OBJ=obj
BIN=bin
CC=gcc
CFLAGS=-Wall -g
IFLAGS=-I$(INCLUDE) -IGL -I/usr/X11R6/include
LDFLAGS=-L/usr/X11R6/lib -lm -lGL -lGLU -lglut

vpath %.h $(INCLUDE)
vpath %.c $(SRC)
vpath %.o $(OBJ)

all: Dextruxion

%.o: %.c | obj
	$(CC) $(CFLAGS) $(IFLAGS) -o $(OBJ)/$@ -c $<

Vector.o: Vector.c Vector.h
Polygon.o: Polygon.c Polygon.h Vector.h
Perlin.o: Perlin.c Perlin.h Vector.h
Mesh.o: Mesh.c Mesh.h Vector.h Polygon.h Perlin.h
main.o: main.c Mesh.c Mesh.h Vector.h Polygon.h Perlin.h

Dextruxion: main.o Vector.o Polygon.o Perlin.o Mesh.o | bin
	$(CC) $(LDFLAGS) -o $(BIN)/$@ $(OBJ)/main.o

obj:
	@mkdir -p $(OBJ)

bin:
	@mkdir -p $(BIN)
	
clean:
	@rm -rf $(BIN) $(OBJ)
	@echo "Nettoye."

archive:
	@tar -cvzf jeremy.meyer.tar.gz $(SRC) $(INCLUDE) makefile LISEZ-MOI.txt
