/* 
Ejecutable en el cual imprime nombres, verbos y situaciones aleatorias, esto con un menú en el cual el usuario puede añadir cualquiera de estos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


// Definimos constantes
#define MAX_PALABRAS 1000
#define MAX_ELEMENTOS 100
#define MAX_CARACTERES 150


// Ponemos los prototipos de las funciones que vamos a utilizar
void mostrarSituacion(), mostrarVerbos(), mostrarNombres();
void discursoLoco(char* nombres[], int tamanoNombres, char* verbos[], int tamanoVerbos, char* situacion[], int tamanoSituacion);
int showMenu();

// Prototipo de funciones para agregar
void agregarNombre(char* nombres[], int* cantidadNombres, int tamanoMax);
void agregarVerbo(char* verbos[], int* cantidadVerbos, int tamanoMax);
void agregarSituacion(char* situacion[], int* cantidadSituacion, int tamanoMax) ;


char* nombres[] = {"Juan", "Paco", "Nate", "Kike", "Antonio", "s4vitar"};
char* verbos[] = {"corre", "nada", "salta", "lee", "escribe", "come", "duerme", "canta", "baila", 
                  "programa", "estudia", "juega", "trabaja", "resuelve su tarea", "limpia", "construye sueños"};
char* situacion[] = {"valientemente", "en Paris", "en la habitación de mi abuela", "en el desfile de modas", 
                    "mientras mi tia pelea con un pulpo", "en la fiesta de baile de los pingüinos", 
                    "en un concurso de besos", "en la reunión de extraterrestres", "mientras yo le enseño trucos nuevos a mi perro", 
                    "intentando enseñarle a un loro", "tratando de conquistar el mundo", "buscando amigos",
                    "resolviendo los ejercicios de MasterMind", "mientras Donald Trump come tacos"};


int main() {
    srand(time(NULL));
    printf("\n\nJuego para crear discursos locos\n");
    printf("Selecciona una opción");

    int respuesta;

    do {
        respuesta = showMenu();

        switch (respuesta) {
        case 0:
            mostrarNombres();
            break;
        
        case 1: 
            mostrarVerbos();
            break;

        case 2: 
            mostrarSituacion();
            break;

        case 3: 
            discursoLoco(nombres, sizeof(nombres) / sizeof(nombres[0]), verbos, sizeof(verbos) / sizeof(verbos[0]), situacion, sizeof(situacion) / sizeof(situacion[0]));
            break;

        default: // Salida del bucle
            printf("\n\nGracias por jugar :D\n");
        }
    
    } while (respuesta != 4); 
}

int showMenu() {
    char resp = 0;
    printf("\n\nPresiona ENTER para continuar");
    getchar();

    while( resp < '0' || resp > '4') {
        printf("\n\n----------- Menu ----------- \n\n");
        printf("0 -----> Mostar/Editar nombres\n");
        printf("1 -----> Mostar/Editar verbos\n");
        printf("2 -----> Mostar/Editar situaciones\n");
        printf("3 -----> Crear discurso loco \n");
        printf("4 -----> Salir \n\n");
        printf("-----------------------------");
        printf("\n\n  Tu respuesta ---->  ");
        scanf(" %c", &resp);
        getchar();
    }
    return resp - '0';
    
}

void mostrarNombres() {
    int i, numero = 0;
    char resp;
    
    printf("\n\n [O]  ----> Mostrar nombres\n [1]  ----> Agregar nombres");
    printf("\n\nTu respuesta ---->  ");
    scanf(" %c", &resp);
    getchar();

    if (resp == '0') { 
        printf("\n\nLos nombres que tengo almacenados son:\n\n");
        for (i = 0; i < sizeof(nombres) / sizeof(nombres[0]); i++)
            printf("--> %s\n", nombres[i]);
    }

    else if (resp == '1') {
        agregarNombre(nombres, &numero, MAX_ELEMENTOS);
    }

    else printf("\n\nIngresa una opcion valida\n");
        
}

void mostrarVerbos() {
    int i, numero = 0;
    char resp;
    
    printf("\n\n [O]  ----> Mostrar verbos\n [1]  ----> Agregar verbos");
    printf("\n\nTu respuesta ---->  ");
    scanf(" %c", &resp);
    getchar();

    if (resp == '0') { 
        printf("\n\nLos verbos que tengo almacenados son:\n\n");
        for (i = 0; i < sizeof(verbos) / sizeof(verbos[0]); i++)
            printf("--> %s\n", verbos[i]);
    }

    else if (resp == '1') {
        agregarVerbo(verbos, &numero, MAX_ELEMENTOS);
    }

    else printf("\n\nIngresa una opcion valida\n");
}

void mostrarSituacion() {
    int i, numero = 0;
    char resp;
    
    printf("\n\n [O]  ----> Mostrar situacion\n [1]  ----> Agregar situacion");
    printf("\n\nTu respuesta ---->  ");
    scanf(" %c", &resp);
    getchar();

    if (resp == '0') { 
        printf("\n\nLas situaciones que tengo almacenados son:\n\n");
        for (i = 0; i < sizeof(situacion) / sizeof(situacion[0]); i++)
            printf("--> %s\n", situacion[i]);
    }

    else if (resp == '1') {
        agregarSituacion(situacion, &numero, MAX_ELEMENTOS);
    }

    else printf("\n\nIngresa una opcion valida\n");
}

void discursoLoco(char* nombres[], int tamanoNombres, char* verbos[], int tamanoVerbos, char* situacion[], int tamanoSituacion) {
    int i, numero = 0;
    printf("\n\nIngresa cuantos discursos locos deseas generar ---->  ");
    scanf(" %d", &numero);
    getchar();
    printf("\n");

    for(i = 0; i < numero; i++) {
        printf("--->[%d] %s %s %s\n", i, nombres[rand() % tamanoNombres], verbos[rand() % tamanoVerbos], situacion[rand() % tamanoSituacion]);
        sleep(1); // Esperamos un segundo para generar la siguiente oracion y si sea aleatorio.
    }
    
}

void agregarNombre(char* nombres[], int* cantidadNombres, int tamanoMax) {
    char nuevoNombre[MAX_CARACTERES];

    printf("\nIngresa el nuevo nombre --> ");
    fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
    nuevoNombre[strcspn(nuevoNombre, "\n")] = '\0'; // Eliminamos el salto de línea

    if (*cantidadNombres < tamanoMax) {
        nombres[*cantidadNombres] = strdup(nuevoNombre);
        (*cantidadNombres)++;
        printf("\nSe ha agregado el nombre \"%s\"\n", nuevoNombre);
    } else {
        printf("No hay suficiente espacio para agregar un nuevo nombre :(\n");
    }
}

void agregarVerbo(char* verbos[], int* cantidadVerbos, int tamanoMax) {
    char nuevoVerbo[MAX_CARACTERES];

    printf("\nIngresa el nuevo verbo --> ");
    fgets(nuevoVerbo, sizeof(nuevoVerbo), stdin);
    nuevoVerbo[strcspn(nuevoVerbo, "\n")] = '\0'; // Eliminamos el salto de línea

    if (*cantidadVerbos < tamanoMax) {
        verbos[*cantidadVerbos] = strdup(nuevoVerbo);
        (*cantidadVerbos)++;
        printf("\nSe ha agregado el verbo \"%s\"\n", nuevoVerbo);
    } else {
        printf("No hay suficiente espacio para agregar un nuevo nombre :(\n");
    }
}

void agregarSituacion(char* situacion[], int* cantidadSituacion, int tamanoMax) {
    char nuevaSituacion[MAX_CARACTERES];

    printf("\nIngresa la nueva situacion --> ");
    fgets(nuevaSituacion, sizeof(nuevaSituacion), stdin);
    nuevaSituacion[strcspn(nuevaSituacion, "\n")] = '\0'; // Eliminamos el salto de línea

    if (*cantidadSituacion < tamanoMax) {
        situacion[*cantidadSituacion] = strdup(nuevaSituacion);
        (*cantidadSituacion)++;
        printf("\nSe ha agregado la nueva situacion \"%s\"\n", nuevaSituacion);
    } else {
        printf("No hay suficiente espacio para agregar un nuevo nombre :(\n");
    }
}
