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
/**************************
MULTIPLICACIÓN DE MATRICES (Algortimo tradicional)
***************************
Requerimientos del problema:
1.- Ficheros a subir: Makefile (automatización compilación), 1 módulo, 2 principales (clásica y transpuesta), 1 interfaz
2.- Documentar secciones significativas del código
3.- No comprimir lo ficheros (por favor)
4.- Si usan repositorio, solo enviar el enlace de la carpeta donde se encuentren los ficheros (puntos adicionales)
5.- Los ficheros deben tener membrete de la universidad, escuela, programa, estudiante (autor), correo electrónico y fecha.
6.- El módulo debe contener las funciones: Inicio medida de tiempo, Final medida de tiempo, Impresión medida de tiempo, Inicialización de las matrices, impresión de matrices.
7.- La función de impresión se debe hacer para validar el cumplimiento del algoritmo (para las tomas de rendimiento se pueden inhabilitar)
8.- De hacerlo por grupo, sólo se hace una entrega.
***************************/
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "modulo.h"

//Funcion principal
int main(int argc, char **argv)
{
    //Se verifica que el usuario haya hecho bien la insercion de todos los parametros de la ejecucion
    if (argc != 3)
    {
        fprintf(stderr, "%s <matrix size> <number of threads>\n", argv[0]);
        return -1;
    }

    // Tamaño de la matriz
    int N = atoi(argv[1]);
    argc--;
    argv++;
    //numero de hilos
    int hilos = atoi(argv[1]);
    argc--;
    argv++;

    double **MtxA = NULL, **MtxB = NULL, **MtxC = NULL;

    // Se reserva de forma dinamica el espacio de memoria para cada una de las matrices de tamaño N * N

    if ((MtxA = (double **)malloc(N * sizeof(double *))) == NULL ||
        (MtxB = (double **)malloc(N * sizeof(double *))) == NULL ||
        (MtxC = (double **)malloc(N * sizeof(double *))) == NULL)
    {
        printf("INSUFICIENTE ESPACIO DE MEMORIA\n");
        return -1;
    }

    for (int i = 0; i < N; i++)
    {
        if ((MtxA[i] = (double *)malloc(N * sizeof(double))) == NULL ||
            (MtxB[i] = (double *)malloc(N * sizeof(double))) == NULL ||
            (MtxC[i] = (double *)malloc(N * sizeof(double))) == NULL)
        {
            printf("INSUFICIENTE ESPACIO DE MEMORIA\n");
            return -1;
        }
    }

    //Declaracion del pragma omp
    omp_set_num_threads(hilos);
#pragma omp parallel
    {
#pragma omp master

        initMatrixDynamic(N, MtxA, MtxB, MtxC);

        printf("Matriz A \n");
        printMatrixDynamic(N, MtxA);
        printf("\n");
        printf("Matriz B \n");
        printMatrixDynamic(N, MtxB);
        printf("\n");
        sample_start();
        int i, j, k;
#pragma omp for
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                double *auxA, *auxB, suma = 0.0;
                auxA = *(MtxA + i);
                auxB = *(MtxB + j);
                for (k = N; k > 0; k--, auxA++, auxB++)
                {
                    suma += (*auxA * *auxB);
                }
                *(*(MtxC + i) + j) = suma;
            }
        }
    //Los comentarios son simples pruebas de impresion    multiMatrix(N, MtxA, MtxB, MtxC);
    sample_stop();
}
printf("\n");
printMatrixDynamic(N, MtxC);
sample_end();
matrixDynamicFree(N, MtxA, MtxB, MtxC);
}