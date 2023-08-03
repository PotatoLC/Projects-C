/*
El programa cuenta el número total de caracteres en la entrada de texto y muestra el resultado al final.
*/


#include <stdio.h>

main(){
    long nc;
    nc = 0;

    while (getchar() != EOF) {
        nc ++;
    }
    printf("Total de caracteres %1d ", nc);
}
