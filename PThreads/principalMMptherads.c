/* 
MUltiplicación de matrices usando pthreads (posix threads)
autor: Felipe Uribe
Fecha
Asignatura
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Declaramos variables globales
int SZ, NThreads;

// Función que calcula un simple elemento en la matriz resultante
void *multiplicacion(void *arg){
    int *datos = (int *) arg;
    int i= 0, j =0;
    int aux = datos[0];
    
    for ( i = 1; i <= aux; i++)
    {
        j += datos[i] * datos[i + aux];
    }
    int *p = (int *) malloc(sizeof(int));
    *p = j;

    // Se necesita finalizar los Threads
    pthread_exit(p);
}

// Función que inicializa la matriz con dos parametros (matriz y rango)
void initMM(double matriz[][SZ], double range){
        for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            matriz[i][j] = range * (j+1);
        }
    }
}

// Función que imprime en consola una matriz
void printMM(double matriz[][SZ]){
    for (int i = 0; i < SZ; i++){
        for (int j = 0; j < SZ; j++){
            printf("%f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char**arg){

    if (argc != 3)
    {   
        printf("Argumentos: TamañoMatriz NumHIlos");
        return -1;
    }


    SZ = (int)atof(arg[1]);
    NThreads = (int)atof(arg[2]);

    double mmA[SZ][SZ], mmB[SZ][SZ], mmR[SZ][SZ];
    
    // Se inicializan las matrices A y B
    initMM(mmA, 4.0);
    initMM(mmB, 3.8);

    // Se imprimen las matrices
    printf("Matriz A\n");
    printMM(mmA);
    printf("Matriz B\n");
    printMM(mmB);    

    // Se declara vector de hilos de tamaño NThreads
    pthread_t *hilos;
    hilos = (pthread_t *) malloc(NThreads* sizeof(pthread_t));

    int *datos = NULL;
    int count = 0;

    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            // Almacenamos filas y columnas en datos
            datos = (int *) malloc()  
        }
        
    }
    
}