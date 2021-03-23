#include <stdio.h>

int main(){
    char a; 
    char *pchar;
    
    pchar =&a;
    *pchar = 'U';

    printf("la dirección de memoria de 'a' es: %p \n",&a);
    printf("y su contenido es: %c \n",*pchar);
        
    return 0;
}