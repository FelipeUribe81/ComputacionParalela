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
int SX; //Tamaño horizontal
int SY; //Tamaño Vetical

void LlenarMatriz(int matriz[SX][SY]){
    // Se ingresan los datos de la matriz
    printf("\nIngrese los valores de la matriz: \n\n");
    for (int i = 0; i < SX; i++){
        for (int j = 0; j < SY; j++){
         scanf("%d",&matriz[i][j]);   
        }
        
    }
    
}

void ImprimirMatriz(int matriz[SX][SY]){
    // Se imprimen los datos de la primera matriz
    for (int i = 0; i < SX; i++){
        for (int j = 0; j < SY; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }   
}

void MultipliacionMatrices(int matrizA[SX][SY], int matrizB[SX][SY], int matrizR[SX][SY]){
    // Se imprimen los datos de la primera matriz

    for (int i = 0; i < SX; i++){
        for (int j = 0; j < SY; j++){
            int R = 0;
            for (int z = 0; z < SX; z++){
                R += matrizA[i][z] * matrizB[z][j];
            }
        matrizR[i][j] = R;
        }
    }
}

int main(){
    printf("Ingrese las dimensiones de las matrices nxm: \n");
    scanf("%d",&SX);
    scanf("%d",&SY);
    
    if (SX!=SY){
        printf("Las matrices no se pueden multiplicar. \nPor favor ingrese una matriz cuadrada:\n\n");
        return main();
    }
    
    // Declaramos las futuras matrices
    int matrizA[SX][SY], matrizB[SX][SY], matrizR[SX][SY];

    LlenarMatriz(matrizA);
    printf("\nMatriz A \n");
    ImprimirMatriz(matrizA);
    
    LlenarMatriz(matrizB);
    printf("\nMatriz B \n");
    ImprimirMatriz(matrizB);

    MultipliacionMatrices(matrizA, matrizB, matrizR);

    printf("\n El resultado de la multiplicación: \n");
    ImprimirMatriz(matrizR);

    return 0;
}