/*
UNIVERSIDAD SERGIO ARBOLEDA
ESCUELA DE CIENCIAS EXACTAS E INGENIERÍA
INGENIERÍA DE SISTEMAS Y TELECOMUNICACIONES

AUTHORS: JUAN JOSÉ MONTENEGRO PULIDO & CAMILO ANDRÉS ROMERO MALDONADO
EMAILS: juan.montenegro@correo.usa.edu.co & camiloa.romero@correo.usa.edu.co

12/03/2021
*/

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "matrix.h"

// Memory chunk allocation for storing the required matrixes
#define SIZE (1024 * 1024 * 64 * 3)
static double MEM_CHUNK[SIZE];

void multiplyMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result);

void transposeMatrix(int MATRIX_SIZE, double *matrix, double *transpose);

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    fprintf(stderr, "%s <matrix size> <number of threads>\n", argv[0]);
    return -1;
  }

  int MATRIX_SIZE = atoi(argv[1]);
  argc--;
  argv++;

  int NUM_THREADS = atoi(argv[1]);
  argc--;
  argv++;

  double *matrixA, *matrixB, *result, *transposeMatrixB;

  // Matrixes memory chunk portion assignment
  matrixA = MEM_CHUNK;
  matrixB = matrixA + MATRIX_SIZE * MATRIX_SIZE;
  transposeMatrixB = matrixB + MATRIX_SIZE * MATRIX_SIZE; // Matrix for storing matrixB's transpose
  result = transposeMatrixB + MATRIX_SIZE * MATRIX_SIZE;

  omp_set_num_threads(NUM_THREADS); // Sets # of threads to be used
#pragma omp parallel                // Declaration of Open MP pragma
  {

#pragma omp master
    initMatrix(MATRIX_SIZE, matrixA, matrixB);

    // printMatrix(MATRIX_SIZE, matrixA, "Matrix A"); // Uncomment to print matrix
    // printMatrix(MATRIX_SIZE, matrixB, "Matrix B"); // Uncomment to print matrix

    transposeMatrix(MATRIX_SIZE, matrixB, transposeMatrixB); // Transpose matrix execution
    // printMatrix(MATRIX_SIZE, transposeMatrixB, "Transpose Matrix B"); // Uncomment to print matrix
    sample_start();

    multiplyMatrix(MATRIX_SIZE, matrixA, transposeMatrixB, result);

    // printMatrix(MATRIX_SIZE, result, "Result Matrix"); // Uncomment to print matrix
  }
  sample_stop();
  sample_end();
  return 0;
}

void multiplyMatrix(int MATRIX_SIZE, double *matrixA, double *matrixB, double *result)
{
  int i, j, k;
#pragma omp for
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      double *auxMatrixA, *auxMatrixB;
      double sum = 0.0;

      auxMatrixA = matrixA + (i * MATRIX_SIZE);
      auxMatrixB = matrixB + (j * MATRIX_SIZE);

      for (k = 0; k < MATRIX_SIZE; k++, auxMatrixA++, auxMatrixB++)
      {
        sum += (*auxMatrixA * *auxMatrixB);
      }
      result[i * MATRIX_SIZE + j] = sum;
    }
  }
}

void transposeMatrix(int MATRIX_SIZE, double *matrix, double *transpose)
{
  int i, j;
#pragma omp for // Open MP pragma for declaration for parallelism
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      transpose[(j * MATRIX_SIZE) + i] = matrix[j + i * MATRIX_SIZE]; // Assignment of matrix transpose to the transpose matrix
    }
  }
}
