#####################################################################################
#                           Universidad Sergio Arboleda                             #
#                      Escuela de Ciencias Exactas e Ingeniería                     #
#                                Autores:  Juan José Montenegro Pulido  &  Camilo Andres Romero Maldonado       #
#                         Programación Paralela y Distribuida                       #
#                      Profesor: Ph.D. John Jairo Corredor Franco                     #
#####################################################################################

#   Este programa tiene como objetivo multiplicar dos matrices de tamaño simétrico  #
#                     (N*N) haciendo uso de hilos (posix Threads)                   #

##################################### RESUMEN #######################################

#     Este archivo facilita la automatización y optimización para el proceso de     #
#     compilación de  cada  uno  de los  ficheros  componentes de la aplicación     #
#                       (benchmarkPthreads.c, interfaz.h y matrix.c)                        #

# 1. esta variable corresponde al compilador de c y su flag pthreads.
GCC = gcc -pthread
# 2. Flags o variables de entorno requeridas para su compilación.
FLAGS = -pedantic -Wall
# 3. Flag compilación
OBJ = -c

# 4. variable de entorno para referirse a la palabra benchmarkPthreads
PROGS = benchmarkPthreads

# 5. Función tomada en cuenta para toda la ejecución
all: benchmarkPthreads

benchmarkPthreads:
# 6. Compilción del matrix.c -> matrix.o
	$(GCC) $(FLAGS) matrix.c ${OBJ}
# 7. Compilación benchmarkPthreads.c -> benchmarkPthreads.o
	$(GCC) $(FLAGS) $@.c ${OBJ}
# 8. compilación de matrix.o y benchmarkPthreads.o -> benchmarkPthreads
	$(GCC) $(FLAGS) -o $@ $@.o matrix.o
clean:
# 9. Elimina todo objeto .o en la carpeta
		$(RM) $(PROGS) *.o
