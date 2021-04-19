/***********************************************************************************/
/*                           Universidad Sergio Arboleda                           */
/*                     Escuela de Ciencias Exactas e Ingeniería                    */
/*                               Autor: Shuo Yang                                */
/*     Editores: Camilo Andres Romero Maldonado & juan José Montenegro Pulido      */
/*                        Programación Paralela y Distribuida                      */
/*                     Profesor: PhD. John Jairo Corredor Franco                    */
/***********************************************************************************/

/*  Este módulo tiene como objetivo multiplicar dos matrices simétricas */
/*                    (N*N) haciendo uso de hilos (posix Threads)                  */

/******************* Importación de Módulos y bibliotecas necesarias *****************/
#include "matrixPth.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Función para inicializar las matrices
void initMatrix(double **matrixA, double **result, int matrixSize)
{
  int i, j;

  srand(time(NULL) * clock());

  for (i = 0; i < matrixSize; i++)
  {
    for (j = 0; j < matrixSize; j++)
    {
      matrixA[i][j] = 2.2 * (i + j);
      matrixB[i][j] = 2.2 * (i + j);
    }
  }
}

// 2. Reserva los espacios en memoria donde se van a almacenar las matrices
double **allocateMatrix(int size)
{
  /* Allocate 'size' * 'size' doubles contiguously. */
  double *vals = (double *)malloc(size * size * sizeof(double));

  /* Allocate array of double* with size 'size' */
  double **ptrs = (double **)malloc(size * sizeof(double *));

  int i;
  for (i = 0; i < size; ++i)
  {
    ptrs[i] = &vals[i * size];
  }

  return ptrs;
}

/******************************* Rutina de los Hilos *******************************/
/*           Cada hilo trabaja en una porción de la matriz1 (matrix1)              */
/*    El inicio y el final de la porción dependen directamente del argumento       */
/*    de entrada 'arg', el cual es el ID asignado a la secuencia de los hilos      */
/***********************************************************************************/

void *worker(void *arg)
{
  int i, j, k, tid, portion_size, row_start, row_end;
  double sum;

  tid = *(int *)(arg); // Se obtiene el ID del hilo asignado secuencialmente
  portion_size = size / threadsNumber;
  row_start = tid * portion_size;
  row_end = (tid + 1) * portion_size;

  for (i = row_start; i < row_end; ++i)
  { // sostiene el indice de la fila de 'matrix1'
    for (j = 0; j < size; ++j)
    {          // sostiene el indice de la columna de 'matrix2'
      sum = 0; // sostiene el valor de la celda
      /* one pass to sum the multiplications of corresponding cells
	 in the row vector and column vector. */
      for (k = 0; k < size; ++k)
      {
        sum += matrixA[i][k] * matrixB[k][j];
      }
      result[i][j] = sum;
    }
  }
  return NULL;
}
