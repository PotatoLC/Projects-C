// Proyecto para encriptar y desencriptar mensajes mediante cifrado Cesar

#include <stdio.h>

int menu();
void encriptar(char mensaje[], int movimientos), desencriptar(char mensaje[], int movimientos), inicio();
char pregunta();

int main() {
    printf("\n\nProyecto para encriptar y desencriptar mensajes\n\n");
    inicio();
    char resp = pregunta();
    while (resp == 'Y' || resp == 'y') {
        inicio();
        resp = pregunta();
    } 
    if (resp == 'N' || resp == 'n') return 0;
}

int menu() {
    /* Función que muestra el menú, solo tiene dos opciones validas 0 y 1, 
    si la respuesta es diferente a cualquiera de esas dos, no podemos salir de la función */

    printf("\n\nIngresa que deseas hacer\n");
    printf("Presiona ENTER para comenzar  ");
    int resp = getchar();

    while (resp != '0' && resp != '1') {
        printf("\n\nSelecciona una opcion valida: \n\n");
        printf("0 ------> Encriptar \n");
        printf("1 ------> Desencriptar \n");
        printf("\nTu respuesta -------->  ");
        resp = getchar();
        getchar();
    }
    return resp ; 
}

void encriptar(char mensaje[], int movimientos) {
    // Funcion que recibe un mensaje y un numero de movimientos, esta se encarga de
    // reccorre n veces la letra, esto para 'encriptar' el mensaje
    int i = 0;

    while (mensaje[i] != '\0') {
        if (mensaje[i] >= 'A' && mensaje[i] <= 'Z') {
            mensaje [i] = ((mensaje[i] - 'A') + movimientos) %26 + 'A';
        }
        else if (mensaje[i] >= 'a' && mensaje[i] <= 'z') {
            mensaje[i] = ((mensaje[i] - 'a') + movimientos) %26 + 'a';
        }
        i ++;
    }
    
    printf("\n\nEl mensaje encriptado es:\n ---> %s \n\n", mensaje);
}

char pregunta(){
    // Función que pregunta al usuario quiere hacer otra consulta
    printf("\n\n¿Deseas hacer otra consulta? [Y/N]\n --->  ");
    char resp;
    scanf(" %c", &resp);
    getchar();

    while (resp != 'Y' && resp != 'N' && resp != 'y' && resp != 'n') {
        printf("Ingresa una opcion valida [Y/N]\n --->  ");
        scanf(" %c", &resp);
        getchar();
    }
    return resp;
}

void inicio(){
    //Función para iniciar el programa, ya sea para encriptar o desencriptar
    int movimientos;
    char mensaje[1000];
    int opcionElegida = menu();

    if (opcionElegida == '1') {
        printf("\n\nIngresa el mensaje que quieras desencriptar \n --->  ");
        scanf("%999[^\n]", mensaje);
        printf("Ingresa cuantas veces quieres retroceder el mensaje \n --->  ");
        scanf("%d", &movimientos);
        desencriptar(mensaje, movimientos);
    }
    else {
        printf("\n\n\nIngresa el mensaje que quieras encriptar \n --->  ");
        scanf("%999[^\n]", mensaje); // Lee el mensaje hasta que se de un salto de linea (ENTER)
        printf("Ingresa cuantos lugares quieres mover el mensaje \n --->  ");
        scanf("%d", &movimientos);
        encriptar(mensaje, movimientos);
    }
}

void desencriptar(char mensaje[], int movimientos) {
    // Funcion que recibe un mensaje y un numero de movimientos, esta se encarga de reccorre n veces la letra, esto para 'encriptar' el mensaje
    int i = 0;
    int longitud = 0;

    while (mensaje[longitud] != '\0') longitud ++; // Calcula la longitud del mensaje

    while (i < longitud) {
        if ( mensaje[i] >= 'A' && mensaje[i] <= 'Z') {
            int desplazamiento = (mensaje[i] - 'A') - movimientos;
            if (desplazamiento < 0) desplazamiento += 26;  // Ajusta el desplazamiento para evitar valores negativos
            mensaje[i] = (desplazamiento % 26) + 'A';
        }
        else if ( mensaje[i] >= 'a' && mensaje[i] <= 'z') {
            int desplazamiento = (mensaje[i] - 'a') - movimientos;
            if (desplazamiento < 0) desplazamiento += 26;
            mensaje[i] = (desplazamiento % 26) + 'a';
        }
        i++;
    }

    printf("\n\nEl mensaje desencriptado es:\n ---> %s \n\n", mensaje);
}
