#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

#include <stddef.h>
#include <sys/time.h>


void initMatrix(int N, double *a,double *b);
void printMatrix(int N, double *matrix);

extern void sample_start();
extern void sample_stop();
extern void sample_end();

#endif