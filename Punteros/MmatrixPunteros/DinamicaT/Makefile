COMPILER = gcc
FLAGS = -pedantic -Wall -fopenmp
OBJ = -c

Classic = MM1cDynamic
Transpose = MM1fDynamic

PROGS = $(Classic) $(Transpose)

all: $(PROGS)

$(Classic):
		$(COMPILER) $(FLAGS) $(OBJ) modulo.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o modulo.o 

$(Transpose):
		$(COMPILER) $(FLAGS) $(OBJ) modulo.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o modulo.o 
clean:
		$(RM) $(PROGS) *.o