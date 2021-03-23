COMPILER = gcc
FLAGS = -pedantic -Wall
OBJ = -c

PROGS = benchmarkCommon

all: benchmarkCommon

benchmarkCommon:
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

clean:
		$(RM) $(PROGS) *.o
