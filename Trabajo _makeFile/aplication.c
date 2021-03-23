#include <stdio.h>
#include "functions.h"

int main(){
    int a, b;
    printf("Ingrese dos numeros: ");
    if (scanf("%d + %d", &a, &b)!=2){
        fputs("Ingreso invalido!", stderr);
        return 1;
    }
    printf("%d + %d = %d", a,b, Sum(a,b));
    return 0;
}