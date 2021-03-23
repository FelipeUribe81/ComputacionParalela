#include <stdio.h>
#include <omp.h>

int main(){

int id_hilo;
int num_hilo;


/* 
El id_hilo se especifica como privado, entonces cada hilo 
tendra su propia copia de id_hilo.
 */

#pragma omp parallel private(id_hilo)
{
    id_hilo = omp_get_thread_num();
    printf("Hello world %d\n", id_hilo);
    /* 
    SE CREA UNA BARRERA DE SINCRONIZACIÓN, 
    EL MASTER ESPERA HASTA QUE TODOS FINALIZEN (ANTES DE IMPRIMIRSE).
     */
#pragma omp barrier 
    if (id_hilo == 0)
    {
        num_hilo = omp_get_num_threads();
        printf("El numero de hilos totales es %d\n", num_hilo);
    }
}


    return 0;
}

