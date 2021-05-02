#include <stdlib.h>
#include <stdio.h>
#include "herminatePolinomial.h"

int herminate(int n, int x){
    if (n == 0){
        return 1;
    }else if (n == 1){
        return 2 * x;
    }else{
        return 2 * x * herminate(n-1,x) - 2 * (n - 1) * herminate(n-2,x);
    }
}