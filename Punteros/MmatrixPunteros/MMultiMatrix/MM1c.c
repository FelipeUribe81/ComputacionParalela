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

//Se crea un vector de gran tamaño para reservar la memoria
#define SIZE (1024*1024*64*3)
static double MEM_CHUNK[SIZE];

//Esta funcion multiplica las matrices con el metodo clasico
void multiMatrix(int N, double *a,double *b, double *c){
    int i, j, k;
#pragma omp for 
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){  
            double *auxA, *auxB, suma = 0;  
            auxA = a+(i*N);
            auxB = b+j;            
            for (k = 0; k < N; k++, auxA++, auxB+=N){
                suma += (*auxA * *auxB);
            }
            c[i*N+j] =  suma;
        }
    }
}
//Funcion principal
int main(int argc, char **argv){


//Se verifica que el usuario haya hecho bien la insercion de todos los parametros de la ejecucion
    if (argc != 3){
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


    double *a;
    double *b;
    double *c;
    //Se asignan los espacios de memoria para cada matriz
    a = MEM_CHUNK;
    b = a + N*N;
    c = b + N*N;

    //Declaracion del pragma omp
    omp_set_num_threads(hilos);
#pragma omp parallel
    {

#pragma omp master

    initMatrix(N, a,b);

    //printf("Matriz A \n");
    //printMatrix(N, a);
    //printf("\n");
    //printf("Matriz b \n");
    //printMatrix(N, b);
    //printf("\n");
    //printf("MUltiplicación normal: \n");
    //Los comentarios son simples pruebas de impresion
    sample_start();
    multiMatrix(N, a, b, c);
    sample_stop();
    sample_end();
    //printf("\n");
    //printMatrix(N, c);

    }
}