#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED
#include <stddef.h>
#include <sys/time.h>

int sizeC;
struct timeval start, end;

// Se declara el tamaño de la matriz
int setSizeMatriz(int size);

// Se declara ka firma del metodo
void MatrizAletoria(int matriz[][sizeC], int aleatorio);

void sample_start();

void sample_stop();

void sample_end();

#endif
