/*
UNIVERSIDAD SERGIO ARBOLEDA
ESCUELA DE CIENCIAS EXACTAS E INGENIERÍA
INGENIERÍA DE SISTEMAS Y TELECOMUNICACIONES

AUTHORS: JUAN JOSÉ MONTENEGRO PULIDO & CAMILO ANDRÉS ROMERO MALDONADO
EMAILS: juan.montenegro@correo.usa.edu.co & camiloa.romero@correo.usa.edu.co

12/03/2021
*/

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>

struct timeval start, end;

void initMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB)
{

  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      matrixA[j + i * MATRIX_SIZE] = 2.2 * (i + j);
      matrixB[j + i * MATRIX_SIZE] = 3.7 * (i - j);
    }
  }
}

// Dynamic matrix initialization
void initDynamicMatrix(int MATRIX_SIZE, double **matrixA, double **matrixB, double **result)
{

  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      *(*(matrixA + j) + i) = 2.2 * (i + j);
      *(*(matrixB + j) + i) = 3.7 * (i + j);
      *(*(result + j) + i) = 1.0;
    }
  }
}

// Dynamic matrix initialization
void initDynamicMatrixTranspose(int MATRIX_SIZE, double **matrixA, double **matrixB, double **result, double **transposeMatrixB)
{

  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      *(*(matrixA + j) + i) = 2.2 * (i + j);
      *(*(matrixB + j) + i) = 3.7 * (i + j);
      *(*(transposeMatrixB + j) + i) = 1.0;
      *(*(result + j) + i) = 1.0;
    }
  }
}

// Frees up reserved memory space
void freeReservedMemory(int MATRIX_SIZE, double **matrixA, double **matrixB, double **result)
{

  int i;

#pragma omp parallel for
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    free(matrixA[i]);
    free(matrixB[i]);
    free(result[i]);
  }
  free(matrixA);
  free(matrixB);
  free(result);
}

// Frees up reserved memory space
void freeReservedMemoryTranspose(int MATRIX_SIZE, double **matrixA, double **matrixB, double **result, double **transpose)
{

  int i;

#pragma omp parallel for
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    free(matrixA[i]);
    free(matrixB[i]);
    free(result[i]);
    free(transpose[i]);
  }
  free(matrixA);
  free(transpose);
  free(matrixB);
  free(result);
}

void printMatrix(int MATRIX_SIZE, double *matrix, char *matrixName)
{
  int i, j;
  if (MATRIX_SIZE <= 5)
  {
    printf("\n%s\n", matrixName);
    for (i = 0; i < MATRIX_SIZE; i++)
    {
      for (j = 0; j < MATRIX_SIZE; j++)
      {
        printf("%f \t", matrix[j + i * MATRIX_SIZE]);
      }
      printf("\n");
    }
  }
}

void printDynamicMatrix(int MATRIX_SIZE, double **matrix, char *matrixName)
{
  int i, j;
  if (MATRIX_SIZE <= 5)
  {
    printf("\n%s\n", matrixName);
    for (i = 0; i < MATRIX_SIZE; i++)
    {
      for (j = 0; j < MATRIX_SIZE; j++)
      {
        printf("%f \t", *(*(matrix + j) + i));
      }
      printf("\n");
    }
  }
}

extern void sample_start()
{
  gettimeofday(&start, NULL);
}

extern void sample_stop()
{
  gettimeofday(&end, NULL);
}

extern void sample_end()
{
  // printf("\n%E\n", (double)((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
  printf("%ld,", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
  // printf("\nExecution time: %ld second(s)\n", (end.tv_sec - start.tv_sec));
}
