#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

#include <stddef.h>
#include <sys/time.h>


void initMatrixDynamic(int N, double **a,double **b, double **C);
void printMatrixDynamic(int N, double **matrix);
void matrixDynamicFree(int N, double **a,double **b, double **c);

extern void sample_start();
extern void sample_stop();
extern void sample_end();

#endif