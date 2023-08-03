
#include <stdio.h>

main(){
    long nc;
    nc = 0;

    while (getchar() != EOF) {
        nc ++;
    }
    printf("Total de caracteres %1d ", nc);
}