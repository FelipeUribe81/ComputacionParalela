#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
// #include "modulo.h"

// Definimos la funcion clrscr()
#define clrscr() printf("\e[1;1H\e[2J")

//Cada hilo opera un elemento en la matriz resultante
void *mult(void *arg)
{
    int *data = (int *)arg;
    int k = 0, i = 0;

    int x = data[0];
    for (i = 1; i <= x; i++)
        k += data[i] * data[i + x];

    int *p = (int *)malloc(sizeof(int));
    *p = k;

    //Se utiliza para terminar el hilo y pasar el valor a un puntero
    pthread_exit(p);
}

// Función Main
int main(int argc, char **argv)
{
    int matrixSize = (int)atof(argv[1]);

    int matA[matrixSize][matrixSize], matB[matrixSize][matrixSize];

    int r1 = matrixSize, c1 = matrixSize, r2 = matrixSize, c2 = matrixSize, i, j, k;

    // Generación de valores aleatorios para la matriz matA
    srand(time(NULL) * clock());

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            matA[i][j] = rand() % 10;

    // Generación de valores aleatorios para la matriz matB
    srand(time(NULL) * clock());

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            matB[i][j] = rand() % 10;

    clrscr();

    // Impresión de la matriz A
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
            printf("%d ", matA[i][j]);
        printf("\n");
    }

    printf("\n");

    // Impresión de la matriz B
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d ", matB[i][j]);
        printf("\n");
    }

    int max = r1 * c2;

    //Declaraciónde un arreglo de hilos de tamaño r1*c2
    pthread_t *threads;
    threads = (pthread_t *)malloc(max * sizeof(pthread_t));

    int count = 0;
    int *data = NULL;
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
        {

            //Almacenando filas y colimnad en data
            data = (int *)malloc((20) * sizeof(int));
            data[0] = c1;

            for (k = 0; k < c1; k++)
                data[k + 1] = matA[i][k];

            for (k = 0; k < r2; k++)
                data[k + c1 + 1] = matB[k][j];

            //creación  de los hilos
            pthread_create(&threads[count++], NULL,
                           mult, (void *)(data));
        }

    printf("\nRESULTANT MATRIX IS --> \n\n");
    for (i = 0; i < max; i++)
    {
        void *k;

        //Uniendo todos los hilso y recogiendo los datos retornados
        pthread_join(threads[i], &k);

        int *p = (int *)k;
        printf("%d ", *p);
        if ((i + 1) % c2 == 0)
            printf("\n");
    }

    return 0;
}