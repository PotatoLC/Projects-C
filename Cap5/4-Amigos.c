#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "4-Amigos.h"

char gustos[][50] = {"Leer", "Comer", "Bañarse", "Pasear perros", "Programar", "Estudiar", "Cocinar", 
                                "Comer", "Ver TV", "Ver Twitch", "Tomar refresco", "Escuchar musica", "Limiar",
                                "Dormir", "Entrenar algun deporte", "Trabajar", "Grabar"};
char nombres[][50] = {"Juan", "Paco", "Miguel", "Victor", "Nate", "Paco", "Antonio", "Axel", "Francisco"}; 

// Sacamos el tamaño de los array
int tamanoGustos = sizeof(gustos) / sizeof(gustos[0]); 
int tamanoNombre = sizeof(nombres) / sizeof(nombres[0]); 
    
extern char gustos_mios[][50]; //Declaramos la variable de forma externa
extern int numMisGustos;


int numAleatorio(int tamano) {
    return rand() % tamano;
}

int compararGustos(char gustos_mios[MAX_GUSTOS][50], int numGustosMios, char gustosAmigos[MAX_GUSTOS][50], int numGustosSuyos) {
    int gustosComun = 0;

    for (int i = 0; i < numGustosMios; i++) {
        for ( int j = 0; j < numGustosSuyos; j++) {
            if (strcmp(gustos_mios[i], gustosAmigos[j]) == 0 ) {
                gustosComun ++;
                break;
            }
        }
    }
    return gustosComun;
}

void llamarPersonas() {
    strcpy(Personas[0].nombre, nombres[numAleatorio(tamanoNombre)]);
    strcpy(Personas[0].gustos[0], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[0].gustos[1], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[0].gustos[2], gustos[numAleatorio(tamanoGustos)]);
    Personas[0].numero_gustos = 3;

    strcpy(Personas[1].nombre, nombres[numAleatorio(tamanoNombre)]);
    strcpy(Personas[1].gustos[0], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[1].gustos[1], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[1].gustos[2], gustos[numAleatorio(tamanoGustos)]);
    Personas[1].numero_gustos = 3;

    strcpy(Personas[2].nombre, nombres[numAleatorio(tamanoNombre)]);
    strcpy(Personas[2].gustos[0], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[2].gustos[1], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[2].gustos[2], gustos[numAleatorio(tamanoGustos)]);
    Personas[2].numero_gustos = 3;

    strcpy(Personas[3].nombre, nombres[numAleatorio(tamanoNombre)]);
    strcpy(Personas[3].gustos[0], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[3].gustos[1], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[3].gustos[2], gustos[numAleatorio(tamanoGustos)]);
    Personas[3].numero_gustos = 3;

    strcpy(Personas[4].nombre, nombres[numAleatorio(tamanoNombre)]);
    strcpy(Personas[4].gustos[0], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[4].gustos[1], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[4].gustos[2], gustos[numAleatorio(tamanoGustos)]);
    Personas[4].numero_gustos = 3;

    strcpy(Personas[5].nombre, nombres[numAleatorio(tamanoNombre)]);
    strcpy(Personas[5].gustos[0], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[5].gustos[1], gustos[numAleatorio(tamanoGustos)]);
    strcpy(Personas[5].gustos[2], gustos[numAleatorio(tamanoGustos)]);
    Personas[5].numero_gustos = 3;
}

void imprimirAmigos(char gustos_mios[MAX_GUSTOS][50], int numMisGustos) {
    int i;
    int personasConGustosSimilares = 0;
    
    for (i = 0; i < MAX_AMIGOS; i++) {
        int gustosComun = compararGustos(gustos_mios, numMisGustos, Personas[i].gustos, Personas[i].numero_gustos);
        if (gustosComun >= 1) {
            personasConGustosSimilares = 1;

        }
    }

    if (personasConGustosSimilares > 0) {
        int i, a, b;
        printf("\nLas personas que encontre con gustos similares son: \n\n");
        for (i = 0; i < MAX_AMIGOS; i++){
            int gustosComun = compararGustos(gustos_mios, numMisGustos, Personas[i].gustos, Personas[i].numero_gustos);
            if (gustosComun >= 1) {
                printf("%s con gustos en comun %d ----> ", Personas[i].nombre, gustosComun);
                int gustosImp = 0;
                for (a = 0; a < numMisGustos; a++) {
                    for ( b = 0; b < Personas[i].numero_gustos; b++) {
                        if (strcmp(gustos_mios[a], Personas[i].gustos[b]) == 0) {
                            if (gustosImp > 0) {
                                printf(" y ");
                            }
                            printf(" %s" , gustos_mios[a]);
                            gustosImp ++;
                            break;
                        }
                    }
                }
                printf("\n\n");
            }
        }
    }

    else printf("\n\nNo logre encontrar a alguien con gustos similares\n\n");
}

void ingresarGustosUsuario(char gustos[MAX_GUSTOS][50], int *numGustos) {
    printf("Ingresa tus gustos :\n");
    char buffer[50];
    while(*numGustos <= MAX_GUSTOS) {
        printf("Gusto %d ---> ", *numGustos + 1);
        fgets(buffer, sizeof(buffer), stdin); // Leemos lo que haya ingresado el usuario
        
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len -1] == '\n') buffer[len -1 ] = '\0';

        strcpy(gustos[*numGustos] , buffer);
        (*numGustos) ++;
    }
}

void imprimirGustos(){
    int i;
    printf("\n\nLos gustos que tengo almacenados son: \n");
    for (i = 0; i <= tamanoGustos; i++) {
        printf("---> %s\n", gustos[i]);
        i++;
    }
}

int menu() {
    char resp = 0;
    printf("\n\nPresiona ENTER para continuar");
    getchar();

    while( resp < '0' || resp > '4') {
        printf("\n---------------------------------------- \n");
        printf("[0] ----> Mostrar gustos almacenados\n");
        printf("[1] ----> Agregar gustos personales\n");
        printf("[2] ----> Mostrar gustos personales\n");
        printf("[3] ----> Buscar amigos nuevos\n");
        printf("[4] ----> Salir\n");
        printf("-----------------------------------------");
        printf("\n\n  Tu respuesta ---->  ");
        scanf(" %c", &resp);
        getchar();
    }
    return resp -'0';
}

void imprimirGustosUsuario(char gustos_mios[MAX_GUSTOS][50], int numMisGustos){
    int i;

    if ( numMisGustos == 0) {
        printf("Aun no agregas ningun gusto");
    }

    else {
        printf("\n\nLos gustos que tengo almacenados son: \n");
        for (i = 0; i < numMisGustos; i++) {
            printf("---> %s\n", gustos_mios[i]);
        }
    }
}



