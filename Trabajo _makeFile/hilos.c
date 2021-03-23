/******************************************************************************
                             UNIVERSIDAD SERGIO ARBOLEDA
                         COMPUTACIÓN PARALELA Y DISTRIBUIDA
                                 Felipe Uribe Guevara
                                    CC: 1000970791
*******************************************************************************/
/******************************************************************************
SUMA DE DOS VECTORES, CON ARGUMENTOS DE ENTRADA AL EJECUTABLE
*******************************************************************************
Requerimientos del problema:
1. Ingreso del tamaño por consola (en el ejecutable).
2. El valor de aleatoriedad sea el segundo parametro.
*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initVectores(int ramdom, int SZ, double v1[SZ], double v2[SZ], double v3[SZ]){
    int i;
    time_t t;

    /*Inicializes random numbre generator */
    srand((unsigned) time(&t));

    for (i = 0; i < SZ; i++)
    {
        v1[i] = rand() % ramdom;
        v2[i] = rand() % ramdom;
        v3[i] = 0;
    }
    
}

int main(int argc, char **argv){
    int SZ; // TAMAÑO DEL VECTOR

    int R; // Ingreso el valor de aleatoriedad

    // Ingreso el tamaño del vector
    SZ = (int) atof(argv[1]);   
    // Ingreso el tamaño del vector
    R = (int) atof(argv[2]);  
    double vect1[SZ], vect2[SZ], res[SZ];

  
    initVectores(R, SZ, vect1, vect2, res);
    printf("Val V1: \n");
    for (int i = 0; i < SZ; i++)
    {   
        printf(" %f", vect1[i]);
        /* code */
    }
    printf("\n");
    
    printf("Val V2: \n");
     for (int i = 0; i < SZ; i++)
    {   
        printf(" %f", vect2[i]);
        /* code */
    }
    printf("\n");
    
    printf("Val Res: \n");
     for (int i = 0; i < SZ; i++)
    {   
        res[i] = vect1[i] + vect2[i];
        printf(" %f", res[i]);
        /* code */
    }
    printf("\n");
    printf("\n");
    
  return 0;  
}