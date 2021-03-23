#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "time.h"
#include "matrix.h"

struct timeval start, end;

void setRand()
{
    srand(time(NULL) * clock());
}

void initMatrix(size_t MATRIX_SIZE, int randomRange, int matrix[][MATRIX_SIZE])
{
    int i, j;

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = rand() % (randomRange + 1);
        }
    }
}

void multiplyMatrix(size_t MATRIX_SIZE, int result[][MATRIX_SIZE], int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE])
{
    int i, j, k;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
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
    printf("Execution time: %ld microsec\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}
