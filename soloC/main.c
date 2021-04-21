#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cfib.h"

int main(int argc, char **argv){

    int arg=0, numiter = 0, i;
    clock_t t;
    if (argc!=3){
        printf("unexpected arguments, two were expected\n");
        return 1;
        //return main(int argc, char **argv);
    }

    arg = atoi(argv[1]);
    numiter = atoi(argv[2]);
    t = clock();
    
    for(i =0; i<numiter; i++){
        cfib(arg);
    }

    t = clock() - t;
    printf("%f\n", ((float)t)/100000/numiter*1e9);
    return 0;
}


