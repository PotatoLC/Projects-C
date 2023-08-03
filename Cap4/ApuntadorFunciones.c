#include <stdio.h>
#include <string.h>
#include "librerialineas.h"
#include "gestorBuffer.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int main(int argc, char *argv[]) {
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }

    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        // Metodo de ordenación. Puntero a funciones
        if (numeric) {
            qsortGen(lineptr , 0 , nlines-1 ,(int (*)(void *, void *))numcmp);
        } else {
            qsortGen(lineptr , 0 , nlines-1 ,(int (*)(void *, void *))mystrcmp);
        }
        writelines(lineptr, nlines);
        return 0;
        
    } else {
        printf("Entrada demasiado grande para ser ordenada");
        return 1;
    }
}


