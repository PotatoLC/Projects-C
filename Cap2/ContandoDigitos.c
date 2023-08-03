
#include <stdio.h>

main(){
    int c, i, nwhite, nother;
    int ndigit [10];

    nwhite = nother = 0;

    for ( i = 0; i < 10; i ++) {
        ndigit[i] = 0;
    }

    while ((c=getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ ndigit [c - '0'];
        } else if ( c == ' ' || c == '\t' || c == '\n') {
            nwhite ++;
        } else nother ++;
    }
    printf("Digitos ---> "); //Imprimir array
    for ( i = 0; i < 10; i ++) {
        printf("%d", ndigit); }
    printf(", espacios en blanco = %d, otros %d\n", nwhite, nother);
}