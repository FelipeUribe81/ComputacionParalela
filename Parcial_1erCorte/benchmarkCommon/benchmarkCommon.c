#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "%s <matrix size> <random range>\n", argv[0]);
        return -1;
    }
    int MATRIX_SIZE = (int)atof(argv[1]);
    int RANDOM_RANGE = (int)atof(argv[2]);
    int matrixA[MATRIX_SIZE][MATRIX_SIZE], matrixB[MATRIX_SIZE][MATRIX_SIZE];
    int result[MATRIX_SIZE][MATRIX_SIZE];

    setRand();
    initMatrix(MATRIX_SIZE, RANDOM_RANGE, matrixA);
    initMatrix(MATRIX_SIZE, RANDOM_RANGE, matrixB);
    sample_start();
    multiplyMatrix(MATRIX_SIZE, result, matrixA, matrixB);
    sample_stop();
    sample_end();

    return 0;
}
