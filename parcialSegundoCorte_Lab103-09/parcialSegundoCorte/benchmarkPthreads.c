/***********************************************************************************/
/*                           Universidad Sergio Arboleda                           */
/*                     Escuela de Ciencias Exactas e Ingeniería                    */
/*                               Autor: Shuo Yang                                */
/*     Editores: Camilo Andres Romero Maldonado & juan José Montenegro Pulido      */
/*                        Programación Paralela y Distribuida                      */
/*                     Profesor: PhD. John Jairo Corredor Franco                    */
/***********************************************************************************/

/*  Este programa tiene como objetivo multiplicar dos matrices de tamaño simétrico */
/*                    (N*N) haciendo uso de hilos (posix Threads)                  */

/******************* Importación de Módulos y bibliotecas necesarias *****************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "matrixPth.h"

/********************************** Función Main ***********************************/
int main(int argc, char *argv[])
{
  struct timeval tstart, tend;
  long int executionTime;
  pthread_t *threads;

  if (argc != 3)
  {
    fprintf(stderr, "%s <matrix size> <number of threads>\n", argv[0]);
    return -1;
  }

  size = atoi(argv[1]);
  threadsNumber = atoi(argv[2]);

  if (size % threadsNumber != 0)
  {
    fprintf(stderr, "size %d must be a multiple of num of threads %d\n",
            size, threadsNumber);
    return -1;
  }

  threads = (pthread_t *)malloc(threadsNumber * sizeof(pthread_t));

  matrixA = allocateMatrix(size);
  matrixB = allocateMatrix(size);
  result = allocateMatrix(size);

  initMatrix(matrixA, matrixB, size);

  gettimeofday(&tstart, NULL);

  int i;

  for (i = 0; i < threadsNumber; ++i)
  {
    int *tid;
    tid = (int *)malloc(sizeof(int));
    *tid = i;
    pthread_create(&threads[i], NULL, worker, (void *)tid);
  }

  for (i = 0; i < threadsNumber; ++i)
  {
    pthread_join(threads[i], NULL);
  }
  gettimeofday(&tend, NULL);

  executionTime = (tend.tv_sec - tstart.tv_sec) * 1000000; // sec
  executionTime += (tend.tv_usec - tstart.tv_usec);        // us

  // printf("Number of MPI ranks: 0\tNumber of threads: %d\tExecution time: %ld microsec\n",
  //    threadsNumber, executionTime);
  printf("%ld,", executionTime);

  return 0;
}
