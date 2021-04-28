#include <stdlib.h>
#include <stdio.h>
#include "comp.h"

int main(int argc, char **argv){
    long double numero = (long double) atof(argv[1]);
    long double  size = (long double) atof(argv[2]);
    numero = numero/180*M_PI;
    long double sin = sinFunction(numero, 0, size, 0.0);
    printf("%Lf\n",sin);
}