#include <stdio.h>
#include <string.h>
#include "librerialineas.h"
#include "gestorBuffer.h"

#define MAXLINE 1000

// Find: Imprime lineas que coincidan con el patron del 1er argumento
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2) {
        printf("\n\nBrother, debes poner la palabra que desees buscar\n");
    } 
    else {
        while(mygetline(line, MAXLINE) > 0) {
            if(strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found ++;
            }
        }
    }

    return found;
}