COMPILER = gcc
FLAGS = -pedantic -Wall -fopenmp
OBJ = -c

Classic = MM1cDynamic
WithoutFuntions = MM1cDynamicSF

PROGS = $(Classic) $(WithoutFuntions)

all: $(PROGS)

$(Classic):
		$(COMPILER) $(FLAGS) $(OBJ) modulo.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o modulo.o 

$(WithoutFuntions):
		$(COMPILER) $(FLAGS) $(OBJ) modulo.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o modulo.o 
clean:
		$(RM) $(PROGS) *.o