#include <stdio.h>
#include <omp.h>

int main(){

int id_hilo;
int num_hilo;


/* 

El id_hilo se especifica como privado,
 */

#pragma omp parallel private(id_hilo)
{
    id_hilo = omp_get_thread_num();
    printf("Hello world %d\n", id_hilo);
}


    return 0;
}