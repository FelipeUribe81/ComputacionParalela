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
MULTIPLICACIÓN DE MATRICES (Algortimo con matriz traspuesta)
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
//Se crea un vector de gran tamaño para reservar la memoria
#define SIZE (1024 * 1024 * 64 * 3)
static double MEM_CHUNK[SIZE];
//Funcion que multiplica una matriz por la transpuesta de otra
void multiMatrixT(int N, double *a, double *b, double *c)
{
    int i, j, k;
#pragma omp for
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {   
            //double *auxA, *auxB, suma = 0;  
            double suma = 0;
            //auxA = a+(i*N);
            //auxB = b+(j*N);    
            //for (k= 0; k < N; k++, auxA++, auxB++){
            for (k = 0; k < N; k++){
                //suma += (*auxA * *auxB);
                suma += (a[k + i * N] * b[k + j * N]);
            }
            c[i * N + j] = suma;
        }
    }
}
//Devuelve una matriz en su propia transpuesta
double *transposeMatrix(int N, double *matrix)
{
    double *tr;
    tr = matrix + N * N;
    int i, j;
#pragma omp for
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            //printf("%f\t",matrix[i+j*N]);
            tr[j + i * N] = matrix[i + j * N];
        }
        //printf("\n");
    }
    return tr;
}
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
    //Numero de hilos
    int hilos = atoi(argv[1]);
    argc--;
    argv++;

    //Se le asigna una porcion del vector creado a cada matriz
    double *a;
    double *b;
    double *c;

    a = MEM_CHUNK;
    b = a + N * N;

    //Declaracion del pragma omp
    omp_set_num_threads(hilos);
#pragma omp parallel
    {

#pragma omp master

        initMatrix(N, a, b);
        
        double *d = transposeMatrix(N, b);
        c = d + N * N;
        //printf("Matriz A \n");
        //printMatrix(N, a);
        //printf("\n");
        //printf("Matriz B \n");
        //printMatrix(N, b);
        //printf("\n");
        //printf("Matriz transpuesta: \n");
        //printMatrix(N,d);printf("\n");

        //printf("Multiplicación con trasnpuesta: \n");
        //Los comentarios son simples pruebas de impresion
        sample_start();
        multiMatrixT(N, a, d, c);
        sample_stop();
        sample_end();
        //printMatrix(N, c);
    }
}