
#define MAX_GUSTOS 3
#define MAX_AMIGOS 6


// Prototipos de funciones
void llamarPersonas(), imprimirGustos();
void imprimirAmigos(char gustos_mios[MAX_GUSTOS][50], int numMisGustos);
void ingresarGustosUsuario(char gustos[MAX_GUSTOS][50], int *numGustos);
int numAleatorio(int tamanoGustos);
int menu();
void imprimirGustosUsuario(char gustos_mios[MAX_GUSTOS][50], int numGustos);

struct Persona{
    char nombre[20];
    char gustos[MAX_GUSTOS][50];
    int numero_gustos;
} Personas[MAX_AMIGOS];

