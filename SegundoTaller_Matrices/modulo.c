#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para establecer el tamaño de la matriz
int setSizeMatriz(int size){
    sizeC = size;
  return sizeC;
}

// Función de matriz aleatoria
void MatrizAletoria(int matriz[][sizeC], int aleatorio){
   
    for (int i = 0; i < sizeC; i++){
        for (int j = 0; j < sizeC; j++){
            matriz[i][j] = (rand() % aleatorio) + 1;
        }
    }    
}

void sample_stop(){
    gettimeofday(&end, NULL);
}

void sample_start(){
    gettimeofday(&start, NULL);
}

void sample_end(){
    printf("%ld microseg\n",((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}