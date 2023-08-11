/*
Queremos generar una mini red de amigos a partir de las aficiones que introducimos
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "4-Amigos.h"

int main() {
    srand(time(NULL));
    char gustos_mios[MAX_GUSTOS][50] = {};
    int numMisGustos = 0;  
    int i, respuesta;

    //Creamos a las personas con sus gustos
    llamarPersonas();
    
    do {
        respuesta = menu();
        switch(respuesta) {
            case 0: 
                imprimirGustos();
                break;

            case 1:
                ingresarGustosUsuario(gustos_mios, &numMisGustos);
                break;

            case 2:
                imprimirGustosUsuario(gustos_mios, numMisGustos);
                break;

            case 3:
                imprimirAmigos(gustos_mios, numMisGustos);
                break;

            default:
                printf("\n\nGracias por buscar amigos :)\n");
    
        } 
    } while (respuesta != 4);
    return 0;
}