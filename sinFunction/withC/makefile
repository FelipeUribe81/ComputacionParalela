
COMPILER = gcc
FLAGS = -pedantic -Wall
OBJ = -c

PROGS = main

all: main

main:
		$(COMPILER) $(FLAGS) $(OBJ) comp.c -lm
		$(COMPILER) $(FLAGS) $(OBJ) $@.c -lm
		$(COMPILER) $(FLAGS) -o $@ $@.o comp.o -lm

clean:
		$(RM) $(PROGS) *.o