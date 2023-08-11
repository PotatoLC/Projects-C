/* Manejo de ficheros con c para leer todas las referencias almacenadas y actualizar las mismas antes de salir */

#include <stdio.h>
#include <string.h>
#include "3-Sabiduria.h"

int main() {
    int resp;
    char palabra[1000];
    char tipo[20];

    do {
        resp = menu();
        switch (resp) {
            case 0:
                agregarRecurso();
                break;
            case 1:
                printf("\n\nEscribe lo que quieras buscar (puede ser por nombre de curso, instructor o plataforma)\n ---->   ");
                scanf("%99s", palabra);
                printf("\nEscribe como quieres buscar (Instructor, Platafora, Nombre)\n ------>  ");
                scanf("%19s", tipo);
                buscarElemento(palabra, tipo);
                break;
            case 2:
                printf("\n\nLos archivos que tengo guardados son: \n\n");
                mostrarArchivos(1, (char *[]){"3-Recursos.txt"});
                break;
            default:
                printf("\n\nGracias por utilizar la herramienta para recursos guardados\n\n");
                break;
        }
    } while (resp != 3);

    return 0;
}


