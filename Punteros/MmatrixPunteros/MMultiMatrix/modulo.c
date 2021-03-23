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


//Se inicializa la matriz
void initMatrix(int N, double *a,double *b){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            a[j+i*N] = 2.01 * (i + j);
            b[j+i*N] = 3.01 * (i - j);          
        }
    }
}
//Se imprime la matriz
void printMatrix(int N, double *matrix){
    int i, j;
    if (N <= 4){
    #pragma omp for 
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                printf("%f\t",matrix[j+i*N]);     
            }
            printf("\n");
        }
    }else{
        //printf("Printing is allowed for maximum matrices of dimension 10");
    }
    }
    


void sample_stop(){
    gettimeofday(&end, NULL);
}

void sample_start(){
    gettimeofday(&start, NULL);
}

void sample_end(){
    printf("%ld \n",((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}