# 
# UNIVERSIDAD SERGIO ARBOLEDA
# ESCUELA DE CIENCIAS EXACTAS E INGENIERÍA
# INGENIERÍA DE SISTEMAS Y TELECOMUNICACIONES
# 
# AUTHORS: JUAN JOSÉ MONTENEGRO PULIDO & CAMILO ANDRÉS ROMERO MALDONADO
# EMAILS: juan.montenegro@correo.usa.edu.co & camiloa.romero@correo.usa.edu.co
# 
# 12/03/2021
# 

COMPILER = gcc
FLAGS = -pedantic -Wall -fopenmp
FLAGS_PTH = -pedantic -Wall -pthread
OBJ = -c

CONVENTIONAL = benchmarkConventional
TRANSPOSE = benchmarkTranspose
TRANSPOSE_2ROWS = benchmarkTranspose2
TRANSPOSE_DYNAMIC = benchmarkTransposeDynamic
PTHREADS = benchmarkPthreads

PROGS = $(CONVENTIONAL) $(TRANSPOSE)  $(TRANSPOSE_DYNAMIC) $(TRANSPOSE_2ROWS) $(PTHREADS)

all: $(PROGS)

$(CONVENTIONAL):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 
		
$(TRANSPOSE):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

$(TRANSPOSE_DYNAMIC):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o 

$(TRANSPOSE_2ROWS):
		$(COMPILER) $(FLAGS) $(OBJ) matrix.c
		$(COMPILER) $(FLAGS) $(OBJ) $@.c
		$(COMPILER) $(FLAGS) -o $@ $@.o matrix.o

$(PTHREADS):
		$(COMPILER)-7 $(FLAGS_PTH) $(OBJ) matrixPth.c
		$(COMPILER)-7 $(FLAGS_PTH) $(OBJ) $@.c
		$(COMPILER)-7 $(FLAGS_PTH) -o $@ $@.o matrixPth.o

clean:
		$(RM) $(PROGS) *.o

clean_out:
		$(RM) ./outputs/*
