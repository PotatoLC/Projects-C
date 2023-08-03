/*
El programa busca líneas que contengan una palabra específica (patrón) proporcionada como argumento de línea de comando. Lee líneas 
de entrada y busca el patrón utilizando la función strstr de la biblioteca estándar. Si encuentra una coincidencia, imprime la línea.
Al final, devuelve el número de líneas encontradas. Si no se proporciona el patrón como argumento, muestra un mensaje para solicitarlo.
*/

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
