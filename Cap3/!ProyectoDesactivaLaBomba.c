#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Se definen constantes 
#define MAX_BOMBA 100
#define MIN_BOMBA 20
#define MAX_USER 10 
#define MIN_USER 1

//Prototipo de funciones utilizadas
int numeroAle(int max, int min), numeroEnArray(int numero, int* numeros_usuario, int tam);
void juego(), mostrarDigitosNoEncontrado(int numero, int* numeros_usuario);
char pregunta();


int main() {
    srand(time(NULL));  
    /* Creamos la semilla en la hora actual del sistema, esto para que cada que se utilice, genere num aleatorios */

    printf("\n\nJuego que consiste en igualar el valor de la bomba con los 5 numeros dados\n");
    printf("Solo puedes ocupar '+', '-' y '*'\n");
    printf("\nNOTA ---> El juego no cuenta con jerarquia de operaciones, asi que ingresalas en el orden que desees que se realicen :)\n");
    juego();

    char resp = pregunta();
    while (resp == 'Y' || resp == 'y') {
        juego();
        resp = pregunta();
    } 

    return 0;

}

int numeroAle(int max, int min) {
    int numAle = rand() %  max + min; // Con el "%" establecemos los rangos que queremos obtener
    return numAle;
}

void juego() {
    int i;
    int numeros_usuario[5];
    int numBomba;

    // Se genera el numero de la bomba
    numBomba = numeroAle(MAX_BOMBA, MIN_BOMBA);
    
    // Se generan los numeros del usuario y se agregar al array
    for ( i = 0; i < 5; i++) {
        numeros_usuario[i] = numeroAle(MAX_USER, MIN_USER);
    }

    printf("\n\n\nEl numero de la bomba es ----> %d\n", numBomba);
    printf("\nTus numeros son: \n");
    for (i = 0; i < 5; i++) {
        printf(" --> %d \n", numeros_usuario[i]);
    }
    printf("\nEscribe tu respuesta con el formato: numero1 operacion numero2 operacion ... \n\n");

    // Leemos lo que haya ingresado el usuario
    int resultado = 0;
    char operador = '+';
    int numero = 0;
    char enter;

    while (1) { //Creamos un bucle infinito 
        int c = getchar();        

        // Si encontramos un operador, realizamos su operacion
        if (c >= '0' && c <= '9') {
            numero = numero * 10 + (c - '0');
        }

        else if (c == '+' || c == '-' || c == '*'){
            if (numeroEnArray(numero, numeros_usuario, 5)) {
                if (operador == '+') resultado += numero;
                else if (operador == '-') resultado -= numero;
                else if (operador == '*') resultado *= numero;
                
                operador = c; //Actualizamos operador para la siguiente iteraccion
                numero = 0; // Reiniciamos el numero para leer el siguiente numero ingresado
            } 
            else {
                mostrarDigitosNoEncontrado(numero, numeros_usuario);
            }
        }

        else if (c == '\n') {
            if (numeroEnArray(numero, numeros_usuario, 5)) {
                if (operador == '+') resultado += numero;
                else if (operador == '-') resultado -= numero;
                else if (operador == '*') resultado *= numero;
                break;
            }
            else {
                mostrarDigitosNoEncontrado(numero, numeros_usuario);
               }
            break;
        }
        

    }
    

    // Checamos si el usuario alcanzó o no el numero de la bomba
    if (resultado == numBomba) printf("\n\nFelicidades, lograste desactivar la bomba\n");
    else printf("\n\nLo siento hermano, tu resultado %d no logró desactivar la bomba\n", resultado);
}

char pregunta(){
    // Función que pregunta al usuario jugar de nuevo 
    printf("\n\n¿Deseas jugar de nuevo? [Y/N]\n --->  ");
    char resp;
    scanf(" %c", &resp);
    getchar();

    while (resp != 'Y' && resp != 'N' && resp != 'y' && resp != 'n') {
        printf("\n\nIngresa una opcion valida [Y/N]\n --->  ");
        scanf(" %c", &resp);
        getchar();
    }
    return resp;
}

// Funcion que checa si un numero está o no dentro de la lista de numeros generados
int numeroEnArray(int numero, int* numeros_usuario, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        if (numero == numeros_usuario[i]) return 1; // El numero está dentro de array
    }
    return 0; // El numero no está en el array
}


void mostrarDigitosNoEncontrado(int numero, int* numeros_usuario) {
    printf("\n ---> El numero ");
    int digitos[10] = {};
    int temp = numero;


    // Obtenemos los dígitos del número
    while (temp > 0) {
        int digito = temp % 10;
        digitos[digito] = 1;
        temp /= 10;
    }

    // Mostramos los dígitos no encontrados en el array de números del usuario
    int i;
    for (i = 0; i < 10; i++) {
        if (digitos[i] == 1 && !numeroEnArray(i, numeros_usuario, 5)) {
            printf("%d ", i);
        }
    }

    printf(" no te lo he dado brother");
}
