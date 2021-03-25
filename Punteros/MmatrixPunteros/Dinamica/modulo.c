/**************************
                             UNIVERSIDAD SERGIO ARBOLEDA
                         COMPUTACIÓN PARALELA Y DISTRIBUIDA
                                 Felipe Uribe Guevara
                            felipe.uribe@correo.usa.edu.co
                                    CC: 1000970791
                           Gustavo Adolfo Castillo Clavijo
                         gustavoa.castillo@correo.usa.edu.co
                                    CC: 1003559564
***************************/
#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>

struct timeval start, end;

//Se inicializa la matriz para memoria dinamica
void initMatrixDynamic(int N, double **a, double **b, double **c)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            *(*(a + j) + i) = 2.01 * (i + j);
            *(*(b + j) + i) = 3.01 * (i - j);
            *(*(c + j) + i) = 3.01;
        }
    }
}

// Liberación de espacio memoria reservada
void matrixDynamicFree(int N, double **a, double **b, double **c)
{
    int i;
#pragma omp parallel for
    for (i = 0; i < N; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
}

//Se imprime la matriz
void printMatrixDynamic(int N, double **matrix)
{
    int i, j;
    if (N <= 4)
    {
#pragma omp for 
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%f\t", *(*(matrix+j) + i));
            }
            printf("\n");
        }
    }
    else
    {
        //printf("Printing is allowed for maximum matrices of dimension 10");
    }
    printf("\n");
}

void sample_stop()
{
    gettimeofday(&end, NULL);
}

void sample_start()
{
    gettimeofday(&start, NULL);
}

void sample_end()
{
    printf("%ld ms \n", ((end.tv_sec ) - (start.tv_sec )));
}