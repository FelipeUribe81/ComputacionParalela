GCC = gcc
FLAGS = -pedantic -Wall
OBJ = -c

PROGS = principal

all: principal
principal:
	$(GCC) $(FLAGS) $(OBJ) modulo.c
	$(GCC) $(FLAGS) $(OBJ) $@.c
	$(GCC) $(FLAGS) -o $@ $@.o modulo.o
clean:
	$(RM) $(PROGS) *.o

