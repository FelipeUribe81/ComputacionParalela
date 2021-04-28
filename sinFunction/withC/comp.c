#include <stdlib.h>
#include <stdio.h>
#include "comp.h"
#include <math.h>

long double factorial(long double number){
    if (number == 0){
        return 1;
    }else{
        return factorial(number-1)*number;
    }
}

long double sinFunction(long double number, long double i, long double size, long double acum){
    if (i == size){
        return acum;
    }else{
        acum += (((long double) pow((-1), i))*((long double) pow(number, 2*i+1))/((long double) factorial(2*i+1)));
        return sinFunction(number, i+1, size, acum);
    }
}