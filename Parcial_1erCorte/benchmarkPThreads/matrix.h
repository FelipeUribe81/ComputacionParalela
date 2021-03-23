/***********************************************************************************/
/*                           Universidad Sergio Arboleda                           */
/*                     Escuela de Ciencias Exactas e Ingeniería                    */
/*                               Autores: Shuo Yang                                */
/*     Editores: Camilo Andres Romero Maldonado & juan José Montenegro Pulido      */
/*                        Programación Paralela y Distribuida                      */
/*                     Profesor: PhD. John Jairo Corredor Franco                    */
/***********************************************************************************/

/*  Este programa tiene como objetivo multiplicar dos matrices de tamaño simétrico */
/*                    (N*N) haciendo uso de hilos (posix Threads)                  */

/******************* Importación de Módulos y bibliotecas necesarias *****************/
#include <stddef.h>

/**************************** Definición de la interfaz ****************************/
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/************************ Declaración de variables globales ************************/
int size, threadsNumber;
double **matrixA, **matrixB, **result;

/******************** Declaración de funciones de la interfaz **********************/

// 1. Función para inicializar las martices de tamaño matrixSize.
void initMatrix(double **matrix, int matrixSize, int randomRange);

// 2. Reserva los espacios en memoria donde va a almacenar las matrices
double **allocateMatrix(int size);
/******************************* Rutina de los Hilos *******************************/
/*           Cada hilo trabaja en una porción de la matrizA (matrixA)              */
/*    El inicio y el final de la porción dependen directamente del argumento       */
/*    de entrada 'arg', el cual es el ID asignado a la secuencia de los hilos      */
/***********************************************************************************/
void *worker(void *arg);
#endif
