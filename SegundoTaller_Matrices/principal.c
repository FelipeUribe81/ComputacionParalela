/******************************************************************************
                             UNIVERSIDAD SERGIO ARBOLEDA
                         COMPUTACIÓN PARALELA Y DISTRIBUIDA
                                 Felipe Uribe Guevara
                                    CC: 1000970791
                           Gustavo Adolfo Castillo Clavijo
                                    CC: 1003559564
*******************************************************************************/
/******************************************************************************
MULTIPLICACIÓN DE MATRICES
*******************************************************************************
Requerimientos del problema:
1.- Crear un programa en C para multiplicar 2 Matrices de IGUAL tamaño.
2.- El tamaño debe ser ingresado como argumento de entrada.
3.- Crear un módulo para la inicialización de matrices de forma aleatoria.
4.- El módulo de inicialización de las matrices debe ir separado.
5.- Se debe crear el interfaz.h.
6.- Se debe crear el Makefile.
7.- Subir los fichero: modulo.h, modulo.c, principal.c, Makefile.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> 
#include <time.h>
#include "modulo.h"


int size;

void LlenarMatriz(int matriz[][size]){
    // Se ingresan los datos de la matriz
    printf("\nIngrese los valores de la matriz: \n\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
         scanf("%d",&matriz[i][j]);   
        }
        
    }
}

void ImprimirMatriz(int matriz[][size]){   
    // Se imprimen los datos de la matriz
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void MultipliacionMatrices(int matrizA[][size], int matrizB[][size], int matrizR[][size]){
    // Se multpilican dos matrices
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int R = 0;
            for (int z = 0; z < size; z++){
                R += matrizA[i][z] * matrizB[z][j];
            }
        matrizR[i][j] = R;
        }
    }
}

int main(int _, char **entrada){
      
    srand(time(NULL));
    size = (int) atof(entrada[1]);  


    int aleatorio = (int) atof(entrada[2]);
    setSizeMatriz(size);
    
    // Declaramos las futuras matrices
    int matrizA[size][size], matrizB[size][size], matrizR[size][size];

    // Se crea la primera matriz aleatoria
    MatrizAletoria(matrizA, aleatorio);
    //LlenarMatriz(matrizA, aleatorio);
    //printf("\nMatriz A \n");
     
    //ImprimirMatriz(matrizA);
    
    // Se crea la segunda matriz aleatoria
    MatrizAletoria(matrizB, aleatorio);
    //LlenarMatriz(matrizB, aleatorio);
    //printf("\nMatriz B \n");
    //ImprimirMatriz(matrizB);

    // Se multiplican amabas
    sample_start();
    MultipliacionMatrices(matrizA, matrizB, matrizR);
    sample_stop();

    sample_end();
    //ImprimirMatriz(matrizR);
    
    return 0;
}